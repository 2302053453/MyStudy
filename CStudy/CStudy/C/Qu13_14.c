//#include<stdio.h>
///*
//	2016-02-23
//	����4(qu13-14.c)
//	���̰� 6�� int�� �迭�� �����Ͽ� 1,2,3,4,5,6 ���� �ʱ�ȭ �Ѵ�.
//	����� ���� ������ ������ ���α׷��� �ۼ��Ͻÿ�.
//*/
//
//void main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int * ptr = arr;
//	int temp;
//
//	printf("������ : ");
//	
//	for (int i = 0; i < 6; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//
//	// �迭�� ������ �����´� 
//	for (int i = 0; i < 3; i++)
//	{
//		temp = *(ptr + i);
//		*(ptr + i) = *(ptr + (5 - i));
//		*(ptr + (5 - i)) = temp;
//	}
//	printf("\n");
//
//	printf("������ : ");
//	for (int i = 0; i < 6; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}