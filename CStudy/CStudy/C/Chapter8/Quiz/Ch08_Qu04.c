//#include<stdio.h>
///*
//	2016-02-18
//	문제4(Qu08-04.c)
//	구구단을 출력하되 짝수단만 출력하도록 프로그램을 작성하라.
//	단, 2단은 2*2까지만, 4단은 4*4까지만....8단은 8*8까지만 출력해야 한다.
//	여기서는 continue, break 문을 이용해서 해결해야 한다.
//*/
//int main(void)
//{
//	int num, i=0;
//	printf("몇 단? : ");
//	scanf("%d", &num);
//
//	while (1)
//	{
//		i++;
//		printf("%d * %d = %d\n", num, i, num*i);
//		
//		// 곱 수가 단의 수보다 진행하지않으면 loop 시작으로 돌아가서 다시 수행
//		if (i < num)
//			continue;
//		// 곱 수가 단의 수와 같거나 크면 loop 종료
//		else if (i >= num)
//			break;
//	}
//
//	return 0;
//}