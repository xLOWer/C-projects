#include <iostream>
#include <tchar.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#include "additionals.h"

HDC hdc;
void my_func(){ //moving round
	TCHAR t[1024], t1[1024], t2[1024];
	double  x = 200,//(W_START_X + WIN_WIDTH)/2, //start position x
			y = 220,//(W_START_Y + WIN_HEIGHT) / 2, //start position y
			r = 30, //radius of circle
			s = 2, // speed
			ff = .0001, // friction force
			fi = 0, //DEGREES to RADIANS
			angle = 0, //angle relative 0 degrees
			xMin = 100, //top border
			yMin = 100,  // left border
			xMax = 800, // right border 
			yMax = 800; // bottom border
	while(1){
		Ellipse(hdc,x - r, y - r, x + r, y + r);
		MYLINE(xMax, yMin, xMax, yMax);
		MYLINE(xMin, yMin, xMax, yMin);
		MYLINE(xMin, yMin, xMin, yMax);
		MYLINE(x, y, x+sin(fi)*r*s, y+cos(fi)*r*s);
		MYpause(.001); 
			if(y - r <= yMin || y + r >= yMax){ angle = 360 - (angle + (ff * s) * 10)      ; s -= ff;}
			if(x - r <= xMin || x + r >= xMax){ angle = 360 - (angle + (ff * s) * 10) + 180; s -= ff;}
			if(angle > 360)angle-=360;
			fi = (angle + 90) * M_PI / 180;
			if(s < abs(ff)){ s = 0; } else { s -= ff; }
			x += sin(fi) * s - ff;
			y += cos(fi) * s - ff;
		Rectangle(hdc, W_START_X, W_START_Y, WIN_WIDTH, WIN_HEIGHT);  //clear screen
		MYPrintParams(1, 1, "x:", t, x);
		MYPrintParams(15, 1, "y:", t1, y); MYv_loadbar(xMin - 15, yMin, yMax - xMin, y - yMin, 0, yMax);
		MYPrintParams(30, 1, "a:", t2, angle); MYh_loadbar(70, 30, 700, s, 3);
	}
}
