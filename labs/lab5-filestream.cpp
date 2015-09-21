#include <locale.h>

class HUMAN
{
	public: char fname[255], lname[255], patromync[255];
	int yoba;
};

int main(void){
	setlocale(LC_ALL,"RUS");
	
	FILE *file_in, *file_out;
	HUMAN hum;
	int i = 0;
	
	file_in = fopen("C://c-file", "r");
	file_out = fopen("C://c-file1", "w");
	
	while (!feof(file_in)){
		fscanf(file_in, "%s %s %s %d\n", &hum.fname, &hum.lname, &hum.patromync, &hum.yoba);
		if (hum.yoba > 1980){
			fprintf(file_out, "%s %s %s %d\n", hum.fname, hum.lname, hum.patromync, hum.yoba);
			printf("%s %s %s %d\n", hum.fname, hum.lname, hum.patromync, hum.yoba);
		}
	}
	fclose(file_in);
	fclose(file_out);
	
}
