//#include<stdio.h>
///*
//	2016-02-22
//	����(Qu11-01.c)
//	���̰� 5�� int�� �迭�� �����ؼ� ����ڷκ��� 5���� ������ �Է¹޴´�.
//	�׸��� �ִ밪, �ּҰ�, ���������� ���϶�. �Լ�(�ִ�,�ּ�,��)�� �����Ͽ� �����Ͻÿ�.
//*/
//
//int Max(int arr[], int size);
//int Min(int arr[], int size);
//int Sum(int arr[], int size);
//
//int main()
//{
//	int arr[5], size;
//	// �迭�� ũ�⸦ ���Ѵ�
//	size = sizeof(arr) / sizeof(int);
//
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d��° ������ �Է��ϼ���: ", i + 1);
//		scanf(" %d", &arr[i]);
//	}
//
//	printf("�ִ밪 : %d \n", Max(arr, size));
//	printf("�ּҰ� : %d \n", Min(arr, size));
//	printf("�հ� : %d \n", Sum(arr, size));
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