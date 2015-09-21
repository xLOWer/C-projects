#include "windows.h"
#include <locale.h>

class HUMAN//класс HUMAN{
	public: char fname[255], lname[255], patromync[255];
	int yob;//year of birth :)
};

int compare(const void *i, const void *j){
	return ((HUMAN*)i)->yob - ((HUMAN*)j)->yob;	//функция для сравнения значений 
}

int main(void){
	setlocale(LC_ALL,"RUS");//расширяем ascii до русского языка
	
	int i = 0, j = 0, count = 0;
	HUMAN human[2][255];//2 массива по 255 человек
	FILE *file_in = fopen("C://c-file", "r");//открываем дял чтения файл
	
	while (!feof(file_in))//читаем пока не EOF{
		fscanf(file_in, "%s %s %s %d", &human[0][i].fname, 
									   &human[0][i].lname, 
									   &human[0][i].patromync, 
									   &human[0][i].yob);//заполняем массив
		count++;
		i++;
	}
	
	memcpy(human[1], human[0], sizeof(human[1]));//копируем первыймассив во второй
	qsort(human[1], count, sizeof(HUMAN), compare);//сортируем
	
	for (i = 0; i < count; i++){
		printf("%s %s %s %d\n", human[1][i].fname, 
								human[1][i].lname, 
								human[1][i].patromync, 
								human[1][i].yob);//выводим отсортированный массив
	}
}
