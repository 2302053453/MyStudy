//#include<stdio.h>
///*
//	2016-02-25
//	double pointer ���� ���α׷�
//*/
//
//int main()
//{
//	double num = 3.14;
//	double * ptr = &num;
//	// ���������� ���� �� �ʱ�ȭ
//	// *dptr = ptr
//	double ** dptr = &ptr;
//	double * ptr2;
//
//	printf("%0p %0p \n", ptr, *ptr);
//	printf("%0g %0g \n", num, **dptr);
//	// ptr2 = ptr�� ���� �ǹ�
//	ptr2 = *dptr;
//	*ptr2 = 10.99;
//	printf("%0g %0g \n", num, **dptr);
//
//	return 0;
//}