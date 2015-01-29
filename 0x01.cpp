#include <Windows.h>
#include <WindowsX.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprevinstance, LPSTR lpcmdline, INT ncmdshow){
	MessageBoxA(NULL, "Hello World", "First Program", MB_OK | MB_ICONEXCLAMATION);

	return 0;
}