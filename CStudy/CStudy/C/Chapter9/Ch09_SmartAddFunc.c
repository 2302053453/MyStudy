//#include<stdio.h>
///*
//	2016-02-18
//	인자, 반환값이 있는 예제 프로그램
//*/
//
//// 인자전달(O), 반환 값(O)
//int Add(int num1, int num2) 
//{
//	return num1 + num2;
//}
//
//// 인자전달 (O), 반환 값(X)
//void ShowAddResult(int num)
//{
//	printf("덧셈결과 출력 : %d \n", num);
//}
//
//// 인자전달(X), 반환 값(O)
//int ReadNum(void)
//{
//	int num;
//	scanf("%d", &num);
//	return num;
//}
//
//// 인자전달(X), 반환 값(X)
//void HowToUseThisProg(void)
//{
//	printf("두 개의 정수를 입력하시면 덧셈결과가 출력됩니다. \n");
//	printf("자! 그럼 두 개의 정수를 입력하세요. \n");
//}
//
//int main_SmartAddFunc(void)
//{
//	int result, num1, num2;
//	HowToUseThisProg();
//	num1 = ReadNum();
//	num2 = ReadNum();
//	result = Add(num1,num2);
//	ShowAddResult(result);
//	return 0;
//}