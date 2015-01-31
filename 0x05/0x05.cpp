#include "resource.h"

#include <Windows.h>
#include <WindowsX.h>

#pragma comment(lib, "winmm.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprevinstance, LPSTR lpcmdline, INT ncmdshow){
	int ret = MessageBoxA(NULL, "请选择", "Play Sound", MB_YESNO | MB_ICONQUESTION);

	if(ret == IDYES){
		PlaySound(MAKEINTRESOURCE(ID_MUSIC), hInstance,
			SND_SYNC | SND_RESOURCE); 
	}else{
		PlaySound(TEXT("QQQG"), hInstance, SND_ASYNC | SND_LOOP | SND_RESOURCE);
	}

	MessageBoxA(NULL, "终止", "Play Sound", MB_OK | MB_ICONSTOP);

	return 0;
}