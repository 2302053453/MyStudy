//#include<stdio.h>
//
///*
//	2016-02-25
//	문제3
//	성적관리 프로그램을 작성한다.
//	국어, 영어, 수학, 국사 4과목이고 학생은 대중, 무현, 재인, 청래 4명이다. 
//	4 by 4 배열을 선언하고 사용자로부터 4사람의 4과목 점수를 입력받아 
//	다음의 형태로 값을 저장하고 총점을 구하는 프로그램을 작성하라.
//	출력예)
//	구분	대중		 무현	재인		청래		총점
//	국어	 100	  99	  98	  97	 394
//	영어	  90									
//	수학  80
//	국사	  99
//	총점  369							1200
//*/
//
//void main()
//{
//	int score[4][4], sumScore;
//	
//	// 과목별 합계를 저장하는 배열
//	int subjectScore[4] = { 0,0,0,0 };
//	
//	// 학생이럼을 저장하는 배열
//	char * name[4] = { "대중", "무현", "재인", "청래"};
//	
//	// 과목별 이름 저장하는 배열
//	char * subject[5] = { "국어", "영어", "수학", "국사", "총점"};
//
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%s의 %s %s %s %s 점수 : ",name[i],subject[0],subject[1],subject[2],subject[3]);
//		scanf("%d %d %d %d", &score[i][0], &score[i][1], &score[i][2], &score[i][3]);
//	}
//	// 첫줄(학생이름) 출력
//	printf("구분 %5s %5s %5s %5s %5s\n", name[0], name[1], name[2], name[3], subject[4]);
//
//	for (int i = 0; i < 5; i++)
//	{ 
//		sumScore = 0;
//		printf("%s ", subject[i]);
//
//		for (int j = 0; j < 4; j++)
//		{
//			// i가 4 -> 과목별 합계 출력
//			if(i == 4)
//			{
//				printf("%5d ", subjectScore[j]);
//				sumScore += subjectScore[j];
//			}
//			else
//			{ 
//				printf("%5d ", score[i][j]);		
//				sumScore += score[i][j];
//				// 과목별 합계
//				subjectScore[j] += score[i][j];
//			}
//		}
//		// 합계 출력
//		printf("%5d\n", sumScore);
//	}
//}
//
