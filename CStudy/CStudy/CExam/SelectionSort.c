//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	2016-02-24
//	���� ����
//	�� �������� �ִ밪(�ּҰ�)�� �����Ͽ� ������ �ڸ��� ��ġ��Ų��
//	ex) 25431 -> 21435 -> 21345 -> 12345
//	�ð����⵵ : O(n^2)
//*/
//
//enum ORDERING { ASC = 1, DSC = 2};
//
//void Swap(int *num1, int * num2)
//{
//	int temp = *num1;
//	*num1 = *num2;
//	*num2 = temp;
//}
//
//// ��������
//void SelectionSort(int * arr, int length, int ordering)
//{
//	int value;
//
//	for (int i = 0; i < 9; i++)
//	{
//		value = 0;
//		// length���� ���� �迭���� �ִ���ڸ� ���Ѵ�.
//		for (int j = 1; j < length; j++)
//		{
//			// ��������
//			if (ordering == ASC)  
//			{
//				if(arr[value] < arr[j])
//					// �ִ밪 ����
//					value = j;
//				printf("%d�� ���� : %d�������� �߰���� : ���� �ִ밪�� %d\n", i + 1, j, arr[value]);
//			}
//			// ��������
//			else if (ordering == DSC)  
//			{
//				if(arr[value] > arr[j])
//					// �ּҰ� ����
//					value = j;
//				printf("%d�� ���� : %d�������� �߰���� : ���� �ּҰ��� %d\n", i + 1, j, arr[value]);
//			}
//		}
//
//		// �迭���� ����
//		length--;
//
//		// �ִ밪�� ���������̶� �����Ұ�� ������ �����ʴ´�.
//		if (value != length)
//			Swap(&arr[value], &arr[length]);
//
//		printf("%d�� ���� ��� : ", i + 1);
//		for (int cnt = 0; cnt < 10; cnt++)
//			printf("%d ", arr[cnt]);
//		printf("\n");
//	}
//}
//
//// ��������
//void MakeRandomNumber(int * arr, int length)
//{
//	// ���� ����
//	srand((int)time(NULL));
//	for (int i = 0; i < length; i++)
//	{
//		arr[i] = rand() % 100;
//
//		// ���� �ߺ�üũ
//		for (int j = 0; j < i;)
//			if (arr[i] == arr[j])
//				arr[i] = rand() % 100;
//			else
//				j++;
//	}
//}
//
//// ���Ĺ�� ����
//void SelectAscOrDsc(int * ordering)
//{
//	// ���Ĺ�� ����(1,2 �̿��� ������ �� ��� �ٽ� �Է��ϵ��� ó��
//	while (*ordering != ASC && *ordering != DSC)
//	{
//		printf("���Ĺ���� �������ּ���.(��������:1, ��������:2) : ");
//		scanf("%d", ordering);
//
//		// 1,2�̿��� �ٸ����� ������� �޼��� ���
//		if (*ordering != ASC && *ordering != DSC)
//			printf("�߸������̽��ϴ�. �ٽ� �������ּ���\n");
//	}
//}
//
//void main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int length=sizeof(arr) / sizeof(int);
//	int ordering=0;
//	
//	// ���� ����
//	MakeRandomNumber(arr, length);
//
//	printf("���� �� ���� : ");
//	for (int i = 0; i < length; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//
//	SelectAscOrDsc(&ordering);
//
//	SelectionSort(arr, length, ordering);
//
//	printf("���� ��� : ");
//	for (int cnt = 0; cnt < 10; cnt++)
//		printf("%d ", arr[cnt]);
//	printf("\n");
//}