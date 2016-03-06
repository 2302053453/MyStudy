//#include<stdio.h>
///*
//	2016-02-24
//	문제7
//	2의 n승을 구하는 함수를 재귀함수를 이용하여 구현해보자.
//*/
//long long SquareOfTwo(int n)
//{
//	if (n == 1)
//		return (long long)2;
//	else 
//		return (long long) (2 * SquareOfTwo(n - 1));
//}
//
//void main()
//{
//	int n;
//	printf("2의 N제곱에서 N을 입력해주세요: ");
//	scanf("%d", &n);
//	printf("2의 %d제곱 : %lld입니다 \n", n, SquareOfTwo(n));
//}