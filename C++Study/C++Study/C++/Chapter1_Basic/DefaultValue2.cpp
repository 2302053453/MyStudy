//#include<iostream>
///*
//	2016-03-15
//	defaultValue예제
//*/
//// 함수선언(DefaultValue 포함)
//int Adder2(int num1 = 1, int num2 = 2);
//
//int main()
//{
//	std::cout << Adder2() << std::endl;
//	std::cout << Adder2(5) << std::endl;
//	std::cout << Adder2(3,5) << std::endl;
//	return 0;
//}
//
//// 함수의 정의에선 defaultValue를 명시하지 않아도 적용된다
//int Adder2(int num1, int num2)
//{
//	return num1 + num2;
//}