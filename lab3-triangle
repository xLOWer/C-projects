#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "lab3-triangle-1.h" 

int main(void) {
	char s[2];
	__TRIANG tri;
	
	printf("Input a: "); gets(s); 
	tri.a = atof(s);
	
	printf("Input b: "); gets(s); 
	tri.b = atof(s);
	
	printf("Input c: "); gets(s); 
	tri.c = atof(s);
	
	if (tri.__triangle() == true)
	{
		printf("Perimeter = %lf\nSquare = %lf", tri._perimeter(), tri._square());
	}
	else
	{
		printf("It is not triangle!");
	}
}
