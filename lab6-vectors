#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "windows.h"


class vector{
	public : 
	double a, b, c;
	
	vector(){ // constructor
		a = 0;
		b = 0;
		c = 0;
	}
	
	vector operator+(vector op2){
		vector v;
		v.a = a + op2.a;
		v.b = b + op2.b;
		v.c = c + op2.c;
		return v;
	}
	vector operator*(vector op2){
		vector v;
		v.a = b * op2.c - c * op2.b;
		v.b = a * op2.c - c * op2.a;
		v.c = a * op2.b - b * op2.a;
		return v;
	}
	char* output(){
		char* s;
		s = (char*)malloc(80);
		sprintf(s, "{%lf; %lf; %lf}", a, b, c);
		return s;
	}
};

int main(void){
	vector v1, v2;
	
	printf("vector1 x y z = \n");
	scanf("%lf %lf %lf", &v1.a, &v1.b, &v1.c);
	
	printf("vector2 x y z = \n");
	scanf("%lf %lf %lf", &v2.a, &v2.b, &v2.c);
	
	printf("\n");
	printf("Sum: %s;\nMulti: %s;\n", (v1 + v2).output(), (v1 * v2).output());
}
