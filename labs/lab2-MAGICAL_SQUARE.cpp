#include <stdio.h>

int main(void){
	int b[3][3], e = 0, w = 0; ///init 3 lol
	bool l = false;
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			scanf("%d", &m[i][j]);//read matrix
		}
	}
	x = 0; y = x;//nulling - обнуление, translate.google.com говорит, что верный термин для обнуления
	printf("\n");
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(i == j)
			{
				x += m[i][j];//для элементов главное диагонали
			}
			
			if(i + j == 2)
			{
				y += m[i][j];//для элементов побочной диагонали
			}
		}
		printf("\n");
	}
	for(int i = 0; i < 3; ++i){
		if(((m[i][0] + m[i][1] + m[i][2])== x && (m[0][i] + m[1][i] + m[2][i])== x && (x)== x && (y)== x)){
			k = true;}else{k = false;}//условие магического квадрата
	}
	if(k == true){printf("MAGICAL\n"); } else{ printf("NOT MAGICAL\n");}//условие
	printf("glavnaya:\t%d\n", y);
	printf("poboxhnaya:\t%d\n\n", x);
	/*
		I so love making a lot comments <3
		for every string....
		...everywhere...
		=)
	*/
}
