//#include<stdio.h>
///*
//	2016-02-22
//	Array 예제 프로그램2
//*/
//
//int main(void)
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	// 배열의 크기를 자동으로 지정
//	int arr2[] = { 1,2,3,4,5,6,7 };
//	// 초기화되지 않은 값은 0으로 초기화
//	int arr3[5] = { 1,2 };
//	
//	int arr1len, arr2len, arr3len, i;
//	
//	// sizeof() : 해당 변수or 자료형의 크기를 반환, 배열의 크기 : 해당 배열이 차지하는 용량
//	printf("배열 arr1의 크기 : %d \n", sizeof(arr1));
//	printf("배열 arr2의 크기 : %d \n", sizeof(arr2));
//	printf("배열 arr3의 크기 : %d \n", sizeof(arr3));
//
//	// 각 배열의 길이 계산, 배열의 길이 : 해당 배열의 요소갯수
//	arr1len = sizeof(arr1) / sizeof(int);
//	arr2len = sizeof(arr2) / sizeof(int);
//	arr3len = sizeof(arr3) / sizeof(int);
//
//	for (i = 0; i < arr1len; i++)
//		printf("%d ", arr1[i]);
//	printf("\n");
//
//	for (i = 0; i < arr2len; i++)
//		printf("%d ", arr2[i]);
//	printf("\n");
//
//	for (i = 0; i < arr3len; i++)
//		printf("%d ", arr3[i]);
//	printf("\n");
//
//	return 0;
//}