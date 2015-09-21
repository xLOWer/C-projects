#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#define h 2
#define w 8

int main(void){
	signed short int m[h][w];
	//signed short int m[255][2];
	//bool k = false;
	srand(time(NULL));
	for(int i = 0; i < h/2; i+=2){
		for(int j = 0; j < w/2; j+=2){
			m[i][j] = rand()%2;
			if(m[i][j] == 0){
				printf(" ");
				printf("%c\n", 219);
				printf(" ");
				printf("%c\b", 219);
			}
			else{
				printf(" ");
				printf(" \n");
				printf("%c", 219);
				printf("%c\b", 219);
			}
		}
		printf("\n");
	}
	/*while(k != true){
	}*/
}
