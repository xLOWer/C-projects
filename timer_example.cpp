#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cmath>
LRESULT CALLBACK WindowProc (HWND, UINT, WPARAM, LPARAM);
HDC dc;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc     = {0};
	wc.style        = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc  = WindowProc;
	wc.hInstance    = hInstance;
	wc.hCursor      = LoadCursor (NULL, IDC_ARROW);
	wc.lpszClassName= "CMyWnd";
	RegisterClass (&wc);
	HWND hWnd = CreateWindow ("CMyWnd", "WinMain sample", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, 320, 240, NULL, NULL, hInstance, NULL);
	dc = GetDC (hWnd);
	ShowWindow (hWnd, nCmdShow);
	SetTimer (hWnd, 1, USER_TIMER_MINIMUM, NULL);
	MSG msg;
	while (GetMessage(&msg,NULL,0,0) > 0)
	{
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}
	return msg.wParam;
}
// Message processing function
LRESULT CALLBACK WindowProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static bool Move = true;
	static int Phase=0, Width, Height;
	switch (message)
	{
		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
			Move = !Move;
			// no break
		case WM_TIMER:
			if (Move)
			Phase++;
			// no break
			else
			break;
		case WM_PAINT:
			Rectangle (dc, -1, -1, Width+1, Height+1);
			MoveToEx (dc, 0, Height * (0.5 + 0.3*sin(0.1*Phase)), NULL);
			for (int i=0; i<Width; i++)
			LineTo (dc, i, Height * (0.5 + 0.3*sin(0.1*(i+Phase))) );
			break;
		case WM_SIZE:
			Width  = LOWORD(lParam),
			Height = HIWORD(lParam);
			break;
		case WM_KEYDOWN:
			if (wParam != VK_ESCAPE)
			break;
			// else no break
		case WM_DESTROY:
			PostQuitMessage (0);
	}
	return DefWindowProc (hWnd, message, wParam, lParam);
}
