#pragma once

#include <Windows.h>
#include <stdio.h>

/*-----[SETTING UP MACROS]-----*/
#define STATUS_SUCCESS ((NTSTATUS)0x00000000L)
#define warn(msg, ...) printf("[-] " msg "\n", ##__VA_ARGS__)
#define info(msg, ...) printf("[i] " msg "\n", ##__VA_ARGS__)
#define okay(msg, ...) printf("[+] " msg "\n", ##__VA_ARGS__)


/*-----[STRUCTURES]------*/

typedef NTSTATUS(NTAPI* myNtTestAlert)();

typedef struct _OBJECT_ATTRIBUTES
{
	ULONG Length;                                                           //0x0
	VOID* RootDirectory;                                                    //0x8
	struct _UNICODE_STRING* ObjectName;                                     //0x10
	ULONG Attributes;                                                       //0x18
	VOID* SecurityDescriptor;                                               //0x20
	VOID* SecurityQualityOfService;                                         //0x28
} OBJECT_ATTRIBUTES, * POBJECT_ATTRIBUTES;

#ifndef InitializeObjectAttributes
#define InitializeObjectAttributes( p, n, a, r, s ) { \
	(p)->Length = sizeof( OBJECT_ATTRIBUTES );        \
	(p)->RootDirectory = r;                           \
	(p)->Attributes = a;                              \
	(p)->ObjectName = n;                              \
	(p)->SecurityDescriptor = s;                      \
	(p)->SecurityQualityOfService = NULL;             \
};
#endif

typedef struct _PS_ATTRIBUTE {
	ULONGLONG Attribute;				/// PROC_THREAD_ATTRIBUTE_XXX | PROC_THREAD_ATTRIBUTE_XXX modifiers, see ProcThreadAttributeValue macro and Windows Internals 6 (372)
	SIZE_T Size;						/// Size of Value or *ValuePtr
	union {
		ULONG_PTR Value;				/// Reserve 8 bytes for data (such as a Handle or a data pointer)
		PVOID ValuePtr;					/// data pointer
	};
	PSIZE_T ReturnLength;				/// Either 0 or specifies size of data returned to caller via "ValuePtr"
} PS_ATTRIBUTE, * PPS_ATTRIBUTE;

typedef struct _CLIENT_ID {
	PVOID UniqueProcess;
	PVOID UniqueThread;
} CLIENT_ID, * PCLIENT_ID;

typedef struct _PS_ATTRIBUTE_LIST {
	SIZE_T TotalLength;					/// sizeof(PS_ATTRIBUTE_LIST)
	PS_ATTRIBUTE Attributes[2];			/// Depends on how many attribute entries should be supplied to NtCreateUserProcess
} PS_ATTRIBUTE_LIST, * PPS_ATTRIBUTE_LIST;

/*-----[FUNCTIONS]-----*/
extern NTSTATUS NtAllocateVirtualMemory(
	IN HANDLE ProcessHandle,
	IN OUT PVOID* BaseAddress,
	IN ULONG ZeroBits,
	IN OUT PSIZE_T RegionSize,
	IN ULONG AllocationType,
	IN ULONG Protect);

extern NTSTATUS NtProtectVirtualMemory(
	_In_ HANDLE ProcessHandle,
	_Inout_ PVOID* BaseAddress,
	_Inout_ PSIZE_T RegionSize,
	_In_ ULONG NewProtect,
	_Out_ PULONG OldProtect
);

extern NTSTATUS NtOpenProcess(
	OUT PHANDLE ProcessHandle,
	IN ACCESS_MASK DesiredAccess,
	IN POBJECT_ATTRIBUTES ObjectAttributes,
	IN PCLIENT_ID ClientId OPTIONAL);

extern NTSTATUS NtCreateThreadEx(

	_Out_ PHANDLE ThreadHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_opt_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ HANDLE ProcessHandle,
	_In_ PVOID StartRoutine, // PUSER_THREAD_START_ROUTINE
	_In_opt_ PVOID Argument,
	_In_ ULONG CreateFlags, // THREAD_CREATE_FLAGS_*
	_In_ SIZE_T ZeroBits,
	_In_ SIZE_T StackSize,
	_In_ SIZE_T MaximumStackSize,
	_In_opt_ PPS_ATTRIBUTE_LIST AttributeList
);

extern NTSTATUS NtWriteVirtualMemory(
	IN HANDLE ProcessHandle,
	IN PVOID BaseAddress,
	IN PVOID Buffer,
	IN SIZE_T NumberOfBytesToWrite,
	OUT PSIZE_T NumberOfBytesWritten OPTIONAL);

extern NTSTATUS NtWaitForSingleObject(
	_In_ HANDLE Handle,
	_In_ BOOLEAN Alertable,
	_In_opt_ PLARGE_INTEGER Timeout);

extern NTSTATUS NtClose(
	IN HANDLE Handle);
