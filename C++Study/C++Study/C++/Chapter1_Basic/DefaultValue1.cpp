//#include<iostream>
///*
//	2016-03-15
//	디폴트값 예제
//*/
//
//int Adder1(int num1 = 1, int num2 = 2)
//{
//	return num1 + num2;
//}
//
//int Adder1(int num1 = 1)
//{
//	return num1;
//}
//
//
//int Adder1()
//{
//	return 7;
//}
//
//int main()
//{
//	// default값이 정의되어있는 adder(int num1)인지
//	// Adder1()인지 알 수가 없다
//	std::cout << Adder1() << std::endl;
//
//	// Adder1(int num1, int num2)인지 Adder(int num1)인지 구분 불가
//	std::cout << Adder1(5) << std::endl;
//
//	std::cout << Adder1(3,4) << std::endl;
//}