//#include<stdio.h>
///*
//	2016-02-24
//	문제1
//	2개의 정수를 입력받아서 해당하는 구간의 구구단을 출력하는 프로그램을 작성하라.
//	2와 5를 입력받았다면 2단, 3단, 4단, 5단이 출력되어야 한다.
//*/
//
//void main()
//{
//	int num1, num2, temp;
//	printf("구구단을 출력할 정수 2개 입력 : ");
//	scanf("%d %d", &num1, &num2);
//
//	// num1이 num2보다 클 경우 swap
//	if (num2 < num1)
//	{
//		temp = num1;
//		num1 = num2;
//		num2 = temp;
//	}
//
//	// 구구단 출력
//	for (num1; num1 < num2 + 1; num1++)
//	{
//		printf("%d단\n", num1);
//		for (int i = 1; i < 10; i++)
//			printf("%d * %d = %d\n", num1, i, num1*i);
//	}
//}