//#include<iostream>
///*
//	2016-03-15
//	오버로딩 예제
//	오버로딩 : 함수명,반환형은 같으나 매개변수가 다른것을 허용
//
//	C언어에서는 동일한 이름의 함수가 정의되는 것을 허용하지 않는다.
//
//	C++에서는 함수의 오버로딩을 허용한다.
//	- 함수호출 시 전달되는 인자를 통해서 호출하고자 하는 함수의 구분 가능
//	- 반환형은 함수호출 시, 호출되는 함수를 구분하는 기준이 될 수 없다.
//*/
//
//void MyFunc()
//{
//	std::cout << "MyFiunc() called" << std::endl;
//}
//// overloading
//void MyFunc(char c)
//{
//	std::cout << "MyFiunc(char c) called" << std::endl;
//}
//// overloading
//void MyFunc(int a, int b)
//{
//	std::cout << "MyFiunc(int a, int b) called" << std::endl;
//}
//
//int main()
//{
//	// 함수 오버로딩
//	MyFunc();
//	MyFunc('A');
//	MyFunc(1,2);
//	return 0;
//}