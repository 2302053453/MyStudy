//#include<stdio.h>
///*
//	2016-02-23
//	Pointer 연산 예제 프로그램
//*/
//
//int main()
//{
//	// 적절치 않은 초기화
//	int * ptr1 = 0x0010;
//	double * ptr2 = 0x0010;
//
//	// 포인터 연산시 +1하면 각타입의 바이트수만큼 증가 (16진수)
//	printf("%p %p \n", ptr1 + 1, ptr1 + 2);
//	printf("%p %p \n", ptr2 + 1, ptr2 + 2);
//
//	printf("%p %p \n", ptr1, ptr2);
//	ptr1++;
//	ptr2++;
//
//	printf("%p %p \n", ptr1, ptr2);
//	return 0;
//}