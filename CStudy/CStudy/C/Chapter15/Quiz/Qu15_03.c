//#include<stdio.h>
///*
//	2016-02-26
//	문제3
//	길이가 10인 배열을 선언한후 총 10개의 정수를 입력받는다.
//	단 홀수는 배열의 앞에서 부터 채워나가고 짝수는 배열의 끝에서부터 채워나간다.
//	출력예시) 총 10개의 정수를 입력하시오.
//	1 2 3 4 5 6 7 8 9 10
//	결과 : 1 3 5 7 9 10 8 6 4 2
//*/
//
//void main()
//{
//	int numArr[10], inputArr[10];
//	int minIdx = 0, maxIdx = 9;
//
//		printf("총 10개의 정수를 입력하시오 : ");
//		scanf(	"%d %d %d %d %d %d %d %d %d %d",
//				&inputArr[0], &inputArr[1], &inputArr[2], &inputArr[3], &inputArr[4],
//				&inputArr[5], &inputArr[6], &inputArr[7], &inputArr[8], &inputArr[9]
//			);
//
//		// 짝수는 끝부터, 홀수는 처음부터 배열에 삽입
//		for (int i = 0; i < 10; i++)
//		{
//			if (inputArr[i] % 2 == 0)
//			{
//				numArr[maxIdx] = inputArr[i];
//				maxIdx--;
//			}
//			else
//			{
//				numArr[minIdx] = inputArr[i];
//				minIdx++;
//			}
//		}
//
//		for (int i = 0; i < 10; i++)
//			printf("%d ", numArr[i]);
//
//		printf("\n");
//
//}