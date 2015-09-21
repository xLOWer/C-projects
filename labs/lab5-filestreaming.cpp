#include <locale.h>

class HUMAN
{
	public: char fname[255], lname[255], patromync[255];
	int yob;//year of birth
};

int main(void){
	setlocale(LC_ALL,"RUS");//расшир€ем askii до русского €зыка
	
	FILE *file_in, *file_out;// объ€вл€ем 2 файловых поинтера
	HUMAN hum;//объ€вл€ем структуру человек
	int i = 0;
	
	file_in = fopen("C://c-file", "r");//открываем дл€ чтени€
	file_out = fopen("C://c-file1", "w");//открываем дл€ записи
	
	while (!feof(file_in)){//читаем файл покане достигнем его конца
		fscanf(file_in, "%s %s %s %d\n", &hum.fname, &hum.lname, &hum.patromync, &hum.yob);
		if (hum.yob > 1980){//если год больше 1980 то записываем в новый массив
			fprintf(file_out, "%s %s %s %d\n", hum.fname, hum.lname, hum.patromync, hum.yob);
			printf("%s %s %s %d\n", hum.fname, hum.lname, hum.patromync, hum.yob);//выводим >1980
		}
	}
	fclose(file_in);//закрываем
	fclose(file_out);//         файлы
	
}
