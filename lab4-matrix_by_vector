#include <stdio.h>
#include <malloc.h>

int main(void){
    int **m, **v, **r; 
	int n;
	printf("input size: "); scanf("%d", &n);
//************************выделяем память под первую размерность****************	
	m = (int** )malloc( n * sizeof(int* ));
	v = (int** )malloc(sizeof(int* ));
	r = (int** )malloc( n * sizeof(int* ));
//************************выделяем память под вторую размерность***************	
	for(int i = 0; i < n; i++){
		m[i] = (int*)malloc( n * sizeof(int));
		v[i] = (int*)malloc( n * sizeof(int));
		r[i] = (int*)malloc(sizeof(int));
	}
//************************вводим с клавы по-очереди элемента массива***********
	printf("input elements of massive: \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &m[i][j]); 
		}
	}
	printf("\n");
//*************************вводим с клавы по-очереди элемента вектора**********
	printf("input vector: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &v[0][i]);
	}
	printf("\n");
//*************************перемножаем вектор на матрицу***********************
	for(int i = 0; i < n; i++){
		r[i][0] = 0;
		for(int j = 0; j < n; j++){
			r[i][0] += m[i][j] * v[0][j];
		}
	}
	printf("\n");
//************************выводим результат*************************************
	printf("result:\n");	
	for(int i = 0; i < n; i++){
			printf("%d\n", r[i][0]);
	}
}
