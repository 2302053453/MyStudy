//#include<stdio.h>
///*
//	2016-02-23
//	포인터(배열)를 인자로 넘기는 예제 프로그램
//*/
//
//void ShowArayElem(int * param, int len)
//{
//	int i;
//	for (i = 0; i < len; i++)
//		printf("%d ", param[i]);
//	printf("\n");
//}
//
//int main()
//{
//	int arr1[3] = { 1,2,3 };
//	int arr2[5] = { 4,5,6,7,8 };
//
//	// C에서는 배열을 직접 넘길수 없으므로 포인터의 형태로 넘긴다.
//	// 함수의 내부에서는 배열의 길이를 구할 수 없으므로 미리 구해서 넘겨준다.
//	ShowArayElem(arr1, sizeof(arr1) / sizeof(int));
//	ShowArayElem(arr2, sizeof(arr2) / sizeof(int));
//	return 0;
//}