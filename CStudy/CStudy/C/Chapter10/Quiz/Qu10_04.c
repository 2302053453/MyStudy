//#include<stdio.h>
///*
//	2016-02-24
//	문제4
//	10개의 소수를 출력하는 프로그램을 작성하시오.
//	소수란 1과 자기자신만으로 나눠지는 수를 말한다.
//	출력예 : 2, 3, 5, 7, 11 .... 등
//*/
//
//void main()
//{
//	int count=0, num;
//	
//	// 2부터 시작
//	for (int i = 2;; i++)
//	{
//		num = i;
//		
//		// 1과 자지자신 이외의 수로 나누어지는지 확인 
//		for (int j = 2; j < i; j++)
//		{ 
//			// 나누어지면 루프를 빠져나온다
//			if (num % j == 0)
//			{ 
//				num /= j;
//				break;
//			}
//		}
//
//		// 루프결과 루프돌기전과 값이 동일하면 소수
//		if (num == i)
//		{
//			printf("%d",num);
//			count++;
//			// 콤마 찍기
//			if (count < 10)
//				printf(", ");
//		}
//		
//		// 소수가 10개 출력되었는지 확인
//		if (count == 10)
//		{
//			printf("\n");
//			break;
//		}
//	}
//}