#include <iostream>
#include <windows.h>

int main(void){
	for(int i = 0; i <= 20; ++i){
		std::cout << "\n";
		for(int j = 0; j <= 40; ++j){
			if(rand()%2 == 0){
				std::cout << "\\";
			}
			else{
				std::cout << "/";
			}
		}
	}
}
