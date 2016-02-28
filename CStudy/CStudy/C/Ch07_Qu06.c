//#include<stdio.h>
///*
//	문제6(Qu07-06.c)
//	사용자로부터 2개의 정수를 입력받는다. 가령 2와 6을 입력받았다면
//	2+3+4+5+6을 구하는 프로그램을 작성하라.
//	단 6과 2를 입력받는다면 6+5+4+3+2를 구해야 한다.
//*/
//
//int main(void)
//{
//	int startNum, endNum, num, sum=0;
//	
//	char sign = '+';
//
//	// 계산종료 체크값 선언
//	int isEnd = 0;
//
//	printf("합의 시작값 : ");
//	scanf("%d", &startNum);
//	
//	printf("합의 마지막값 : ");
//	scanf("%d", &endNum);
//
//	// num의 시작값 : startNum
//	num = startNum;
//
//	while (isEnd == 0)
//	{
//		// 숫자를 합계에 더한다
//		sum += num;
//		printf("%d",num);
//
//		// 더한숫자가 endNum과 같다 - 종료
//		isEnd = num == endNum ? 1 : 0;
//		
//		// 시작숫자가 크면 endNum까지 감소, 작으면 증가시킨다.
//		startNum > endNum ? num-- : num++;
//		
//		// 마지막 루프에 따른 수학기호 지정
//		sign = isEnd == 1 ? '=' : '+';
//		
//		printf("%c",sign);
//	}
//
//	printf("%d \n", sum);
//
//	return 0;
//}