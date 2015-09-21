#include <windows.h>
#include <math.h>
#include <iostream>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

#define W_SIZE_H 900//window height
#define W_SIZE_W 1000//window width
#define W_START_X 0//window start position x
#define W_START_Y 0//window start position y

void pause(double c){for(double i=0;i<=1000;i+=c){}}

HDC hdc;

void PIXEL(int, int, int);
struct point{
	double x, y, r;
	int xx(){return (int)x;}
	int yy(){return (int)y;}
	int rr(){return (int)r;}
};
void SQUARE(point);
void SQUARE(int, int, int);
void LINE(int, int, int, int);
class BALL{
	public: void param_set(double _x, double _y, double _radius, double _speed, double _friction, double _fi, double _angle, double _xMin, double _yMin, double _xMax, double _yMax){
		x = _x; y = _y; radius = _radius; speed = _speed; friction = _friction; fi = _fi; angle = _angle; xMin = _xMin; yMin = _yMin; xMax = _xMax; yMax = _yMax;
		}
	TCHAR text_buffer[32];
	double  x,//(W_START_X + W_SIZE_W)/2, //start position x
			y,//(W_START_Y + W_SIZE_H) / 2, //start position y
			radius, //radius of circle
			speed, // speed
			friction, // friction force
			fi, //DEGREES to RADIANS
			angle,//rand()%360, //angle relative 0 degrees
			xMin, //top border
			yMin,  // left border
			xMax, // right border 
			yMax; // bottom border
			
	void h_loadbar(int x, int y, int size, double n, double sec/*, double max*/){
		int c = 4;
		for(int i = 0; i <= sec*(size / sec); i += (size / sec))
		{
			LINE(x + i, y + (size / 40/c), x + i, y + (size / 10 / c));
		}
		LINE(x, y + (size / 20 / c), x + ((size / sec) * n), y + (size / 20 / c));
	}
	void v_loadbar(int x, int y, int size, double n, double sec, double max){
		int c = 4;
		for(int i = 0; i <= sec*(size / sec); i += (max / sec))
		{
			LINE(x + 5, y + i, x - 5, y + i);
		}
		LINE(x + (size / 20 / c), y, x + (size / 20 / c), y + ((size / max) * n));
	}
	void move(){
		Ellipse(hdc,x - radius, y - radius, x + radius, y + radius);//main ball
		draw_borders();
		LINE(x, y, x + sin(fi) * radius * speed, y + cos(fi) * radius * speed);//speed vector
		pause(.001); //pause between draws
		param_calculate();
		Rectangle(hdc, W_START_X, W_START_Y, W_SIZE_W, W_SIZE_H);  //clear screen
	}
	
	void draw_borders(){
		LINE(xMax, yMin, xMax, yMax);//right line
		LINE(xMin, yMin, xMax, yMin);//top line
		LINE(xMin, yMin, xMin, yMax);//left line
		LINE(xMin, yMax, xMax, yMax);//bot line
	}
	void param_calculate(){
		if(y - radius <= yMin || y + radius >= yMax){
			angle = 360 - (angle + (friction * speed) * 10); 
			speed -= friction;
		}
		if(x - radius <= xMin || x + radius >= xMax){
			angle = 180 - (angle + (friction * speed) * 10); 
			speed -= friction;
		}
		if(angle > 360) angle-=360;
		fi = (angle + 90) * M_PI / 180;
		if(speed < abs(friction)){ speed = 0; } else { speed -= friction; }
		x += sin(fi) * speed - friction;
		y += cos(fi) * speed - friction;
	}
	void PrintParams(int x, int y, TCHAR str[], TCHAR str2[], double a){
		gcvt(a, 4, str2);
		TextOut(hdc, y, x, _T(str), _tcslen(str));
		TextOut(hdc, y + 15, x, str2, _tcslen(str2));
	}
};
//***********************************************************************

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	BALL ball;
	srand((unsigned int)time(NULL));
	switch(Message) {
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		case WM_PAINT: {
			hdc = BeginPaint(hwnd, &pt);
			ball.param_set(
					200,//(W_START_X + W_SIZE_W)/2, //start position x
					220,//(W_START_Y + W_SIZE_H) / 2, //start position y
					30, //radius of circle
					2, // speed
					.001, // friction force
					0, //DEGREES to RADIANS
					0,//angle relative 0 degrees
					100, //top border
					100,  // left border
					800, // right border 
					800 // bottom border
			);
			while(ball.speed > 0){
				ball.move();
				ball.PrintParams(1, 1, "x:", ball.text_buffer, ball.x);
				ball.PrintParams(15, 1, "y:", ball.text_buffer, ball.y);
				ball.PrintParams(30, 1, "s:", ball.text_buffer, ball.speed); 
				ball.h_loadbar(70, 30, 700, ball.speed, 3);
			}
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
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,W_START_X,W_START_Y, W_SIZE_W,W_SIZE_H,NULL,NULL,hInstance,NULL);
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


void LINE(int x0, int y0, int x1, int y1){
	MoveToEx(hdc, x0, y0, NULL);
	LineTo(hdc, x1, y1);
}

void SQUARE(int x, int y, int s){
	Rectangle(hdc, x, y, x + s, y + s);
}
void SQUARE(point p){
	Rectangle(hdc, p.xx() - p.rr(), p.yy() - p.rr(), p.xx() + p.rr(), p.yy() + p.rr());
}
void PIXEL(int x, int y){
	MoveToEx(hdc, x-1, y-1, NULL);
	LineTo(hdc, x, y);
  }
void PIXEL(int x, int y, int s){
	for(int i = 0; i <= s; ++i){
		for(int j = 0; j <= s; ++j){
			MoveToEx(hdc, x-1+i, y-1+j, NULL);
			LineTo(hdc, x+i, y+j); 
		}
	}
}
