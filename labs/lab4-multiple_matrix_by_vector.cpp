#include <stdio.h>
#include <malloc.h>

int main(void){
    int **m, **v, **r; //объ€вл€ем 3 динамических массива
	int n;
	printf("input size: "); scanf("%d", &n);//вводим n
//************************выдел€ем пам€ть под первую размерность****************	
	m = (int** )malloc( n * sizeof(int* ));//матрица
	v = (int** )malloc(sizeof(int* ));//вектор
	r = (int** )malloc( n * sizeof(int* ));//матрица-результат умножени€
//************************выдел€ем пам€ть под вторую размерность***************	
	for(int i = 0; i < n; i++){
		m[i] = (int*)malloc( n * sizeof(int));
		v[i] = (int*)malloc( n * sizeof(int));
		r[i] = (int*)malloc(sizeof(int));
	}
//************************вводим с клавы по-очереди элемента массива***********
	printf("\ninput elements of massive: \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &m[i][j]); 
		}
	}
//*************************вводим с клавы по-очереди элемента вектора**********
	printf("\nninput vector: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &v[0][i]);
	}
//*************************перемножаем вектор на матрицу***********************
	for(int i = 0; i < n; i++){
		r[i][0] = 0;
		for(int j = 0; j < n; j++){
			r[i][0] += m[i][j] * v[0][j];
		}
	}
//************************выводим результат*************************************
	printf("\nresult:\n");	
	for(int i = 0; i < n; i++){
			printf("%d\n", r[i][0]);
	}
}
