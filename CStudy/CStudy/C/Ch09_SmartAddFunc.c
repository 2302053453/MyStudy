//#include<stdio.h>
///*
//	2016-02-18
//	����, ��ȯ���� �ִ� ���� ���α׷�
//*/
//
//// ��������(O), ��ȯ ��(O)
//int Add(int num1, int num2) 
//{
//	return num1 + num2;
//}
//
//// �������� (O), ��ȯ ��(X)
//void ShowAddResult(int num)
//{
//	printf("������� ��� : %d \n", num);
//}
//
//// ��������(X), ��ȯ ��(O)
//int ReadNum(void)
//{
//	int num;
//	scanf("%d", &num);
//	return num;
//}
//
//// ��������(X), ��ȯ ��(X)
//void HowToUseThisProg(void)
//{
//	printf("�� ���� ������ �Է��Ͻø� ��������� ��µ˴ϴ�. \n");
//	printf("��! �׷� �� ���� ������ �Է��ϼ���. \n");
//}
//
//int main_SmartAddFunc(void)
//{
//	int result, num1, num2;
//	HowToUseThisProg();
//	num1 = ReadNum();
//	num2 = ReadNum();
//	result = Add(num1,num2);
//	ShowAddResult(result);
//	return 0;
//}