#include <windows.h>
#include <math.h>
#include <iostream>
#include <ctime>

#define h 1000
#define w 1000

#define k 1000 
#define W_SIZE_H 900//window height
#define W_SIZE_W 1000//window width
#define W_START_X 0//window start position x
#define W_START_Y 0//window start position y

void pause(double c){for(double i=0;i<=1000;i+=c){}}

HDC hdc;
void my_func();
void PIXEL(int, int, int);
struct point{
double x, y, r;
int xx(){return (int)x;}
int yy(){return (int)y;}
int rr(){return (int)r;}
};
void SQUARE(point p){
	Rectangle(hdc, p.xx() - p.rr(), p.yy() - p.rr(), p.xx() + p.rr(), p.yy() + p.rr());
}
void SQUARE(int x, int y, int s){
	Rectangle(hdc, x, y, x + s, y + s);
}
int DRAWW(point p, int dir, int iter) { 
		SQUARE(p.x - p.r, p.y - p.r, 2 * p.r);
		if (iter == 0) {return 0;}
		point o[4];
		int d = 3 * p.r / 2;
		o[0].x = p.x - d;
		o[0].y = p.y;
		o[1].x = p.x;
		o[1].y = p.y - d;
		o[2].x = p.x + d;
		o[2].y = p.y;
		o[3].x = p.x;
		o[3].y = p.y + d;
		for (int i = 0; i < 4; i++) {
			if (i - dir == 2 || i - dir == -2)continue; o[i].r = (p.r / 2); DRAWW(o[i], i, iter - 1);
			}
		return 0;
	}

//***********************************************************************
void my_func(){ //not crosser rounds
	point p[k]; int m = 60, d = 0, mm = m/2, l = ((k * k) / (M_PI * m * m))*2.12;
	char text[] = "1";
	std::cout << l;
	for(int i = 0; i <= l; ++i)
	{
	mt:
		p[i].x = mm + rand()%(k - mm);
		p[i].y = mm + rand()%(k - mm);
		d = 0;
		for(int j = 0; j < i; ++j)
		{
			if((sqrt(((p[i].x - p[j].x) * (p[i].x - p[j].x)) + ((p[i].y - p[j].y) * (p[i].y - p[j].y)))) < m )
			{
				d++;
			} 
		}
		if(d != 0) 
		{
			goto mt;
		}
		else
		{
			Ellipse(hdc, p[i].x - mm, p[i].y - mm, p[i].x + mm, p[i].y + mm); //S = pi * m^2
			PIXEL(p[i].x, p[i].y,2);
		}
	}
}
void my_func1(){ //moving round
	double x = 300, 
			y = 150, 
			r = 20, 
			fi = 0, 
			angle = 35, 
			xMin = W_START_X, 
			yMin = W_START_Y, 
			xMax = W_START_X + W_SIZE_W, 
			yMax = W_START_Y + W_SIZE_H;
	while(1){
		Ellipse(hdc,x - r, y - r, x + r, y + r);
		pause(.0005); 
		if(y - r <= yMin || y + r >= yMax){ angle = 360 - angle; }
		if(x - r <= xMin || x + r >= xMax){ angle = 360 - angle + 180; }
		fi = (angle + 90) * M_PI / 180;
		x += sin(fi);
		y += cos(fi);
		Rectangle(hdc, W_START_X, W_START_Y, W_SIZE_W, W_SIZE_H); 
	}
}
void my_func2(){//labirint
	signed short int m[h][w], p=8;
	//signed short int m[255][2];
	//bool k = false;
	srand(time(NULL));
	for(int i = 0; i < h/2; i+=p*2){
		for(int j = 0; j < w/2; j+=p*2){
			m[i][j] = rand()%2;
			if(m[i][j] == 0){
				PIXEL(i, j + p, p); PIXEL(i + p, j + p, p);
			}
			else{
				PIXEL(i + p, j, p); PIXEL(i + p, j + p, p);
			}
		}
	}
}
//***********************************************************************

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT pt;
	//double R, r = 200, fi = 0, dx = 350, dy = 225, angle = .5;
	point pos;
	pos.x = 400; pos.y = pos.x; pos.r = 400;
	switch(Message) {
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		case WM_PAINT: {
			hdc = BeginPaint(hwnd, &pt);
			my_func1();		//---------------------------
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
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */
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
