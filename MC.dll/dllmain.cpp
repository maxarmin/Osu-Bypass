
#include "common.h"
#include <Objbase.h>


int init()
{
	ConsoleInit();
	InstallHooks();
	return 1;
}


void dispose()
{
	ConsoleDispose();
	UninstallHooks();
}



BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)init, hModule, NULL, NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		dispose();
		break;
	}
	return TRUE;
}