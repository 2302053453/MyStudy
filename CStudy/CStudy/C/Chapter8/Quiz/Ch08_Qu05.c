//#include<stdio.h>
///*
//	2016-02-18
//	문제5(Qu08-05.c)
//	다음 식을 만족하는 모든 A와 Z를 구하는 프로그램을 작성하라
//	AZ
//	+ZA
//	-----
//	99
//	단, A와 Z는 서로다른 숫자이다.
//*/
//
//int main(void)
//{
//	// AB = (A*10)+ B, BA = (B*10)+A
//	for (int i = 0; i < 10; i++)
//		for (int j = 0; j < 10; j++)
//			if (((i * 10) + j) + (i + (j * 10)) == 99)
//				printf("%d%d+%d%d = 99\n", i, j, j, i);
//
//	return 0;
//}