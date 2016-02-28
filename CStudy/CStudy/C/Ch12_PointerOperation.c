//#include<stdio.h>
///*
//	2016-02-22
//	Pointer 예제 프로그램
//*/
//
//int main()
//{
//	int num1 = 100, num2 = 100;
//	// 포인터변수 선언
//	int * pnum;
//
//	// 포인터 pnum이 num1을 가리킨다
//	pnum = &num1;
//	// (*pnum) = num1이라 보면 되므로 num1 += 30과 동일
//	(*pnum) += 30;
//
//	// 포인터 pnum이 num2을 가리킨다
//	pnum = &num2;
//	// (*pnum) = num2이라 보면 되므로 num2 += 30과 동일
//	(*pnum) -= 30;
//
//	printf("num1 : %d, num2 : %d \n", num1, num2);
//
//	return 0;
//
//}