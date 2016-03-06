//#include<stdio.h>
///*
//	2016-02-23
//	call-by-value 예제
//*/
//
//void Swap(int n1, int n2)
//{
//	int temp = n1;
//	n1 = n2;
//	n2 = temp;
//	printf("n1 n2 : %d %d \n", n1, n2);
//}
//
//int main(void)
//{
//	int num1 = 10;
//	int num2 = 20;
//	printf("num1 num2 : %d %d \n", num1, num2);
//
//	// call-by-value인 void형 함수이므로 내부에서 실행된 결과값이 외부에 영향을 미치지않는다.
//	Swap(num1, num2);
//
//	printf("num1 num2 : %d %d \n", num1, num2);
//	return 0;
//}