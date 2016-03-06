//#include<stdio.h>
///*
//	2016-02-18
//	문제2(Qu08-02.c)
//	두개의 정수를 입력 받아서 두수의 차를 출력하는 프로그램을 작성하라.
//	단 입력된 두 수의 순서에 상관없이 출력결과는 항상 0 이상이어야 한다.
//	1과2를 입력했다면 1 .... 20과10을 입력했다면 10 ....
//	위 프로그램을 if문과 조건연산자를 이용하여 작성해보자.
//*/
//
//int main(void)
//{
//	int num1, num2;
//	printf("두 수의 차를 구하기 위하여 정수 2개를 입력해주세요: ");
//	scanf("%d %d", &num1, &num2);
//	if (num1 > num2)
//		printf("(%d) - (%d) = %d", num1, num2, num1 - num2);
//	else if (num1 < num2)
//		printf("(%d) - (%d) = %d", num2, num1, num2 - num1);
//	else if (num1 == num2)
//		printf("ERROR! : 입력하신 두 정수가 같습니다.\n 프로그램을 종료합니다.\n");
//
//	return 0;
//}