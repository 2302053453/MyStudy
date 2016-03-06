//#include<stdio.h>
///*
//	2016-02-24
//	문제3
//	현재 소유하고 있는 금액을 입력받아서 아래 물건을
//	잔돈을 남기지않고 최소 1개이상 구매하려면 어떻게 구매해야 하는가?
//	빵 : 500원
//	과자 : 700원
//	음료수 : 400원
//	단, 1600원 이상을 입력받으세요...
//*/
//
//void CheckMoneyIsZero(int snack, int bread, int drink, int money, int *isEnable)
//{
//	// 과자, 빵, 음료가 최소 각 1개씩 존재하며 그 합이 금액과 같을때 출력
//
//	if ( snack>=1 && bread >=1 && drink >= 1 &&
//		(snack * 700) + (bread * 500) + (drink * 400) == money)
//	{ 
//		printf("과자 %d개, 빵 %d개, 음료 %d개로 살 수 있습니다.\n", snack, bread, drink);
//		(*isEnable)++;
//	}
//}
//
//void main()
//{
//	int money, isEnable=0;
//	printf("금액을 입력해주세요 : ");
//	
//	do
//	{ 
//		scanf("%d", &money);
//		if(money<1600)
//			printf("1600원 이상 입력해야 합니다\n 다시 입력해주세요 : ");
//	} while (money < 1600);
//
//	for (int snack = 0; (snack*700) <= money; snack++)
//		for (int bread = 0; (snack*700)+(bread*500) <= money; bread++)
//			for (int drink = 0; (snack * 700) + (bread * 500) + (drink * 400) <= money; drink++)
//				CheckMoneyIsZero(snack, bread, drink, money, &isEnable);
//
//	// 만일 조건을 만족하는 구매방법이 없을때 불가메세지 출력
//	if (isEnable == 0)
//		printf("해당 금액으로 잔돈없이 모든 제품을 각 하나씩 살 수 있는 방법은 없습니다\n");
//
//}
//
