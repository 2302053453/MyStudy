//#include<stdio.h>
///*
//	2016-02-17
//	����)Qu07-08.c
//	���� �ϳ��� �Է¹����� �� ����
//	���丮�� �Լ��� ����� ����ϴ� ���α׷��� while���� �̿��Ͽ� �����Ͻÿ�.
//	��¿�) �Է����� : 5
//	5*4*3*2*1 = 120
//*/
//int main(void)
//{
//	// ���� ������ ���Ͽ� 1�� �ʱ�ȭ
//	int num, factorial = 1, idx;
//
//	printf("�Է����� : ");
//	scanf("%d", &num);
//
//	idx = num;
//
//	// factorial�� ���ϱ� ���� loop
//	while (idx != 0)
//	{
//		printf("%d", idx);
//		factorial = factorial * idx;
//		idx--;
//
//		// '*' ���
//		while (idx != 0)
//		{
//			printf("*");
//			// ����� �ٷ� ����������
//			break;
//		}
//	}
//
//	printf(" = %d \n", factorial);
//
//	return 0;
//}