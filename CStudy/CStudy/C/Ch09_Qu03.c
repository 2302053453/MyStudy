//#include<stdio.h>
///*
//	2016-02-19
//
//	문제3(Qu09-03.c)
//	인자로 전달된 수만큼 피보나치 수열을 출력하는 함수를 정의하라.
//	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ......
//	피보나치수열은 0,1에서 시작한다..
//*/
//int Fibinachi(int num, int isPrint, int maximum);
//// int Fibonachi(int num);
//
//int main()
//{
//	int num;
//	int isPrint = 1;
//	printf("피보나치 수 : ");
//	scanf("%d", &num);
//
//	Fibinachi(num, isPrint, num);
//	// Fibonachi(num);
//	return 0;
//}
//
////int Fobinachi(int num)
////{
//	// 반복문을 통한 수열 출력
//	/*
//	int printValue, leftValue=0, rightValue=1;
//
//	printf("0,1,");
//
//	for (int i = 0; i < num; i++)
//	{
//	printValue = leftValue + rightValue;
//	printf("%d", printValue);
//	leftValue = rightValue;
//	rightValue = printValue;
//
//	if (i < num - 1)
//	printf(",");
//	}
//	printf("\n");
//
//	return 0;
//	*/
////}
//
//int Fibinachi(int num, int isPrint, int maximum)
//{
//	int value;
//
//	// 처음문장출력
//	if (num == maximum)
//		printf("0 ,1 ,");
//
//	// Fibonachi(1) = 1 or Fibonachi(0)
//	if (num == 0 || num == 1)
//		value = 1;
//
//	// 0 보다 작으면 계산하지 않는다.
//	else if (num < 0)
//		value = 0;
//
//	else
//		value = isPrint == 1 ? Fibinachi(num - 1, 1,maximum) + Fibinachi(num - 2, 0, maximum)
//							  : Fibinachi(num - 1, 0, maximum) + Fibinachi(num - 2, 0, maximum);
//
//	if (isPrint == 1)
//	{ 
//		printf("%d ", value);
//
//		if (num != maximum)
//			printf(",");
//	}
//
//	return value;
//}
