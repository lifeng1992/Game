// A complete simple windows program
#include <Windows.h>
#include <WindowsX.h>

void CreateWindowsClass(WNDCLASSEX *pwinclass, HINSTANCE hInstance);

// 2.创建WinProc
LRESULT CALLBACK WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprevinstance, LPSTR lpCmdline, INT nCmdshow){
	WNDCLASSEX	winclass;
	HWND		hwnd;
	MSG			msg;

	// 1.创建一个Windows类
	CreateWindowsClass(&winclass, hInstance);
	// 3.注册Windows类
	if(!RegisterClassEx(&winclass)){
		return 0;
	}
	// 4.创建窗口
	hwnd = CreateWindowEx(NULL, TEXT("winclass_0x01"), TEXT("Simple Example"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 860, 480, NULL, NULL, hInstance, NULL);
	if(!hwnd){
		return 0;
	}

	while(GetMessage(&msg, NULL, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

void CreateWindowsClass(WNDCLASSEX *pwinclass, HINSTANCE hInstance){
	pwinclass->cbSize			= sizeof(WNDCLASSEX);
	pwinclass->style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;
	pwinclass->lpfnWndProc		= WinProc;
	pwinclass->cbClsExtra		= 0;
	pwinclass->cbWndExtra		= 0;
	pwinclass->hInstance		= hInstance;
	pwinclass->hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	pwinclass->hCursor			= LoadCursor(NULL, IDC_ARROW);
	pwinclass->hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	pwinclass->lpszMenuName		= NULL;
	pwinclass->lpszClassName	= TEXT("WinClass_0x01");
	pwinclass->hIconSm			= LoadIcon(NULL, IDI_APPLICATION);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam){
	PAINTSTRUCT ps;
	HDC			hdc;

	switch(Msg){
		case WM_CREATE:{
			return 0;
			break;
		}

		case WM_PAINT:{
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
			break;
		}

		case WM_DESTROY:{
			PostQuitMessage(0);
			return 0;
			break;
		}

		default:break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);			  
}