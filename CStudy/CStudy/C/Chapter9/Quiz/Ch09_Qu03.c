//#include<stdio.h>
///*
//	2016-02-19
//
//	����3(Qu09-03.c)
//	���ڷ� ���޵� ����ŭ �Ǻ���ġ ������ ����ϴ� �Լ��� �����϶�.
//	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ......
//	�Ǻ���ġ������ 0,1���� �����Ѵ�..
//*/
//int Fibinachi(int num, int isPrint, int maximum);
//// int Fibonachi(int num);
//
//int main()
//{
//	int num;
//	int isPrint = 1;
//	printf("�Ǻ���ġ �� : ");
//	scanf("%d", &num);
//
//	Fibinachi(num, isPrint, num);
//	// Fibonachi(num);
//	return 0;
//}
//
////int Fobinachi(int num)
////{
//	// �ݺ����� ���� ���� ���
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
//	// ó���������
//	if (num == maximum)
//		printf("0 ,1 ,");
//
//	// Fibonachi(1) = 1 or Fibonachi(0)
//	if (num == 0 || num == 1)
//		value = 1;
//
//	// 0 ���� ������ ������� �ʴ´�.
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
