//#include<stdio.h>
///*
//	2016-02-18
//	�Լ� ���� �� ���� ���� ���α׷�
//*/
//
//// �Լ� ���� (������ ���߿� �Ѵ�.)
//int AbsoCompare(int num1, int num2);
//int GetAbsoValue(int num);
//
//int main(void)
//{
//	int num1, num2;
//	printf("�� ���� ���� �Է�: ");
//	scanf("%d %d", &num1, &num2);
//	// �Լ� ȣ��
//	printf("%d�� %d�� ������ ū ����: %d \n",
//		num1, num2, AbsoCompare(num1, num2));
//	return 0;
//}
//
//// �̸� �����߾��� �Լ� ����
//int AbsoCompare(int num1, int num2)
//{
//	// �Լ� ���ο��� �ٸ� �Լ� ȣ��
//	if (GetAbsoValue(num1) > GetAbsoValue(num2))
//		return num1;
//	else
//		return num2;
//}
//
//int GetAbsoValue(int num)
//{
//	if (num < 0)
//		return num * (-1);
//	else
//		return num;
//}