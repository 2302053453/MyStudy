#include "04_stdiv.h"
/*
2016-03-10
����ü ���Ϻ��� ����
*/

Div IntDiv(int num1, int num2)
{
	Div dval;
	dval.quitient = num1 / num2;
	dval.remainder = num1 % num2;
	return dval;
}