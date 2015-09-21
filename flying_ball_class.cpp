//#include <iostream>
//#include <tchar.h>
#include <stdlib.h>
//#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#include "additionals.h"

class BALL{
	public: double  x, y, radius, speed, ff, fi, angle;
	public: RECT rect; //winow start\end coordinates
	public: BALL(){
		srand((unsigned int)time(NULL));
		radius = 5; //radius of circle
		x = radius + (rand()%WIN_WIDTH - radius); //start position x
		y = radius + (rand()%WIN_HEIGHT - radius); //start position y
		speed = 6; // speed
		ff = .0001; // friction force
		fi = 0; //DEGREES to RADIANS
		angle = 1+rand()%360; //angle relative 0 degrees
}
	public: void draw_ball(){
		Ellipse(_hdc, x - radius, y - radius, x + radius, y + radius);
	}
	
	public: void clear_ball(){
		Rectangle(_hdc, rect.left, rect.top, rect.right, rect.bottom);//clear screen
	}
	
	public: void draw_speedline(){
		MYLINE(x, y, x + sin(fi) * radius * speed, y + cos(fi) * radius * speed);	
	}
	
	public: void draw_borders(){
		MYLINE(rect.right, rect.top, rect.right, rect.bottom);
		MYLINE(rect.left, rect.top, rect.right, rect.top);	
		MYLINE(rect.left, rect.top, rect.left, rect.bottom);
		MYLINE(rect.left, rect.bottom, rect.right, rect.bottom);
	}
	public: void calculate(){
		if(y + radius >= rect.bottom || y - radius <= rect.top){ angle = 360 - (angle + (ff * speed) * 10)      ; speed -= ff;}
		if(x + radius >= rect.right || x - radius <= rect.left){ angle = 360 - (angle + (ff * speed) * 10) + 180; speed -= ff;}
		while(angle>360){angle -= 360;}
		fi = (angle + 90) * M_PI / 180;
		if(speed < abs(ff)){ speed = 0; } else { speed -= ff; }
	}
	
	public: void setParams(){
		x += sin(fi) * speed - ff;
		y += cos(fi) * speed - ff;
	}

		/*
		MYPrintParams(1, 1, "x:", t, x);
		MYPrintParams(15, 1, "y:", t1, y); 
		MYv_loadbar(xMin - 15, yMin, yMax - xMin, y - yMin, 0, yMax);
		MYPrintParams(30, 1, "a:", t2, angle); 
		MYh_loadbar(70, 30, 700, s, 3);
		*/
};
