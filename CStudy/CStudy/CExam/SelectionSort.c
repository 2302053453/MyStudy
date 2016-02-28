//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
///*
//	2016-02-24
//	선택 정렬
//	각 루프마다 최대값(최소값)을 선택하여 마지막 자리에 위치시킨다
//	ex) 25431 -> 21435 -> 21345 -> 12345
//	시간복잡도 : O(n^2)
//*/
//
//enum ORDERING { ASC = 1, DSC = 2};
//
//void Swap(int *num1, int * num2)
//{
//	int temp = *num1;
//	*num1 = *num2;
//	*num2 = temp;
//}
//
//// 선택정렬
//void SelectionSort(int * arr, int length, int ordering)
//{
//	int value;
//
//	for (int i = 0; i < 9; i++)
//	{
//		value = 0;
//		// length범위 내의 배열에서 최대숫자를 구한다.
//		for (int j = 1; j < length; j++)
//		{
//			// 오름차순
//			if (ordering == ASC)  
//			{
//				if(arr[value] < arr[j])
//					// 최대값 변경
//					value = j;
//				printf("%d번 루프 : %d번까지의 중간결과 : 현재 최대값은 %d\n", i + 1, j, arr[value]);
//			}
//			// 내림차순
//			else if (ordering == DSC)  
//			{
//				if(arr[value] > arr[j])
//					// 최소값 변경
//					value = j;
//				printf("%d번 루프 : %d번까지의 중간결과 : 현재 최소값은 %d\n", i + 1, j, arr[value]);
//			}
//		}
//
//		// 배열범위 감소
//		length--;
//
//		// 최대값이 마지막값이랑 동일할경우 스왑을 하지않는다.
//		if (value != length)
//			Swap(&arr[value], &arr[length]);
//
//		printf("%d번 루프 결과 : ", i + 1);
//		for (int cnt = 0; cnt < 10; cnt++)
//			printf("%d ", arr[cnt]);
//		printf("\n");
//	}
//}
//
//// 난수생성
//void MakeRandomNumber(int * arr, int length)
//{
//	// 난수 생성
//	srand((int)time(NULL));
//	for (int i = 0; i < length; i++)
//	{
//		arr[i] = rand() % 100;
//
//		// 난수 중복체크
//		for (int j = 0; j < i;)
//			if (arr[i] == arr[j])
//				arr[i] = rand() % 100;
//			else
//				j++;
//	}
//}
//
//// 정렬방법 선택
//void SelectAscOrDsc(int * ordering)
//{
//	// 정렬방법 선택(1,2 이외의 선택을 할 경우 다시 입력하도록 처리
//	while (*ordering != ASC && *ordering != DSC)
//	{
//		printf("정렬방법을 선택해주세요.(내림차순:1, 오름차순:2) : ");
//		scanf("%d", ordering);
//
//		// 1,2이외의 다른수를 누른경우 메세지 출력
//		if (*ordering != ASC && *ordering != DSC)
//			printf("잘못누르셨습니다. 다시 선택해주세요\n");
//	}
//}
//
//void main()
//{
//	int arr[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int length=sizeof(arr) / sizeof(int);
//	int ordering=0;
//	
//	// 난수 생성
//	MakeRandomNumber(arr, length);
//
//	printf("정렬 전 숫자 : ");
//	for (int i = 0; i < length; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//
//	SelectAscOrDsc(&ordering);
//
//	SelectionSort(arr, length, ordering);
//
//	printf("최종 결과 : ");
//	for (int cnt = 0; cnt < 10; cnt++)
//		printf("%d ", arr[cnt]);
//	printf("\n");
//}