//#include<stdio.h>
///*	
//	2016-02-17
//	����4(Qu07-04.c)
//	�Ʒ��� ����� �ϼ��϶�.(while, for ���� ���ÿ� ����ؾ� �Ѵ�)
//		*
//		O*
//		OO*
//		OOO*
//		OOOO*
//	2016-02-18
//	��ȭ
//	���� ������ �Է¹޾� �Ƕ�̵� ���·� ���
//	 ex) 3 �Է½� 
//	  *
//	 O *
//	O O *
//   O O O *
//*/
//
//int main(void)
//{
//	int height = 0, num;
//
//	printf("���� �Է� : ");
//	scanf("%d", &num);
//
//
//	// while �ݺ��� ���
//	while (height < num)
//	{
//		// ��ȭ ���� �߰�(�պκ� ���� ���)
//		for (int i = 0; i < num - height; i++)
//			printf(" ");
//
//		// for �ݺ��� ���
//		for (int i = 0; i < height; i++)
//			printf("O ");
//		// printf("O"); -> ���� ����1
//
//		printf("*\n");
//		height++;
//	}
//
//	return 0;
//}