//#include<stdio.h>
///*
//	문제3(Qu08-03.c)
//	학생의 전체 평균점수에 대한 학점을 출력하는 프로그램을 작성하라.
//	실행시 국어, 영어, 수학의 점수를 차례로 입력받은후 평균을 구한 후
//	90점이상 A, 80점이상 B, 70점이상 C, 50점이상 D, 그 미만이면 F를 출력한다.
//*/
//
//int main(void)
//{
//	int korScore, engScore, mathScore,average;
//
//	printf("국어점수 : ");
//	scanf("%d", &korScore);
//	printf("영어점수 : ");
//	scanf("%d", &engScore);
//	printf("수학점수 : ");
//	scanf("%d", &mathScore);
//
//	// 평군 소수점이하 내림처리
//	average = ( korScore + engScore + mathScore ) / 3;
//
//	// average 값을 10으로 나눈 값으로 판별
//	switch ((average / 10))
//	{
//		// 90이상 =  9 or 10
//		case 9:
//		case 10:
//			printf("평균 : %d \n등급 : A\n", average);
//			break;
//		case 8:
//			printf("평균 : %d \n등급 : B\n", average);
//			break;
//		case 7:
//			printf("평균 : %d \n등급 : C\n", average);
//			break;
//		// 50점이상 70미만 = 5 or 6
//		case 6:
//		case 5:
//			printf("평균 : %d \n등급 : D\n", average);
//			break;
//		// 그 이외의 경우 = 50미만
//		default:
//			printf("평균 : %d \n등급 : F\n", average);
//			break;
//	}
//	return 0;
//
//}