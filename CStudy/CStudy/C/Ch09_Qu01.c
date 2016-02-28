//#include<stdio.h>
///*
//	2016-02-19
//
//	문제1(Qu09-01.c)
//	세 개의 정수를 인자로 전달받아서 그중 가장 큰수와 가장 작은수를 반환하는 함수를 정의하라
//*/
//
//int Max(int num1, int num2, int num3);
//int Min(int num1, int num2, int num3);
//void main()
//{
//	int num1, num2, num3;
//	printf("정수 3개 입력 : ");
//	scanf("%d %d %d", &num1, &num2, &num3);
//
//	printf("가장 큰 수 : %d, 가장 작은 수 : %d \n", Max(num1, num2, num3), Min(num1, num2, num3));
//}
//
//// 가장 큰수를 반환하는 함수
//int Max(int num1, int num2, int num3)
//{
//	return num3 >= (num1 >= num2 ? num1 : num2) ? num3 : (num1 >= num2 ? num1 : num2);
//}
//
//// 가장 작은수를 반환하는 함수
//int Min(int num1, int num2, int num3)
//{
//	return num3 <= (num1 <= num2 ? num1 : num2) ? num3 : (num1 <= num2 ? num1 : num2);
//}