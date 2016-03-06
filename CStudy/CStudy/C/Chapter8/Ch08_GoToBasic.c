//#include<stdio.h>
///*
//	2016-02-18
//	goto 에제 프로그램
//*/
//
//int main(void)
//{
//	int num;
//	printf("자연수 입력: ");
//	scanf("%d", &num);
//
//	// 입력에 따른 goto문 선언
//	if (num == 1)
//		goto ONE;
//	else if (num == 2)
//		goto TWO;
//	else
//		goto OTHER;
//
//// 입력에 따른 goto문 분기
//ONE:
//	printf("1을 입력하셨습니다 \n");
//	goto END;
//TWO:
//	printf("2을 입력하셨습니다 \n");
//	goto END;
//OTHER:
//	printf("3 혹은 다른값을 입력하셨군요! \n");
//	goto END;
//END:
//	return 0;
//
//}