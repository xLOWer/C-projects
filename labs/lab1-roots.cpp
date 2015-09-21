#include <iostream>
#include <math.h>

int main(void){
	float a = 1, //a
		  b = 65, //b
		  c = 54;//c
	
	if(((b * b) - 4 * a * c) > 0)//if D > 0 y=f(x) have 2 roots
	{
		printf("x1 = %lf\nx2 = %lf", (-b + sqrt((b * b) - 4 * a * c)) / (2 * a), (-b - sqrt((b * b) - 4 * a * c)) / (2 * a));
	}
	else if(((b * b) - 4 * a * c) == 0)// if D is NU11, y=f(x) have single root
	{
		printf("x1 = %lf", -(b / 2 * a));
	}
	else //if D<0 function have more than one complex root
	{
		printf("complex roots!");
	}
}
