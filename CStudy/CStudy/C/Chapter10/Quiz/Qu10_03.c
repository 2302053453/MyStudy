//#include<stdio.h>
///*
//	2016-02-24
//	����3
//	���� �����ϰ� �ִ� �ݾ��� �Է¹޾Ƽ� �Ʒ� ������
//	�ܵ��� �������ʰ� �ּ� 1���̻� �����Ϸ��� ��� �����ؾ� �ϴ°�?
//	�� : 500��
//	���� : 700��
//	����� : 400��
//	��, 1600�� �̻��� �Է¹�������...
//*/
//
//void CheckMoneyIsZero(int snack, int bread, int drink, int money, int *isEnable)
//{
//	// ����, ��, ���ᰡ �ּ� �� 1���� �����ϸ� �� ���� �ݾװ� ������ ���
//
//	if ( snack>=1 && bread >=1 && drink >= 1 &&
//		(snack * 700) + (bread * 500) + (drink * 400) == money)
//	{ 
//		printf("���� %d��, �� %d��, ���� %d���� �� �� �ֽ��ϴ�.\n", snack, bread, drink);
//		(*isEnable)++;
//	}
//}
//
//void main()
//{
//	int money, isEnable=0;
//	printf("�ݾ��� �Է����ּ��� : ");
//	
//	do
//	{ 
//		scanf("%d", &money);
//		if(money<1600)
//			printf("1600�� �̻� �Է��ؾ� �մϴ�\n �ٽ� �Է����ּ��� : ");
//	} while (money < 1600);
//
//	for (int snack = 0; (snack*700) <= money; snack++)
//		for (int bread = 0; (snack*700)+(bread*500) <= money; bread++)
//			for (int drink = 0; (snack * 700) + (bread * 500) + (drink * 400) <= money; drink++)
//				CheckMoneyIsZero(snack, bread, drink, money, &isEnable);
//
//	// ���� ������ �����ϴ� ���Ź���� ������ �Ұ��޼��� ���
//	if (isEnable == 0)
//		printf("�ش� �ݾ����� �ܵ����� ��� ��ǰ�� �� �ϳ��� �� �� �ִ� ����� �����ϴ�\n");
//
//}
//
