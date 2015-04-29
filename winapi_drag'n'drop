#define _TIMER_TICK 1
#include "additionals.h"

	int x, y, sX, sY;
	bool inn = false, clk = false;
	MYpoint p;
//***********************************************************************
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	MYSQUARE(p);
	switch(Message) {
		case WM_KEYDOWN: {
			switch (wParam)
			{
				case VK_SPACE: inn=!inn; break;
				case VK_UP:; break;
				default: break;
 			}
 			break;
 		}
 		case WM_LBUTTONDOWN:
			{
				clk = true;
				//if(sX >= 0 && sX <= p.r && sY >= 0 & sY <= p.r){
			 		inn = true;
	 			//}else inn = false;
			}
		case WM_MOUSEMOVE:
			{
				x = LOWORD(lParam);
			 	y = HIWORD(lParam);
			 	sX = x - p.x;
				sY = y - p.y;
				p.x = x - sX;
			 	p.y = y - sY;
				system("cls");
	 			std::cout << "x: " << x << "\n";
	 			std::cout << "y: " << y << "\n";
	 			std::cout << "sx: " << sX << "\n";
	 			std::cout << "sy: " << sY << "\n";
	 			std::cout << "click: " << clk << "\n";
	 			std::cout << "click in: " << inn << "\n";
	 			if(sX >= 0 && sX <= p.r && sY >= 0 & sY <= p.r){
			 		std::cout << "in?: 1" << "\n";
	 			}else std::cout << "in?: 0" << "\n";
	 			
	 			if(inn && clk){
					p.x = x - sX;
			 		p.y = y - sY;
		 			MYSQUARE(0,0,999);
					MYSQUARE(p);
					inn = false;
				}
			}
		case WM_PAINT:
			{
				break;
			}
		case WM_LBUTTONUP:
			{
				clk = false;
				inn = false;
	 			break;
			}
			
		case WM_DESTROY: 
			PostQuitMessage(0);
			break;
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
