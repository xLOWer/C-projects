#include <stdio.h>

int main(void){
	char s[80];
	for(int i = 0 ; i < 80; ++i){s[i] = 0;}
	gets(s);
	for(int i = 0; i < 80; ++i){
		if(s[i] == 'a'){s[i] = 'A';}	
		if(s[i] == 'b'){s[i] = 'B';}
	}
	for(int i = 0 ; i < 80; ++i){printf("%c", s[i]);}
}
