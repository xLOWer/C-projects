#include <iostream>
#include <windows.h>
#include <ctime>

int main(void){
	srand(time(NULL));
	for(int i = 0; i <= 20; ++i){
		for(int j = 0; j <= 75-1; ++j){
			printf("%c",220 + rand()%2);
		}
		printf("\n");
	}
}
