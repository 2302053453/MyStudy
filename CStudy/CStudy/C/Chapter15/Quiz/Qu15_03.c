//#include<stdio.h>
///*
//	2016-02-26
//	����3
//	���̰� 10�� �迭�� �������� �� 10���� ������ �Է¹޴´�.
//	�� Ȧ���� �迭�� �տ��� ���� ä�������� ¦���� �迭�� ���������� ä��������.
//	��¿���) �� 10���� ������ �Է��Ͻÿ�.
//	1 2 3 4 5 6 7 8 9 10
//	��� : 1 3 5 7 9 10 8 6 4 2
//*/
//
//void main()
//{
//	int numArr[10], inputArr[10];
//	int minIdx = 0, maxIdx = 9;
//
//		printf("�� 10���� ������ �Է��Ͻÿ� : ");
//		scanf(	"%d %d %d %d %d %d %d %d %d %d",
//				&inputArr[0], &inputArr[1], &inputArr[2], &inputArr[3], &inputArr[4],
//				&inputArr[5], &inputArr[6], &inputArr[7], &inputArr[8], &inputArr[9]
//			);
//
//		// ¦���� ������, Ȧ���� ó������ �迭�� ����
//		for (int i = 0; i < 10; i++)
//		{
//			if (inputArr[i] % 2 == 0)
//			{
//				numArr[maxIdx] = inputArr[i];
//				maxIdx--;
//			}
//			else
//			{
//				numArr[minIdx] = inputArr[i];
//				minIdx++;
//			}
//		}
//
//		for (int i = 0; i < 10; i++)
//			printf("%d ", numArr[i]);
//
//		printf("\n");
//
//}