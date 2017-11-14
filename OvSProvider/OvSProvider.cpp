#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <stdio.h>
#include <wchar.h>

#include "OvSProvider.h"
#include "log_api.h"

/*Pointer to wide buffer that receives the converted string*/
wchar_t* wString = NULL;

wchar_t *
char_to_lpcwstr(char *charArray)
{
	/*Size, in characters, of the wide buffer */
	int wsize = 0; 

	/*Get required wide buffer size, in characters.*/
	wsize = MultiByteToWideChar(CP_UTF8, 0, charArray, -1, NULL, 0);

	if (wsize == 0)
	{
		wprintf(L"Conversion error.\n");
		exit(wsize);
	}
	else
	{
		wString = new wchar_t[wsize];
		MultiByteToWideChar(CP_UTF8, 0, charArray, -1, wString, wsize);
	}

	return wString;
}

void 
userspace_err_log(char *log) 
{
	EventWriteUserspace_Error_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteUserspace_Error_Event.\n");
}

void
userspace_warn_log(char *log)
{
	EventWriteUserspace_Warning_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteUserspace_Warning_Event.\n");
}

void
userspace_info_log(char *log)
{
	EventWriteUserspace_Informational_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteUserspace_Informational_Event.\n");
}

void
userspace_dbg_log(char *log)
{
	EventWriteUserspace_Verbose_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteUserspace_Verbose_Event.\n");
}

void
userspace_emer_log(char *log)
{
	EventWriteUserspace_Critical_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteUserspace_Critical_Event.\n");
}


void
datapath_err_log(char *log)
{
	EventWriteDatapath_Error_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteDatapath_Error_Event.\n");
}

void
datapath_warn_log(char *log)
{
	EventWriteDatapath_Warning_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteDatapath_Warning_Event.\n");
}

void
datapath_info_log(char *log)
{
	EventWriteDatapath_Informational_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteDatapath_Informational_Event.\n");
}

void
datapath_dbg_log(char *log)
{
	EventWriteDatapath_Verbose_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteDatapath_Verbose_Event.\n");
}

void
datapath_emer_log(char *log)
{
	EventWriteDatapath_Critical_Event(char_to_lpcwstr(log));
	wprintf(L"Using Macro: EventWriteDatapath_Critical_Event.\n");
}

int 
main()
{
	ULONG status;

	/* Register the Userspace Provider. 
	If registration fails 
	then each of the successive event logging calls will fail. */
	
	status = ERROR_SUCCESS;
	status = EventRegisterLinux_Foundation_Open_vSwitch_Userspace();
	if (status != ERROR_SUCCESS) {
		wprintf(L"ERROR: " 
			"EventRegisterLinux_Foundation_Open_vSwitch_Userspace " 
			"Failed with Status code = %d\n", status);
		exit(status);
	}

	/* Register the Datapath Provider. 
	If registration fails 
	then each of the successive event logging calls will fail. */

	status = ERROR_SUCCESS;
	status = EventRegisterLinux_Foundation_Open_vSwitch_Datapath();
	if (status != ERROR_SUCCESS) {
		wprintf(L"ERROR: " 
			"EventRegisterLinux_Foundation_Open_vSwitch_Datapath " 
			"Failed with Status code = %d\n", status);
		exit(status);
	}

	/* Write NULL terminated unicode string under Userspace channel. */

	userspace_dbg_log("Dbg Msg");
	userspace_emer_log("Emer Msg");

	/* Write NULL terminated unicode string under Datapath channel. */

	datapath_info_log("Info Msg");
	datapath_err_log("Err Msg");


	/* Unregister Userspace provider if it was registered. */

	EventUnregisterLinux_Foundation_Open_vSwitch_Userspace();
	wprintf(L"Using Macro: " 
		"EventUnregisterLinux_Foundation_Open_vSwitch_Userspace.\n");

	/* Unregister Datapath provider if it was registered. */

	EventUnregisterLinux_Foundation_Open_vSwitch_Datapath();
	wprintf(L"Using Macro: " 
		"EventUnregisterLinux_Foundation_Open_vSwitch_Datapath.\n");

	delete wString;

	return status;
}