//#include<stdio.h>
///*
//	2016-02-17
//	2단~9단 출력하는 예제 프로그램 (반복문 중첩)
//*/
//
//int main(void)
//{
//	int cur = 2;
//	int is = 0;
//
//	// 2단부터 9단까지 반복
//	while (cur < 10)
//	{
//		// 새로운 단의 시작
//		is = 1;
//
//		// 각단의 1부터 9의 곱을 표현
//		while (is < 10)
//		{
//			printf("%d * %d = %d \n", cur, is, cur*is);
//			is++;
//		}
//
//		// 단 증가
//		cur++;
//	}
//
//	return 0;
//}