//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	2016-02-18
//	Ex)가위바위보 게임 만들기	
//	파일명 : Ex_RPSGame.c
//	게임설명 :
//	1,2,3중 하나의 숫자를 난수로 생성한다.	
//	사용자가 가위(1),바위(2),보(3) 중 하나를 낸다.
//	승부를 판단하여 출력한다.
//	1,2,3 이외의 숫자를 입력하면 잘못된 입력을 알려준다.
//*/
//
//// 플레이어 선택값을 받아 반환
//int PlayerSelect()
//{
//	int sel;
//
//	scanf("%d", &sel);
//
//	// 1~3은 그대로 , 나머지는 ERROR(-1)
//	if (sel >= 1 && sel <= 3)
//		return sel;
//	else
//		return -1;
//}
//
//// 컴퓨터의 선택값을 반환
//int ComputerSelect()
//{
//	// 컴퓨터의 선택값 : 난수 생성
//	int sel;
//	srand((int)time(NULL));
//	sel = (rand() % 100 + 1) % 3 + 1;
//
//	return sel;
//}
//
//// 플레이어와 컴퓨터간 대결 결과 출력
//void Versus(int player, int computer)
//{
//	// LOSE CASE( 가위(1),바위(2) / 바위(2), 보(3) / 보(3),가위(1) ) 
//	if (player - computer == -1 || player - computer == 2)
//		printf("졌습니다!\n");
//	// WIN CASE( 가위(1), 보(3) / 바위(2), 가위(1) / 보(3), 바위(2) )
//	else if (player - computer == 1 || player - computer == -2)
//		printf("이겼습니다!\n");
//	// DRAW CASE ( 서로 같은 경우 )
//	else if (player == computer)
//		printf("비겼습니다!\n");
//}
//
//// 받은값(입력값)에 따른 가위, 바위, 보 출력
//void PrintString(int sel)
//{
//	switch (sel)
//	{
//	case 1:
//		printf("가위");
//		return;
//	case 2:
//		printf("바위");
//		return;
//	case 3:
//		printf("보");
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
//		printf("가위바위보(1.가위 2.바위 3.보)");
//
//		// 플레이어 선택
//		player = PlayerSelect();
//
//		// 3이외의 값 입력한 경우
//		if (player == -1)
//		{
//			printf("다시선택\n");
//			continue;
//		}
//
//		// 컴퓨터 선택
//		computer = ComputerSelect();
//
//		// 플레이어가 낸 값 출력
//		printf("플레이어 : ");
//		PrintString(player);
//		printf("\n");
//
//		// 컴퓨터가 낸 값 출력
//		printf("컴퓨터 : ");
//		PrintString(computer);
//		printf("\n");
//
//		// 결과 출력
//		Versus(player, computer);
//	}
//}