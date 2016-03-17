//#include<iostream>
///*
//2016-03-15
//지역변수 예제
//지역변수 : 해당 함수에서만 사용된다
//전역변수 : 프로그램 전체적으로 사용된다
//지역변수 -> 메모리영역에서 stack에 저장 (해당 함수가 끝나면 바로 해제)
//전역변수+static -> 메모리영역에서 데이터영역에 저장 ( 해당 프로그램이 끝나아 해제)
//*/
//
//int main(void)
//{
//	int val1, val2, result = 0;
//	std::cout << "두 개의 숫자입력 : ";
//	std::cin >> val1 >> val2;
//	if (val1 < val2)
//	{
//		for (int i = val1 + 1; i < val2; ++i)
//			result += i;
//	}
//	else
//	{
//		for (int i = val2 + 1; i < val1; ++i)
//			result += i;
//	}
//
//	std::cout << "두 수 사이의 정수 합 : " << result << std::endl;
//	return 0;
//}