//#include<stdio.h>
///*
//	2016-02-22
//	CH12.������
//
//	����1(Qu12-01.c) : ����� ����� �����غ���
//	int main(void)
//	{
//	int num = 10;
//	int * ptr1 = &num;
//	int * ptr2 = ptr1;
//
//	(*ptr1)++;
//	(*ptr2)++;
//	printf("%d \n", num);
//	return 0;
//	}
//	�ش� : 12
//	���� : (*ptr1) = num, ptr1 = ptr2, �� (*ptr1) = (*ptr2)
//
//	����2(Qu12-02.c) : int�� ���� num1�� num2�� ����� ���ÿ� ���� 10�� 20���� �ʱ�ȭ�ϰ�,
//	int�� ������ ���� ptr1, ptr2 �� �����Ͽ� num1, num2�� ����Ű�� ����.
//	ptr1, ptr2�� �̿��ؼ� num1 10����, num2 10������ ���...
//	ptr1, ptr2�� ����Ű�� ����� ���� �ٲ��� 15������Ų��.
//	�׸��� ptr1, ptr2�� ����Ű�� ������ ����� ���� ���...
//*/
//int main()
//{
//	int num1=10, num2 = 20;
//	int * ptr1 = &num1;
//	int * ptr2 = &num2;
//
//	(*ptr1)+=10;
//	(*ptr2)-=10;
//	printf("num1 : %d, num2 : %d \n", (*ptr1), (*ptr2));
//
//	// ����Ű�� ����� �����Ѵ�.
//	ptr1 = &num2;
//	ptr2 = &num1;
//	
//	ptr1 += 10;
//	(*ptr2) -= 10;
//	printf("num1 : %d, num2 : %d \n", (*ptr1), (*ptr2));
//
//	return 0;
//
//}