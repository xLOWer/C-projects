#include <locale.h>

class HUMAN
{
	public: char fname[255], lname[255], patromync[255];
	int yob;//year of birth
};

int main(void){
	setlocale(LC_ALL,"RUS");//��������� askii �� �������� �����
	
	FILE *file_in, *file_out;// ��������� 2 �������� ��������
	HUMAN hum;//��������� ��������� �������
	int i = 0;
	
	file_in = fopen("C://c-file", "r");//��������� ��� ������
	file_out = fopen("C://c-file1", "w");//��������� ��� ������
	
	while (!feof(file_in)){//������ ���� ������ ��������� ��� �����
		fscanf(file_in, "%s %s %s %d\n", &hum.fname, &hum.lname, &hum.patromync, &hum.yob);
		if (hum.yob > 1980){//���� ��� ������ 1980 �� ���������� � ����� ������
			fprintf(file_out, "%s %s %s %d\n", hum.fname, hum.lname, hum.patromync, hum.yob);
			printf("%s %s %s %d\n", hum.fname, hum.lname, hum.patromync, hum.yob);//������� >1980
		}
	}
	fclose(file_in);//���������
	fclose(file_out);//         �����
	
}
