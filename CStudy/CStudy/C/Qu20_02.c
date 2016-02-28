//#include<stdio.h>
///*
//	2016-02-26
//	달팽이 배열을 만들어서 이를 출력하는 프로그램을 작성하고자 한다. 달팽이배열은 다음과 같다.
//	4 by 4 크기의 달팽이배열
//	1  2    3	4 
//    12 13   14  5
//	11 16	15	6
//	10 9	8	7
//	사용자로부터 숫자 n을 입력받아서 n by n 길이에 해당하는 달팽이 배열을 출력해주는 프로그램을 작성하라.
//*/
//
//enum MODE { UP =0, DOWN = 1, LEFT =2, RIGHT =3};
//
//void main()
//{
//	int num, numArr[100][100] = { 0 }, count[4] = { 0 }, row, col, repeat, size;
//	printf("달팽이 행렬 길이를 입력하세요 : ");
//	scanf("%d", &size);
//	col = size-1;
//	row = size-1;
//	num = 1;
//	repeat = size;
//
//	// n*n을 전부 출력할때까지 반복
//	while (num <= size*size)
//	{
//		int i;
//
//		// RIGHT
//		for (i = 0; i < repeat; i++)
//			numArr[count[RIGHT]][i + count[RIGHT]]=num++;
//		count[RIGHT]++;
//		repeat--;
//		// DOWN
//		for (i = 0; i < repeat; i++)
//			numArr[1+i+count[DOWN]][col -count[DOWN]] = num++;
//		count[DOWN]++;
//		// LEFT
//		for (i = 0; i < repeat; i++)
//			numArr[row -count[LEFT]][col -count[LEFT]-i-1] = num++;
//		count[LEFT]++;
//		repeat--;
//		//UP
//		for (i = 0; i < repeat; i++)
//			numArr[row -1-i-count[UP]][count[UP]] = num++;
//		count[UP]++;
//	}
//
//	for (int i = 0; i < size; i++)
//	{ 
//		for (int j = 0; j < size; j++)
//			printf("%4d", numArr[i][j]);
//		printf("\n");
//	}
//}