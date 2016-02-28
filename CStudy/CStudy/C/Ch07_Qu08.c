//#include<stdio.h>
///*
//	2016-02-17
//	문제)Qu07-08.c
//	정수 하나를 입력받은후 그 수의
//	팩토리얼 함수의 결과를 출력하는 프로그램을 while문을 이용하여 구현하시오.
//	출력예) 입력정수 : 5
//	5*4*3*2*1 = 120
//*/
//int main(void)
//{
//	// 곱셈 연산을 위하여 1로 초기화
//	int num, factorial = 1, idx;
//
//	printf("입력정수 : ");
//	scanf("%d", &num);
//
//	idx = num;
//
//	// factorial을 구하기 위한 loop
//	while (idx != 0)
//	{
//		printf("%d", idx);
//		factorial = factorial * idx;
//		idx--;
//
//		// '*' 출력
//		while (idx != 0)
//		{
//			printf("*");
//			// 출력후 바로 빠져나오기
//			break;
//		}
//	}
//
//	printf(" = %d \n", factorial);
//
//	return 0;
//}