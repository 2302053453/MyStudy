//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	2016-02-18
//	Ex)���������� ���� �����	
//	���ϸ� : Ex_RPSGame.c
//	���Ӽ��� :
//	1,2,3�� �ϳ��� ���ڸ� ������ �����Ѵ�.	
//	����ڰ� ����(1),����(2),��(3) �� �ϳ��� ����.
//	�ºθ� �Ǵ��Ͽ� ����Ѵ�.
//	1,2,3 �̿��� ���ڸ� �Է��ϸ� �߸��� �Է��� �˷��ش�.
//*/
//
//// �÷��̾� ���ð��� �޾� ��ȯ
//int PlayerSelect()
//{
//	int sel;
//
//	scanf("%d", &sel);
//
//	// 1~3�� �״�� , �������� ERROR(-1)
//	if (sel >= 1 && sel <= 3)
//		return sel;
//	else
//		return -1;
//}
//
//// ��ǻ���� ���ð��� ��ȯ
//int ComputerSelect()
//{
//	// ��ǻ���� ���ð� : ���� ����
//	int sel;
//	srand((int)time(NULL));
//	sel = (rand() % 100 + 1) % 3 + 1;
//
//	return sel;
//}
//
//// �÷��̾�� ��ǻ�Ͱ� ��� ��� ���
//void Versus(int player, int computer)
//{
//	// LOSE CASE( ����(1),����(2) / ����(2), ��(3) / ��(3),����(1) ) 
//	if (player - computer == -1 || player - computer == 2)
//		printf("�����ϴ�!\n");
//	// WIN CASE( ����(1), ��(3) / ����(2), ����(1) / ��(3), ����(2) )
//	else if (player - computer == 1 || player - computer == -2)
//		printf("�̰���ϴ�!\n");
//	// DRAW CASE ( ���� ���� ��� )
//	else if (player == computer)
//		printf("�����ϴ�!\n");
//}
//
//// ������(�Է°�)�� ���� ����, ����, �� ���
//void PrintString(int sel)
//{
//	switch (sel)
//	{
//	case 1:
//		printf("����");
//		return;
//	case 2:
//		printf("����");
//		return;
//	case 3:
//		printf("��");
//		return;
//	}
//}
//
//void main_RSPGame()
//{
//	int player, computer;
//
//	while (1)
//	{
//		printf("����������(1.���� 2.���� 3.��)");
//
//		// �÷��̾� ����
//		player = PlayerSelect();
//
//		// 3�̿��� �� �Է��� ���
//		if (player == -1)
//		{
//			printf("�ٽü���\n");
//			continue;
//		}
//
//		// ��ǻ�� ����
//		computer = ComputerSelect();
//
//		// �÷��̾ �� �� ���
//		printf("�÷��̾� : ");
//		PrintString(player);
//		printf("\n");
//
//		// ��ǻ�Ͱ� �� �� ���
//		printf("��ǻ�� : ");
//		PrintString(computer);
//		printf("\n");
//
//		// ��� ���
//		Versus(player, computer);
//	}
//}