//#include<iostream>
//using namespace std;
///*
//	2016-03-16
//	다중상속 예제
//*/
//
//class Phone
//{
//public:
//	void power()
//	{
//		cout << "Phone : called " << endl;
//	}
//};
//
//class Printer
//{
//public:
//	void power()
//	{
//		cout << "printer : called" << endl;
//	}
//
//};
//
//// Phone과 Printer 2개를 상속 (다중상속)
//// 다중상속의 경우 문제가 될 소지가 있으니 주의해서 쓸 것(직접적인 클래스 다중상속이 아닌 인터페이스와 가상함수를 사용(?) )
//class Fax : public Phone, public Printer
//{
//public:
//	void power()
//	{
//		cout << " Fax : called" << endl;
//	}
//};
//
//int main()
//{
//	Fax fax;
//	// 다중상속을 받아 부모클래스의 같은이름 함수를 호출하려면
//	// 어느클래스인지 지정해 줘야 한다.
//	fax.Phone::power();
//	fax.Printer::power(); 
//	fax.power();
//
//	Phone p = fax;
//	Printer pr = fax;
//
//	return 0;
//}