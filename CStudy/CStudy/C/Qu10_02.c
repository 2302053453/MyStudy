//#include<stdio.h>
///*
//	2016-02-24
//	문제2
//	두개의 정수를 입력받아서 최대공약수를 구하는 프로그램을 작성하라
//	최대공약수란 두 수의 공통약수중에 가장 큰 값을 말한다.
//	2|   12   18
//	-----------------
//	3|    6      9
//	-----------------
//	2      3
//	좌측의 2 와 3을 곱하면 최대공약수가 된다.
//*/
//
//// 최대공약수를 구하는 함수
//int GetGCD(int num1, int num2, int value)
//{
//	// 둘중의 한수보다 크지않을때까지
//	for (int i = 2; i <= num1 || i <= num2; i++)
//	{
//		// 둘다 나눠지는 수 = 공약수
//		if (num1 % i == 0 && num2 % i == 0)
//		{
//			// 최대공약수 = 공통된 공약수들의 곱이라고도 볼 수 있다.
//			// 재귀함수처리
//			value = GetGCD(num1/i, num2/i, value*i);
//			break;
//		}
//	}
//	return value;
//}
//
//void main()
//{
//	int num1, num2, value = 1;
//	
//	printf("최대공약수를 구할 정수 2개를 입력 : ");
//	scanf("%d %d", &num1, &num2);
//
//	value = GetGCD(num1, num2, value);
//
//	printf("%d와 %d의 최대공약수 : %d\n", num1, num2, value);
//
//}