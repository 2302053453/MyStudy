//#include<stdio.h>
///*
//	2016-02-23
//	call-by-reference 예제 프로그램
//*/
//
//void Swap(int * ptr1, int * ptr2)
//{
//	int temp = *ptr1;
//	*ptr1 = *ptr2;
//	*ptr2 = temp;
//}
//
//int main(void)
//{
//	int num1 = 10;
//	int num2 = 20;
//	printf("num1 num2 : %d %d \n", num1, num2);
//
//	// call-by-reference인 void형 함수이므로 
//	// 내부에서 실행된 결과값이 외부에 영향을 준다.
//	Swap(&num1, &num2);
//
//	printf("num1 num2 : %d %d \n", num1, num2);
//	return 0;
//}