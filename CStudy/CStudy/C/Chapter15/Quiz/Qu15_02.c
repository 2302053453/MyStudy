//#include<stdio.h>
//#include<math.h>
///*
//2016-02-26
//����2
//10������ �Է¹޾Ƽ� 2������ ��ȯ�ؼ� ����ϴ� ���α׷��� �ۼ��϶�.
//��¿���) 10������ �Է��Ͻÿ�. : 12
//2���� : 1100
//�ؾƷ��� 2������ ���ϴ� ������� ������ �մϴ�.
//2|   12
//-------
//2|    6 --- 0
//-------
//2|    3 --- 0
//-------
//1 --- 1
//*/
//
//void main()
//{
//	int num,k=1,bynary = 0, count=1;
//	printf("10������ �Է��Ͻÿ� : ");
//	scanf("%d", &num);
//	
//	// 10�������� �۰ų� ���� 2�� �ִ� ������ ���Ѵ�
//	while (1)
//	{
//		// 2�� k������ ǥ���� �� �ִ� �ִ� �� : 2�� (k+1)���� -1
//		if ( (k*2-1) < num)
//		{ 
//			k *= 2;
//			// 2���� �ڸ���(ex : (2����)100 -> 3)
//			count++;
//		}
//		else 
//			break;
//	}
//
//	for (int i = 0; i < count; i++ )
//	{
//		// 2������ 1 �ƴϸ� 0 ���
//		if (num >= k)
//		{
//			num -= k;
//			printf("1");
//		}
//		else
//			printf("0");	
//		k /= 2;
//	}
//
//	printf("\n");
//}