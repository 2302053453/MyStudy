//#include<stdio.h>
///*
//	2016-02-19
//	지역 변수 예제 프로그램
//*/
//
//
//void main()
//{
//	int num = 1;
//	if (num == 1)
//	{
//		// 아래 구문 선언시 if 문 내의 num 은 7이되며 if 문 이후에는 소멸된다. 
//		int num = 7;
//		num += 10;
//		printf("if 문 내 지역변수 : %d \n", num);
//	}
//	printf("main 함수 내 지역변수 num = %d \n", num);
//
//}