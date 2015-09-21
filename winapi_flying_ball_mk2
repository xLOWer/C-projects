#include <windows.h>
#include <iostream>

#define _TIMER_TICK 1

#include "flying_ball_class.h"

BALL bl[5];
bool move = true;

void redraw(int i){
		bl[i].clear_ball();
		bl[i].calculate();	
		bl[i].draw_ball();
		//bl[i].draw_speedline();
		bl[i].setParams();
}
//***********************************************************************
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	
	switch(Message) {
		case WM_KEYDOWN: {
			switch (wParam)
			{
				case VK_SPACE: move = !move; break;
				case VK_UP: bl[4].angle += 5; break;
				case VK_DOWN: bl[4].angle -= 5; break;
				default: break;
 			}
 		}
		case WM_TIMER:
			if(move){
				for(int i = 0; i < 5; ++i){ GetClientRect(hwnd, &bl[i].rect); }	
			}
			else break;
		case WM_PAINT: {
			for(int i = 0; i < 5; ++i){ redraw(i); }
			break;
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
	}
	return DefWindowProc(hwnd, Message, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASS wc     = {0};
	wc.style        = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc  = WndProc;
	wc.hInstance    = hInstance;
	wc.hCursor      = LoadCursor (NULL, IDC_ARROW);
	wc.lpszClassName= "CMyWnd";
	RegisterClass (&wc);
	HWND hwnd = CreateWindow ("CMyWnd", "WinMain sample", WS_OVERLAPPEDWINDOW, W_START_X, W_START_Y, WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);
	_hdc = GetDC (hwnd);
	ShowWindow (hwnd, nCmdShow);
	SetTimer (hwnd, 1, _TIMER_TICK, NULL);
	MSG msg;
	while (GetMessage(&msg,NULL,0,0) > 0){
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}
	return msg.wParam;
}
