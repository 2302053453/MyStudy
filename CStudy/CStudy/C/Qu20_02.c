//#include<stdio.h>
///*
//	2016-02-26
//	������ �迭�� ���� �̸� ����ϴ� ���α׷��� �ۼ��ϰ��� �Ѵ�. �����̹迭�� ������ ����.
//	4 by 4 ũ���� �����̹迭
//	1  2    3	4 
//    12 13   14  5
//	11 16	15	6
//	10 9	8	7
//	����ڷκ��� ���� n�� �Է¹޾Ƽ� n by n ���̿� �ش��ϴ� ������ �迭�� ������ִ� ���α׷��� �ۼ��϶�.
//*/
//
//enum MODE { UP =0, DOWN = 1, LEFT =2, RIGHT =3};
//
//void main()
//{
//	int num, numArr[100][100] = { 0 }, count[4] = { 0 }, row, col, repeat, size;
//	printf("������ ��� ���̸� �Է��ϼ��� : ");
//	scanf("%d", &size);
//	col = size-1;
//	row = size-1;
//	num = 1;
//	repeat = size;
//
//	// n*n�� ���� ����Ҷ����� �ݺ�
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