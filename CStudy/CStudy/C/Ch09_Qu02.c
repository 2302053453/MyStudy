//#include<stdio.h>
///*
//	2016-02-19
//	����2(Qu09-02.c)
//	����(Celsius)�� �Է¹޾Ƽ� ȭ��(Fahrenheit)�� ��ȯ�Ͽ� �����ϴ� �Լ���
//	ȭ���� �Է¹޾Ƽ� ������ ��ȯ�Ͽ� �����ϴ� �Լ��� ������.
//	ȭ�� = 1.8 * ���� + 32
//	���� = (ȭ�� - 32) / 1.8
//*/
//
//double Convert(int select, double value);
//
//int main()
//{
//	int select;
//	double value;
//	printf("1.����, 2.ȭ�� ����� �Է��Ͻðڽ��ϱ�? : ");
//	scanf("%d", &select);
//	if (select != 1 && select != 2)
//	{ 
//		printf("�߸��Ȱ��Դϴ�. ���α׷��� �����մϴ�\n");
//		return 0;
//	}
//
//	printf("���� �Է����ּ���.");
//	scanf("%f", &value);
//	Convert(select, value);
//	
//	printf("��� : %f \n", value);
//	return 0;
//}
//
//double Convert(int select, double value)
//{
//	switch (select)
//	{
//		//���� -> ȭ��
//		case 1:
//			return  (double)1.8 * value + (double)32;
//		//ȭ�� -> ����
//		case 2:
//			return (value - 32) / 1.8;
//		default:
//			printf("����\n");
//			break;
//	}
//}
//
