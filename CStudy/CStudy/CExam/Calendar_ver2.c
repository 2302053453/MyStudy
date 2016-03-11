//#include<stdio.h>
///*
//	2016-03-07
//	년도를 입력받아 해당 년도의 달력을 출력하시오
//	윤년을 고려할 것
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
//enum DAYS { FRI = 5 };
//enum BIRTH { BIRTHMON = 11, BIRTHDAY = 10 };
//
//// 해당 달의 마지막 날자를 반환하는 함수
//void GetMaxDayOfMonth(int month, int *maxDayOfMonth, int year)
//{
//	// 2월 : 윤년은 29일(4년마다 반복), 아니면 28일
//	// 8월이전  : 홀수는 31일, 짝수는 30일
//	// 8월이후  : 홀수는 30일, 짝수는 31일
//	if (month == 2)
//		*maxDayOfMonth = year % 4 == 0 ? 29 : 28;
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
//		if (month == BIRTHMON && dayIdx == BIRTHDAY)
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
//	// 구할년도
//	int year;
//	// 각 달의 마지막 날
//	int maxDayOfMonth;
//	// 각 달의 수
//	int monthCount = 12;
//	// 기준년도(2016년)
//	int startYear = 2016;
//	// 1년의 수 
//	int daysOfYear;
//
//	printf("달력을 볼 년도를 입력해주세요 : ");
//	scanf("%d", &year);
//
//	while (1)
//	{
//		if (startYear == year)
//		{
//
//			for (int i = 0; i < monthCount; i++)
//			{
//				// 각 달의 마지막 날짜 초기화
//				GetMaxDayOfMonth(i + 1, &maxDayOfMonth, startYear);
//
//				// 월 출력
//				printf("%d년 %d월\n", startYear, i + 1);
//				// 요일 출력
//				PrintDayList();
//				// 일 출력
//				PrintDayOfMonth(startIdx, maxDayOfMonth, (i + 1));
//				printf("\n");
//				// 다음 달 시작일 초기화
//				startIdx = (startIdx + maxDayOfMonth) % 7;
//			}
//			break;
//		}
//		else
//		{
//			// 년도별 시작일 초기화
//			daysOfYear = startYear % 4 == 0 ? 366 : 365;
//			startIdx = startYear < year ? (startIdx + daysOfYear) % 7 : (daysOfYear - startIdx) % 7;
//			startYear < year ? startYear++ : startYear--;
//		}
//	}
//}
//
//
//
//
//
