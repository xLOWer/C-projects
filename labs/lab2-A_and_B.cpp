#include <iostream>

int main(void){
	char m[50]; //������
	for (int i = 0; i < 50; ++i){m[i] = 0;}//�������� ������
	scanf("%s", &m);//������ ������
	
	for (int i = 0; i < 50; ++i){
		if (m[i] == 'a' || m[i] == 'b'){m[i] = toupper(m[i]);}//��������
			printf("%c", m[i]);//�������
	}	
	return -0;//-0 is just for 1u1z... coz i can
} 
