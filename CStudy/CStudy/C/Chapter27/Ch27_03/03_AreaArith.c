#include"03_BasicArith.h"

/*
	2016-03-10
	���Ϻ��� ����
*/

double TriangleArea(double base, double height)
{
	return Div(Mul(base, height), 2);
}

double CircleArea(double rad)
{
	return Mul(rad, rad)* PI;
}