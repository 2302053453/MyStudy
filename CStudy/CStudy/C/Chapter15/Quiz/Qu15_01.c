//#include<stdio.h>
///*
//	2016-02-26
//	����1
//	���̰� 10�� �迭�� �����ϰ� �� 10���� ������ �Է¹޾Ƽ� Ȧ���� ¦����
//	�����ؼ� ����϶�.
//	��¿���) �� 10���� ���ڸ� �Է��Ͻÿ�.
//	1 2 3 ....... 10���Է�
//	Ȧ����� : 1, 3, 5, 7, 9
//	¦����� : 2, 4, 6, 8, 10
//*/
//
//enum BOOL { FALSE = 0, TRUE = 1};
//void main()
//{
//	int num[10], isComma=FALSE;
//	printf("10���� ������ �Է��Ͻÿ� : ");
//	scanf("%d %d %d %d %d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9]);
//
//	// Ȧ�� ���
//	printf("Ȧ����� : ");
//	for(int i = 0; i < 10; i++)
//	{
//		if (num[i] % 2 == 1)
//		{
//			// ',' ���
//			printf(isComma == TRUE ? ", " : "");
//
//			printf("%d", num[i]);
//			isComma = TRUE;
//		}
//	}
//	
//	// ',' ��� �Ǻ��ʱ�ȭ
//	isComma = FALSE;
//
//	// ¦�� ���
//	printf("\n¦����� : ");
//	for (int i = 0; i < 10; i++)
//	{
//		if (num[i] % 2 == 0)
//		{
//			// ',' ���
//			printf(isComma == TRUE ? ", ":"");
//
//			printf("%d", num[i]);
//			isComma = TRUE;
//		}
//	}
//
//	printf("\n");
//}