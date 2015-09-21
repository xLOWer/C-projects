#include <stdio.h>
#include <malloc.h>

int main(void){
    int **m, **v, **r; //��������� 3 ������������ �������
	int n;
	printf("input size: "); scanf("%d", &n);//������ n
//************************�������� ������ ��� ������ �����������****************	
	m = (int** )malloc( n * sizeof(int* ));//�������
	v = (int** )malloc(sizeof(int* ));//������
	r = (int** )malloc( n * sizeof(int* ));//�������-��������� ���������
//************************�������� ������ ��� ������ �����������***************	
	for(int i = 0; i < n; i++){
		m[i] = (int*)malloc( n * sizeof(int));
		v[i] = (int*)malloc( n * sizeof(int));
		r[i] = (int*)malloc(sizeof(int));
	}
//************************������ � ����� ��-������� �������� �������***********
	printf("\ninput elements of massive: \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &m[i][j]); 
		}
	}
//*************************������ � ����� ��-������� �������� �������**********
	printf("\nninput vector: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &v[0][i]);
	}
//*************************����������� ������ �� �������***********************
	for(int i = 0; i < n; i++){
		r[i][0] = 0;
		for(int j = 0; j < n; j++){
			r[i][0] += m[i][j] * v[0][j];
		}
	}
//************************������� ���������*************************************
	printf("\nresult:\n");	
	for(int i = 0; i < n; i++){
			printf("%d\n", r[i][0]);
	}
}
