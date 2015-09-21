#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

int main(void){
	float a = 1, 
		  b = 65, 
		  c = 54;
	
	if(((b * b) - 4 * a * c) > 0)
	{
		printf("x1 = %lf\nx2 = %lf", (-b + sqrt((b * b) - 4 * a * c)) / (2 * a), (-b - sqrt((b * b) - 4 * a * c)) / (2 * a));
	}
	else if(((b * b) - 4 * a * c) == 0)
	{
		printf("x1 = %lf", -(b / 2 * a));
	}
	else 
	{
		printf("complex roots!");
	}
}
