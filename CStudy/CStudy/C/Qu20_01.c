//#include<stdio.h>
//#include<math.h>
///*
//	2016-02-26
//	문제1
//	길이가 4 by 4인 int형 배열을 선언하고 순서대로 1, 2, 3 … 정수를 입력하여 초기화하자.
//	그리고 배열의 요소들을 오른쪽 방향으로 90º씩 이동시켜서 그 결과를 출력하는 프로그램을 작성하라.
//	추가적으로 횟수를 입력받아 그 횟수만큼 회전하는 과정을 보여주어야 한다.
//	1  2  3  4			13  9   5  1
//	5  6  7  8   ->		14  10  6  2
//	9  10 11 12			15  11  7  3
//	13 14 15 16			16  12  8  4
//	*/
//
//void main()
//{
//	int numArr[4][4], numArr2[4][4], rotationCount, value =1;
//
//	printf("회전 횟수를 입력하세요 : ");
//	scanf("%d", &rotationCount);
//
//	// 초기 배열 설정
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++)
//		{
//			numArr[i][j] = value++;
//			// 배열복사
//			numArr2[i][j] = numArr[i][j];
//		}
//
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			printf("%2d ", numArr[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//
//	// 입력횟수 만큼 회전
//	while (rotationCount > 0)
//	{
//		for (int i = 0; i < 4; i++)	
//			for (int j = 0; j < 4; j++)
//			{
//				/*
//					값의 변화 : 0,0 -> 3,0, 3,0 -> 3,3, 3,3 -> 0,3, 0,3->0,0 ...
//					이런식으로 행은 (열의크기 -3)의 절대값이고
//					열은 행값이 된다.
//				*/
//				value = (int)sqrt((double)(j - 3)*(double)(j - 3));
//				numArr[i][j] = numArr2[value][i];
//			}
//
//		for (int i = 0; i < 4; i++)
//		{ 
//			for (int j = 0; j < 4; j++)
//			{ 
//				printf("%2d ", numArr[i][j]);
//				// 변경된 배열 복사
//				numArr2[i][j] = numArr[i][j];
//			}
//			printf("\n");
//		}
//
//		printf("\n");
//		rotationCount--;
//	}
//
//
//}