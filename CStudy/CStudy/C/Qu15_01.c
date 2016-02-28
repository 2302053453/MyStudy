//#include<stdio.h>
///*
//	2016-02-26
//	문제1
//	길이가 10인 배열을 선언하고 총 10개의 정수를 입력받아서 홀수와 짝수를
//	구분해서 출력하라.
//	출력예시) 총 10개의 숫자를 입력하시오.
//	1 2 3 ....... 10개입력
//	홀수출력 : 1, 3, 5, 7, 9
//	짝수출력 : 2, 4, 6, 8, 10
//*/
//
//enum BOOL { FALSE = 0, TRUE = 1};
//void main()
//{
//	int num[10], isComma=FALSE;
//	printf("10개의 정수를 입력하시오 : ");
//	scanf("%d %d %d %d %d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9]);
//
//	// 홀수 출력
//	printf("홀수출력 : ");
//	for(int i = 0; i < 10; i++)
//	{
//		if (num[i] % 2 == 1)
//		{
//			// ',' 출력
//			printf(isComma == TRUE ? ", " : "");
//
//			printf("%d", num[i]);
//			isComma = TRUE;
//		}
//	}
//	
//	// ',' 출력 판별초기화
//	isComma = FALSE;
//
//	// 짝수 출력
//	printf("\n짝수출력 : ");
//	for (int i = 0; i < 10; i++)
//	{
//		if (num[i] % 2 == 0)
//		{
//			// ',' 출력
//			printf(isComma == TRUE ? ", ":"");
//
//			printf("%d", num[i]);
//			isComma = TRUE;
//		}
//	}
//
//	printf("\n");
//}