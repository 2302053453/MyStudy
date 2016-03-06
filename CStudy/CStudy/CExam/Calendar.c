//#include<stdio.h>
///*
//	2016-03-02
//	2016년 켈린더를 출력하시오
//	2월은 29일까지 있는걸로 간주함(2016년은 2월이 29일까지 있음)
//	2016년1월1일은 금요일
//	본인의 생일은 날자 대신에 “생일” 이라고 표시한다.
//
//	EX) 
//	1월
//	SUN MON TUE WED THU FRI SAT
//	_	_	_	_	_	1	2
//	3	4	5	6	7	8	9
//	10	11	12	13	14	15	16
//	17	18	19	20	21	22	23
//	24	25	26	27	28	29	30
//	31
//*/
//
//enum DAYS { FRI  = 5};
//enum BIRTH { BIRTHMON = 11, BIRTHDAY = 10 };
//
//// 해당 달의 마지막 날자를 반환하는 함수
//void GetMaxDayOfMonth(int month, int *maxDayOfMonth)
//{
//	// 2월 : 윤년은 29일(4년마다 반복), 아니면 28일
//	// 8월이전  : 홀수는 31일, 짝수는 30일
//	// 8월이후  : 홀수는 30일, 짝수는 31일
//	if(month == 2)
//		*maxDayOfMonth = 2016 % 4 == 0 ? 29 : 28;
//	else if (month < 8)
//		*maxDayOfMonth = month % 2 == 1 ? 31 : 30;
//	else 
//		*maxDayOfMonth = month % 2 == 0 ? 31 : 30;
//}
//
//// 요일명을 출력하는 함수
//void PrintDayList()
//{
//	// 요일이름
//	char * dayList[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
//
//	// 요일의 수
//	int dayCount = 7;
//
//	for (int day = 0; day < dayCount; day++)
//		printf("%4s ", dayList[day]);
//	printf("\n");
//}
//
//// 달의 해당하는 일을 출력하는 함수
//void PrintDayOfMonth(int startIdx, int maxDayOfMonth, int month)
//{
//	int dayIdx = 0;
//
//	// 시작이전에는 '-' 출력
//	// 시작일 이후에는 각 날자에 맞는 일을 출력
//	for (int day = 0; dayIdx < maxDayOfMonth; day++)
//	{
//		if(month == BIRTHMON && dayIdx == BIRTHDAY)
//		{ 
//			printf("%4s ", "생일");
//			dayIdx++;
//		}
//		else if (day >= startIdx)
//			printf("%4d ", ++dayIdx);
//		else if (day < startIdx)
//			printf("%4c ", '_');
//
//		if (day % 7 == 6 && dayIdx <maxDayOfMonth)
//			printf("\n");
//	}
//}
//
//void main()
//{
//	// 2016년1월1일은 금요일 => 시작부분
//	int startIdx = FRI;
//	
//	// 구할년도 
//	int year = 2016;
//
//	// 각 달의 마지막 날
//	int maxDayOfMonth;
//	
//	// 각 달의 수
//	int monthCount = 12;
//
//	for (int i = 0; i < monthCount; i++)
//	{
//		// 월 출력
//		printf("%d월\n", i + 1);
//
//		// 각 달의 마지막 날짜 초기화
//		GetMaxDayOfMonth(i+1, &maxDayOfMonth);
//
//		// 요일 출력
//		PrintDayList();
//
//		// 일 출력
//		PrintDayOfMonth(startIdx, maxDayOfMonth, (i+1));
//		
//		// 다음 달 시작일 초기화
//		startIdx = (startIdx + maxDayOfMonth) % 7;
//
//		printf("\n");
//
//	}
//}