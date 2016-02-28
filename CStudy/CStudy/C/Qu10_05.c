//#include<stdio.h>
///*
//	2016-02-24
//	문제5
//	초를 입력받아서 00시간 00분 00초 형태로 출력하는 프로그램을
//	함수를 이용하여 작성하라
//	출력예 : 2458초 -> 0시간 41분 25초
//	3456초 -> 0시간 57분 36초
//*/
//
//int ConvertSecondToTime(int time)
//{
//	// 시간 : 3600초
//	int hour = time / 3600;
//	// 분 : 초를 60으로 나누고 60으로 나머지를 구한다(1~59분)
//	int minite = (time / 60)%60;
//	// 초 : 시간과 분을 구한 나머지
//	int second = (time % 60) % 60;
//	printf("%d초 -> %d시간 %d분 %d초\n", time, hour, minite, second);
//}
//void main()
//{
//	int second;
//	printf("초를 입력하세요 : ");
//	scanf("%d", &second);
//	ConvertSecondToTime(second);
//}