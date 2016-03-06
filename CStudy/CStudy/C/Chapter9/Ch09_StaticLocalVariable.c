//#include<stdio.h>
///*
//	2016-02-19
//	static 지역변수 예제프로그램
//*/
//
//void SimpleFunc(void)
//{
//	static int num1 = 0; // 초기화 하지 않으면 0으로 초기화
//	int num2 = 0; // 초기화 하지 않으면 ERROR
//	// num1은 함수가 끝나도 소멸되지않으므로 값이 이전값에서 계속 증가한다.
//	num1++;
//	num2++;
//	printf("static: %d, local : %d \n", num1, num2);
//	
//}
//
//int main(void)
//{
//	int i;
//	for (i = 0; i < 3; i++)
//		SimpleFunc();
//	return 0;
//}