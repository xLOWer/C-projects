#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <stdlib.h>
#include <math.h>

#define WIN_HEIGHT 900 //window height
#define WIN_WIDTH 1000 //window width
#define W_START_X 0 //window start position x
#define W_START_Y 0 //window start position y

HDC _hdc;

void MYpause(double milliseconds){for(double i=0;i<=1000;i+= 0.01 / milliseconds / 0.895){}}

struct MYpoint{
	double x, y, r;
	int xx(){return (int)x;}
	int yy(){return (int)y;}
	int rr(){return (int)r;}
};

void MYLINE(int x0, int y0, int x1, int y1){
	MoveToEx(_hdc, x0, y0, NULL);
	LineTo(_hdc, x1, y1);
}


void MYPrintParams(int x, int y, TCHAR str[], TCHAR str2[], double a){
	gcvt(a, 4, str2);
	TextOut(_hdc, y, x, _T(str), _tcslen(str));
	TextOut(_hdc, y + 15, x, str2, _tcslen(str2));
}
void MYSQUARE(int x, int y, int s){
	Rectangle(_hdc, x, y, x + s, y + s);
}
void MYSQUARE(MYpoint p){
	Rectangle(_hdc, p.xx() - p.rr(), p.yy() - p.rr(), p.xx() + p.rr(), p.yy() + p.rr());
}
void MYPIXEL(int x, int y){
	MoveToEx(_hdc, x-1, y-1, NULL);
	LineTo(_hdc, x, y);
  }
void MYPIXEL(int x, int y, int s){
	for(int i = 0; i <= s; ++i){
		for(int j = 0; j <= s; ++j){
			MoveToEx(_hdc, x-1+i, y-1+j, NULL);
			LineTo(_hdc, x+i, y+j); 
		}
	}
}

void MYh_loadbar(int x, int y, int size, double n, double sec){
	int c = 4;
	for(int i = 0; i <= sec*(size / sec); i += (size / sec))
	{
		MYLINE(x + i, y + (size / 40/c), x + i, y + (size / 10 / c));
	}
	MYLINE(x, y + (size / 20 / c), x + ((size / sec) * n), y + (size / 20 / c));
}

void MYv_loadbar(int x, int y, int size, double n, double sec, double max){
	int c = 4;
	for(int i = 0; i <= sec*(size / sec); i += (max / sec))
	{
		MYLINE(x + 5, y + i, x - 5, y + i);
	}
	MYLINE(x + (size / 20 / c), y, x + (size / 20 / c), y + ((size / max) * n));
}

