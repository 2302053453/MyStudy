//#include<stdio.h>
///*	
//	2016-02-17
//	문제4(Qu07-04.c)
//	아래의 출력을 완성하라.(while, for 문을 동시에 사용해야 한다)
//		*
//		O*
//		OO*
//		OOO*
//		OOOO*
//	2016-02-18
//	심화
//	양의 정수를 입력받아 피라미드 형태로 출력
//	 ex) 3 입력시 
//	  *
//	 O *
//	O O *
//   O O O *
//*/
//
//int main(void)
//{
//	int height = 0, num;
//
//	printf("높이 입력 : ");
//	scanf("%d", &num);
//
//
//	// while 반복문 사용
//	while (height < num)
//	{
//		// 심화 문제 추가(앞부분 공백 출력)
//		for (int i = 0; i < num - height; i++)
//			printf(" ");
//
//		// for 반복문 사용
//		for (int i = 0; i < height; i++)
//			printf("O ");
//		// printf("O"); -> 기존 문제1
//
//		printf("*\n");
//		height++;
//	}
//
//	return 0;
//}