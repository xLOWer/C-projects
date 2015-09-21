#include "windows.h"
#include <locale.h>

class HUMAN{//����� HUMAN
	public: char fname[255], lname[255], patromync[255];
	int yob;//year of birth :)
};

int compare(const void *i, const void *j){
	return ((HUMAN*)i)->yob - ((HUMAN*)j)->yob;	//������� ��� ��������� �������� 
}

int main(void){
	setlocale(LC_ALL,"RUS");//��������� ascii �� �������� �����
	
	int i = 0, j = 0, count = 0;
	HUMAN human[2][255];//2 ������� �� 255 �������
	FILE *file_in = fopen("C://c-file", "r");//��������� ��� ������ ����
	
	while (!feof(file_in)){//������ ���� �� ��������� ����� �����
		fscanf(file_in, "%s %s %s %d", &human[0][i].fname, 
									   &human[0][i].lname, 
									   &human[0][i].patromync, 
									   &human[0][i].yob);//��������� ������
		count++;//����������� ��������
		i++;
	}
	
	memcpy(human[1], human[0], sizeof(human[1]));//�������� ������ ������ �� ������
	qsort(human[1], count, sizeof(HUMAN), compare);//���������
	
	for (i = 0; i < count; i++){
		printf("%s %s %s %d\n", human[1][i].fname, 
								human[1][i].lname, 
								human[1][i].patromync, 
								human[1][i].yob);//������� ��������������� ������
	}
}
