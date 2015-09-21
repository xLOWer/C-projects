#include <iostream>

int main(void){
	char m[50]; //строка
	for (int i = 0; i < 50; ++i){m[i] = 0;}//обнуляем массив
	scanf("%s", &m);//читаем строку
	
	for (int i = 0; i < 50; ++i){
		if (m[i] == 'a' || m[i] == 'b'){m[i] = toupper(m[i]);}//заменяем
			printf("%c", m[i]);//выводим
	}	
	return -0;//-0 is just for 1u1z... coz i can
} 
