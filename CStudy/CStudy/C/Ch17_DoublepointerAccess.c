//#include<stdio.h>
///*
//	2016-02-25
//	double pointer 예제 프로그램
//*/
//
//int main()
//{
//	double num = 3.14;
//	double * ptr = &num;
//	// 더블포인터 선언 및 초기화
//	// *dptr = ptr
//	double ** dptr = &ptr;
//	double * ptr2;
//
//	printf("%0p %0p \n", ptr, *ptr);
//	printf("%0g %0g \n", num, **dptr);
//	// ptr2 = ptr과 같은 의미
//	ptr2 = *dptr;
//	*ptr2 = 10.99;
//	printf("%0g %0g \n", num, **dptr);
//
//	return 0;
//}