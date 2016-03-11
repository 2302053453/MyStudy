#include<stdio.h>
#include "04_stdiv.h"
#include "04_Intdiv4.h"
/*
	2016-03-10
	구조체 파일분할 예제
*/

extern Div IntDiv(int num1, int num2);

int main()
{
	Div val = IntDiv(5, 2);
	printf("몫 : %d \n", val.quitient);
	printf("나머지 : %d \n", val.remainder);
	return 0;
}