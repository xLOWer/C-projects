#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <tchar.h>

#define WIN_HEIGHT 900 //window height
#define WIN_WIDTH 1000 //window width
#define W_START_X 0 //window start position x
#define W_START_Y 0 //window start position y

#include "snake.h"

HDC hdc;
//***********************************************************************
void MYpause(double milliseconds){for(double i=0;i<=1000;i+= 0.01 / milliseconds / 0.895){}}

void MYPIXEL(int x, int y, int s){
	for(int i = 0; i <= s; ++i){
		for(int j = 0; j <= s; ++j){
			MoveToEx(hdc, x-1+i, y-1+j, NULL);
			LineTo(hdc, x+i, y+j); 
		}
	}
}
//***********************************************************************

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	//srand((unsigned int)time(NULL));
	switch(Message) {
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		case WM_PAINT: {
			hdc = BeginPaint(hwnd, &pt);
			//***********************
				SnakeGame sn;
				sn.pos.setY(10);
				std::cout << sn.pos.getY();
			//***********************
			EndPaint(hwnd, &pt);
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* Use the name "A" to use the project icon */
	VirtualAllocEx(hwnd, NULL, 1024 * 1024 * 1024, MEM_COMMIT, PAGE_READWRITE); /* Reserve memory for our programm */
	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,W_START_X,W_START_Y, WIN_WIDTH,WIN_HEIGHT,NULL,NULL,hInstance,NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}

