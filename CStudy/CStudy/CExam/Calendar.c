//#include<stdio.h>
///*
//	2016-03-02
//	2016�� �̸����� ����Ͻÿ�
//	2���� 29�ϱ��� �ִ°ɷ� ������(2016���� 2���� 29�ϱ��� ����)
//	2016��1��1���� �ݿ���
//	������ ������ ���� ��ſ� �����ϡ� �̶�� ǥ���Ѵ�.
//
//	EX) 
//	1��
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
//// �ش� ���� ������ ���ڸ� ��ȯ�ϴ� �Լ�
//void GetMaxDayOfMonth(int month, int *maxDayOfMonth)
//{
//	// 2�� : ������ 29��(4�⸶�� �ݺ�), �ƴϸ� 28��
//	// 8������  : Ȧ���� 31��, ¦���� 30��
//	// 8������  : Ȧ���� 30��, ¦���� 31��
//	if(month == 2)
//		*maxDayOfMonth = 2016 % 4 == 0 ? 29 : 28;
//	else if (month < 8)
//		*maxDayOfMonth = month % 2 == 1 ? 31 : 30;
//	else 
//		*maxDayOfMonth = month % 2 == 0 ? 31 : 30;
//}
//
//// ���ϸ��� ����ϴ� �Լ�
//void PrintDayList()
//{
//	// �����̸�
//	char * dayList[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
//
//	// ������ ��
//	int dayCount = 7;
//
//	for (int day = 0; day < dayCount; day++)
//		printf("%4s ", dayList[day]);
//	printf("\n");
//}
//
//// ���� �ش��ϴ� ���� ����ϴ� �Լ�
//void PrintDayOfMonth(int startIdx, int maxDayOfMonth, int month)
//{
//	int dayIdx = 0;
//
//	// ������������ '-' ���
//	// ������ ���Ŀ��� �� ���ڿ� �´� ���� ���
//	for (int day = 0; dayIdx < maxDayOfMonth; day++)
//	{
//		if(month == BIRTHMON && dayIdx == BIRTHDAY)
//		{ 
//			printf("%4s ", "����");
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
//	// 2016��1��1���� �ݿ��� => ���ۺκ�
//	int startIdx = FRI;
//	
//	// ���ҳ⵵ 
//	int year = 2016;
//
//	// �� ���� ������ ��
//	int maxDayOfMonth;
//	
//	// �� ���� ��
//	int monthCount = 12;
//
//	for (int i = 0; i < monthCount; i++)
//	{
//		// �� ���
//		printf("%d��\n", i + 1);
//
//		// �� ���� ������ ��¥ �ʱ�ȭ
//		GetMaxDayOfMonth(i+1, &maxDayOfMonth);
//
//		// ���� ���
//		PrintDayList();
//
//		// �� ���
//		PrintDayOfMonth(startIdx, maxDayOfMonth, (i+1));
//		
//		// ���� �� ������ �ʱ�ȭ
//		startIdx = (startIdx + maxDayOfMonth) % 7;
//
//		printf("\n");
//
//	}
//}