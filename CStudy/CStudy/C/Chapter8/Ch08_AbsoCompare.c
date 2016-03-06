//#include<stdio.h>
///*
//	2016-02-18
//	함수 선언 후 구현 예제 프로그램
//*/
//
//// 함수 선언 (구현은 나중에 한다.)
//int AbsoCompare(int num1, int num2);
//int GetAbsoValue(int num);
//
//int main(void)
//{
//	int num1, num2;
//	printf("두 개의 정수 입력: ");
//	scanf("%d %d", &num1, &num2);
//	// 함수 호출
//	printf("%d와 %d중 절댓값이 큰 정수: %d \n",
//		num1, num2, AbsoCompare(num1, num2));
//	return 0;
//}
//
//// 미리 선언했었던 함수 구현
//int AbsoCompare(int num1, int num2)
//{
//	// 함수 내부에서 다른 함수 호출
//	if (GetAbsoValue(num1) > GetAbsoValue(num2))
//		return num1;
//	else
//		return num2;
//}
//
//int GetAbsoValue(int num)
//{
//	if (num < 0)
//		return num * (-1);
//	else
//		return num;
//}