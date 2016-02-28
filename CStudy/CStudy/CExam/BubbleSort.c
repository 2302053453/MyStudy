//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	 2016-02-23
//	 BubbleSort 프로그램
//	 각 루프에서 현재위치와 다음위치의 크기를 비교하여 스왑시켜서 정렬
//	 ex) 1번루프 : 52143 -> 25143 -> 21543 -> 21453 -> 21435
//		 2번루프 : 21435 -> 12435
//		 3번루프 : 12435 -> 12345 
//		 END
//*/
//
//void Swap(int * num1, int * num2)
//{
//	int temp = *num1;
//	*num1 = *num2;
//	*num2 = temp;
//}
//
//void BubbleSort(int * num,int size, int isASC)
//{
//	// 각 숫자 횟수만큼 반복
//	for (int i = 0; i < size; i++)
//	{
//		// 정렬된 수를 제외한 나머지 수에 대한 반복
//		for (int j = 0; j < 9 - i; j++)
//		{
//			// 오름차순
//			if (isASC == 2 && num[j] > num[j + 1])
//				Swap(&num[j], &num[j + 1]);
//
//			// 내림차순
//			else if (isASC == 1 && num[j] < num[j + 1])
//				Swap(&num[j], &num[j + 1]);
//
//			// 각 과정 출력
//			printf("%d번째 루프, %d번째  : ", i+1, j+1);
//			for (int i = 0; i < 10; i++)
//				printf("%d ", num[i]);
//			printf("\n");
//		}
//	}
//}
//
//
//void main()
//{
//	
//
//	int size;
//	int num[10];
//	int isASC = 0;
//
//	printf("BubbleSort 프로그램입니다. \n");
//	
	//// 정렬방법 선택(1,2 이외의 선택을 할 경우 다시 입력하도록 처리
	//while (isASC != 1 && isASC != 2)
	//{
	//	printf("정렬방법을 선택해주세요.(내림차순:1, 오름차순:2) : ");
	//	scanf("%d", &isASC);

	//	// 1,2이외의 다른수를 누른경우 메세지 출력
	//	if (isASC != 1 && isASC != 2)
	//		printf("잘못누르셨습니다. 다시 선택해주세요\n");
	//}
//
//	// 배열의 size 초기화
//	size = sizeof(num) / sizeof(int);
//
//	// 난수 생성
//	srand((int)time(NULL));
//	for (int i = 0; i < size; i++)
//	{ 
//		num[i] = rand() % 100;
//
//		// 난수 중복체크
//		for (int j = 0; j < i;)
//			if (num[i] == num[j])
//				num[i] = rand() % 100;
//			else
//				j++;
//	}
//	
//	// 정렬전의 숫자 출력
//	printf("초기숫자 : ");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", num[i]);
//	printf("\n");
//
//	// BubbleSort
//	BubbleSort(num, size, isASC);
//
//	// 정렬후의 숫자 출력
//	printf("정렬결과 : ");
//	for (int i = 0; i < 10; i++)
//		printf("%d ", num[i]);
//	printf("\n");
//}