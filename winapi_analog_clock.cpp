#include <windows.h>
#include <iostream>
#include <ctime>
#include <math.h>

#define WIN_HEIGHT 900 //window height
#define WIN_WIDTH 1000 //window width
#define W_START_X 0 //window start position x
#define W_START_Y 0 //window start position y
#define _TIMER_TICK 200

//#include "additionals.h"
HDC _hdc;
void MYLINE(int x0, int y0, int x1, int y1){
	MoveToEx(_hdc, x0, y0, NULL);
	LineTo(_hdc, x1, y1);
}
//***********************************************************************
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	RECT rect;

	float fi, fi_sec, fi_min, fi_hour;
	double sec_k = 1.17, min_k = 1.4, hour_k = 2.2, r;
	int Width, Height, x, y, _sec, _min, _hour, n = 49;
	time_t t;
	struct tm *t_m;
	bool flag_paint_dial = true, flag_move = true;
	
	switch(Message) {
		case WM_TIMER:
			if(flag_move){
				t = time(NULL);
				t_m = localtime(&t);	
				_sec = t_m->tm_sec; 
				_min = t_m->tm_min;
				_hour = t_m->tm_hour;
				if(_hour > 12)_hour -= 12;
				fi_sec = ((_sec * 6) - 180) * M_PI / -180;
				fi_min = (((_min * 6) + (_sec / 10)) - 180) * M_PI / -180;
				fi_hour = (((_hour * 30) + (_min / 2)) - 180) * M_PI / -180;
			}
			else break;
		case WM_PAINT: {
			GetClientRect(hwnd, &rect);
			Width  = rect.right;
			Height = rect.bottom;
			if(Height < Width){ r = Height;}else{r = Width;}
			r/=2;x = r; y = x;
			Rectangle (_hdc, -1, -1, Width + 1, Height + 1);//clear
			
			if(flag_paint_dial){
				for(unsigned short i = 0; i < 360; i += 6){
					fi = (90 + i) * M_PI / 180;
					MYLINE(x + sin(fi * 5) * r / 1.15, y + cos(fi * 5) * r / 1.15, 
							x + sin(fi * 5) * r / 1.05, y + cos(fi * 5) * r / 1.05);
							
					MYLINE(x + sin(fi) * r / 1.08, y + cos(fi) * r / 1.08, 
							x + sin(fi) * r / 1.03, y + cos(fi) * r / 1.03);
				}
				flag_paint_dial = false;
			}
			MYLINE(x, y, (r / sec_k) * sin(fi_sec) + x, (r / sec_k) * cos(fi_sec) + y);//(радиус / коэффициент длинны) * функцию( [x || y] ) + [x || y]
			MYLINE(x, y, (r / min_k) * sin(fi_min) + x, (r / min_k) * cos(fi_min) + y);
			MYLINE(x, y, (r / hour_k) * sin(fi_hour) + x, (r / hour_k) * cos(fi_hour) + y);
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
