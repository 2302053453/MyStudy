//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	 2016-02-23
//	 BubbleSort ���α׷�
//	 �� �������� ������ġ�� ������ġ�� ũ�⸦ ���Ͽ� ���ҽ��Ѽ� ����
//	 ex) 1������ : 52143 -> 25143 -> 21543 -> 21453 -> 21435
//		 2������ : 21435 -> 12435
//		 3������ : 12435 -> 12345 
//		 END
//*/
//
//void Swap(int * num1, int * num2)
//{
//	int temp = *num1;
//	*num1 = *num2;
//	*num2 = temp;
//}
//
//void BubbleSort(int * num,int size, int isASC)
//{
//	// �� ���� Ƚ����ŭ �ݺ�
//	for (int i = 0; i < size; i++)
//	{
//		// ���ĵ� ���� ������ ������ ���� ���� �ݺ�
//		for (int j = 0; j < 9 - i; j++)
//		{
//			// ��������
//			if (isASC == 2 && num[j] > num[j + 1])
//				Swap(&num[j], &num[j + 1]);
//
//			// ��������
//			else if (isASC == 1 && num[j] < num[j + 1])
//				Swap(&num[j], &num[j + 1]);
//
//			// �� ���� ���
//			printf("%d��° ����, %d��°  : ", i+1, j+1);
//			for (int i = 0; i < 10; i++)
//				printf("%d ", num[i]);
//			printf("\n");
//		}
//	}
//}
//
//
//void main()
//{
//	
//
//	int size;
//	int num[10];
//	int isASC = 0;
//
//	printf("BubbleSort ���α׷��Դϴ�. \n");
//	
	//// ���Ĺ�� ����(1,2 �̿��� ������ �� ��� �ٽ� �Է��ϵ��� ó��
	//while (isASC != 1 && isASC != 2)
	//{
	//	printf("���Ĺ���� �������ּ���.(��������:1, ��������:2) : ");
	//	scanf("%d", &isASC);

	//	// 1,2�̿��� �ٸ����� ������� �޼��� ���
	//	if (isASC != 1 && isASC != 2)
	//		printf("�߸������̽��ϴ�. �ٽ� �������ּ���\n");
	//}
//
//	// �迭�� size �ʱ�ȭ
//	size = sizeof(num) / sizeof(int);
//
//	// ���� ����
//	srand((int)time(NULL));
//	for (int i = 0; i < size; i++)
//	{ 
//		num[i] = rand() % 100;
//
//		// ���� �ߺ�üũ
//		for (int j = 0; j < i;)
//			if (num[i] == num[j])
//				num[i] = rand() % 100;
//			else
//				j++;
//	}
//	
//	// �������� ���� ���
//	printf("�ʱ���� : ");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", num[i]);
//	printf("\n");
//
//	// BubbleSort
//	BubbleSort(num, size, isASC);
//
//	// �������� ���� ���
//	printf("���İ�� : ");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", num[i]);
//	printf("\n");
//}