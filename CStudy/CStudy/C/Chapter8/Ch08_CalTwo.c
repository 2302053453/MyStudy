//#include<stdio.h>
///*
//	2016-02-17
//	if - else if - else 예제 프로그램
//*/
//
//int main(void)
//{
//	int opt;
//	double num1, num2;
//	double result=0;
//	printf("1.덧셈 2.뺼셈 3.곱셈 4.나눗셈 \n");
//	printf("선택 : ");
//	scanf("%d", &opt);
//	printf("두 개의 실수 입력: ");
//	scanf("%lf %lf",&num1, &num2);
//
//	if (opt == 1)
//		result = num1 + num2;
//	else if (opt == 2)
//		result = num1 - num2;
//	else if (opt == 3)
//		result = num1 * num2;
//	else if (opt == 4)
//		result = num1 / num2;
//	else
//		printf("잘못된 입력으로 result가 정상적으로 표시되지 않습니다. \n");
//	
//	printf("결과 : %f \n", result);
//
//	return 0;
//}