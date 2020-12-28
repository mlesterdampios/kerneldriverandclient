#pragma once
#pragma warning( disable : 4099 )

#include <ntdef.h>
#include <ntifs.h>

#include <ntifs.h>
#include <ntddk.h>
#include <windef.h>
#include <wdf.h>
#include <ntdef.h>
#include <ntimage.h>
#include <ntifs.h>
#include <intrin.h>


#include <ntdef.h>
#include <ntifs.h>
#include <ntifs.h>
#include <ntddk.h>
#include <windef.h>
#include <wdf.h>
#include <ntdef.h>

#include <ntimage.h>
#include <ntifs.h>
#include <intrin.h>

#include "Utils.h"


//DRIVER_INITIALIZE DriverInitialize;
//extern "C" DRIVER_INITIALIZE DriverEntry;
//#pragma alloc_text(INIT, DriverEntry)


#define IOCTL_DISK_BASE                 FILE_DEVICE_DISK
#define IOCTL_DISK_GET_DRIVE_GEOMETRY   CTL_CODE(IOCTL_DISK_BASE, 0x0000, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define READ_PROCESS_MEMORY_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2331, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define WRITE_PROCESS_MEMORY_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2332, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define GET_PROCESS_BASE_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2333, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define GET_PROCESS_PEB_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2334, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define VIRTUAL_QUERY_EX_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2336, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define WRITE_PROTECTED_VIRTUAL_MEMORY_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2337, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define VIRTUAL_PROTECT_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2338, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
///////////////////////////////////////////
//ROAD TO BSOD. HAHAHA
///////////////////////////////////////////
//#define FIND_PATTERN_PROCESS_MEMORY_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN, 0x2335, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

struct CUSTOM_IOCTL_CALL
{
	ULONG64 Filter;
	ULONG ControlCode;

};

struct READ_PROCESS_MEMORY : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	unsigned __int64 ProcessAddress;
	unsigned __int64 Length;
	unsigned __int64 OutBuffer;
};

///////////////////////////////////////////
//ROAD TO BSOD. HAHAHA
///////////////////////////////////////////
/*
struct FIND_PATTERN_PROCESS_MEMORY : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	unsigned __int64 StartAddress;
	unsigned __int64 EndAddress;
	char* Pattern;
	char* Mask;
	unsigned __int64 OutBuffer;
};
*/

struct VIRTUAL_QUERY_EX : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	PVOID BaseAddress;
	MEMORY_BASIC_INFORMATION mbi;
	SIZE_T size;
};

struct VIRTUAL_PROTECT : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	PVOID Address;
	DWORD protection;
	SIZE_T size;
};

struct WRITE_PROCESS_MEMORY : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	unsigned __int64 ProcessAddress;
	unsigned __int64 Length;
	unsigned __int64 InBuffer;
};

struct WRITE_PROTECTED_VIRTUAL_MEMORY : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	UINT64 Address; // Target
	PVOID Value; // Source
	SIZE_T Size;
};

struct GET_PROCESS_BASE : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	unsigned __int64 ProcessBaseAddres;
};

struct GET_PROCESS_PEB : CUSTOM_IOCTL_CALL
{
	unsigned __int64 ProcessId;
	unsigned __int64 ProcessBaseAddres;
};

#define Printf(...) DbgPrintEx( DPFLTR_SYSTEM_ID, DPFLTR_ERROR_LEVEL, "[zDriver] " __VA_ARGS__ )
