//#include<stdio.h>
///*
//	2016-02-19
//	지역변수로 전역변수를 가리는 예제 프로그램
//*/
//
//int Add(int val);
//int num = 1;
//int main(void)
//{
//	int num = 5;
//	printf("num: %d \n", Add(3));
//	// 선언한 지역변수 num (5)를 사용
//	printf("num: %d \n", num + 9);
//	return 0;
//}
//
//int Add(int val)
//{
//	int num = 9;
//	// 이때의 num은 지역변수 num이다
//	num += val;
//	// 지역변수 num에 val을 더한 값을 반환한다.
//	return num;
//}