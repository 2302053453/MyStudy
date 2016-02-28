//#include<stdio.h>
///*
//	2016-02-22
//	문제(Qu11-01.c)
//	길이가 5인 int형 배열을 선언해서 사용자로부터 5개의 정수를 입력받는다.
//	그리고 최대값, 최소값, 모든수의합을 구하라. 함수(최대,최소,합)를 정의하여 구현하시오.
//*/
//
//int Max(int arr[], int size);
//int Min(int arr[], int size);
//int Sum(int arr[], int size);
//
//int main()
//{
//	int arr[5], size;
//	// 배열의 크기를 구한다
//	size = sizeof(arr) / sizeof(int);
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d번째 정수를 입력하세요: ", i + 1);
//		scanf(" %d", &arr[i]);
//	}
//
//	printf("최대값 : %d \n", Max(arr, size));
//	printf("최소값 : %d \n", Min(arr, size));
//	printf("합계 : %d \n", Sum(arr, size));
//}
//
//int Max(int arr[], int size)
//{
//	int max=0;
//	for (int i = 0; i < size; i++)
//		max = max >= arr[i] ? max : arr[i];
//	return max;
//}
//
//int Min(int arr[], int size)
//{
//	int min = 0;
//	for (int i = 0; i < size; i++)
//		min = min <= arr[i] ? min : arr[i];
//	return min;
//}
//
//int Sum(int arr[], int size)
//{
//	int sum = 0;
//	for (int i = 0; i < size; i++)
//		sum += arr[i];
//	return sum;
//}