//#include<stdio.h>
//#include<math.h>
///*
//	2016-02-26
//	����1
//	���̰� 4 by 4�� int�� �迭�� �����ϰ� ������� 1, 2, 3 �� ������ �Է��Ͽ� �ʱ�ȭ����.
//	�׸��� �迭�� ��ҵ��� ������ �������� 90���� �̵����Ѽ� �� ����� ����ϴ� ���α׷��� �ۼ��϶�.
//	�߰������� Ƚ���� �Է¹޾� �� Ƚ����ŭ ȸ���ϴ� ������ �����־�� �Ѵ�.
//	1  2  3  4			13  9   5  1
//	5  6  7  8   ->		14  10  6  2
//	9  10 11 12			15  11  7  3
//	13 14 15 16			16  12  8  4
//	*/
//
//void main()
//{
//	int numArr[4][4], numArr2[4][4], rotationCount, value =1;
//
//	printf("ȸ�� Ƚ���� �Է��ϼ��� : ");
//	scanf("%d", &rotationCount);
//
//	// �ʱ� �迭 ����
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//		{
//			numArr[i][j] = value++;
//			// �迭����
//			numArr2[i][j] = numArr[i][j];
//		}
//
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			printf("%2d ", numArr[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//
//	// �Է�Ƚ�� ��ŭ ȸ��
//	while (rotationCount > 0)
//	{
//		for (int i = 0; i < 4; i++)	
//			for (int j = 0; j < 4; j++)
//			{
//				/*
//					���� ��ȭ : 0,0 -> 3,0, 3,0 -> 3,3, 3,3 -> 0,3, 0,3->0,0 ...
//					�̷������� ���� (����ũ�� -3)�� ���밪�̰�
//					���� �ప�� �ȴ�.
//				*/
//				value = (int)sqrt((double)(j - 3)*(double)(j - 3));
//				numArr[i][j] = numArr2[value][i];
//			}
//
//		for (int i = 0; i < 4; i++)
//		{ 
//			for (int j = 0; j < 4; j++)
//			{ 
//				printf("%2d ", numArr[i][j]);
//				// ����� �迭 ����
//				numArr2[i][j] = numArr[i][j];
//			}
//			printf("\n");
//		}
//
//		printf("\n");
//		rotationCount--;
//	}
//
//
//}