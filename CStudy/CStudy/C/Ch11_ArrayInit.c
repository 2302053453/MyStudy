//#include<stdio.h>
///*
//	2016-02-22
//	Array ���� ���α׷�2
//*/
//
//int main(void)
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	// �迭�� ũ�⸦ �ڵ����� ����
//	int arr2[] = { 1,2,3,4,5,6,7 };
//	// �ʱ�ȭ���� ���� ���� 0���� �ʱ�ȭ
//	int arr3[5] = { 1,2 };
//	
//	int arr1len, arr2len, arr3len, i;
//	
//	// sizeof() : �ش� ����or �ڷ����� ũ�⸦ ��ȯ, �迭�� ũ�� : �ش� �迭�� �����ϴ� �뷮
//	printf("�迭 arr1�� ũ�� : %d \n", sizeof(arr1));
//	printf("�迭 arr2�� ũ�� : %d \n", sizeof(arr2));
//	printf("�迭 arr3�� ũ�� : %d \n", sizeof(arr3));
//
//	// �� �迭�� ���� ���, �迭�� ���� : �ش� �迭�� ��Ұ���
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