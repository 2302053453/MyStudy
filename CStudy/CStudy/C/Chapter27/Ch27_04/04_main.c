#include<stdio.h>
#include "04_stdiv.h"
#include "04_Intdiv4.h"
/*
	2016-03-10
	����ü ���Ϻ��� ����
*/

extern Div IntDiv(int num1, int num2);

int main()
{
	Div val = IntDiv(5, 2);
	printf("�� : %d \n", val.quitient);
	printf("������ : %d \n", val.remainder);
	return 0;
}