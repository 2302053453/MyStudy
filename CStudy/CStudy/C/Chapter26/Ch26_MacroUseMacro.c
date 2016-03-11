//#include<stdio.h>
//#define PI	3.14
//// 두 줄로 Macro를 정의
////  \ 를 사용하면 밑의 줄까지 정의가 이어진다
//#define PRODUCT(X,Y) \
//((X)*(Y))
//// Macro에서 Macro를 사용
//#define CIRCLE_AREA(R)	(PRODUCT((R) , (R))*PI)
//
///*
//	2016-03-10
//	Macro에서 Macro를 사용하는 예제
//*/
//
//int main()
//{
//	double rad = 2.1;
//	printf("반지름 %g인 원의 넓이 : %g \n", rad, CIRCLE_AREA(rad) );
//	return 0;
//}