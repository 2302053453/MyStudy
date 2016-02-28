//#include<stdio.h>
///*
//	2016-02-23
//	문제4(qu13-14.c)
//	길이가 6인 int형 배열을 선언하여 1,2,3,4,5,6 으로 초기화 한다.
//	저장된 값의 순서를 뒤집는 프로그램을 작성하시오.
//*/
//
//void main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int * ptr = arr;
//	int temp;
//
//	printf("변경전 : ");
//	
//	for (int i = 0; i < 6; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//
//	// 배열의 순서를 뒤집는다 
//	for (int i = 0; i < 3; i++)
//	{
//		temp = *(ptr + i);
//		*(ptr + i) = *(ptr + (5 - i));
//		*(ptr + (5 - i)) = temp;
//	}
//	printf("\n");
//
//	printf("변경후 : ");
//	for (int i = 0; i < 6; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}