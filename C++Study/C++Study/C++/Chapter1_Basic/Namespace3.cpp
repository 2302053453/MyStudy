//#include<iostream>
///*
//	2016-03-15
//	namespace 예제
//*/
//
//// std namespace를 선언하면 std:: 없이 cout,cin, endl을 사용할 수 있다.
//using namespace std;
//
//namespace my31
//{
//	void SimpleFunc();
//}
//
//namespace my31
//{
//	void PrettyFunc();
//}
//
//namespace my32
//{
//	void SimpleFunc();
//}
//
//int main()
//{
//	my31::SimpleFunc();
//	return 0;
//}
//
//void my31::SimpleFunc()
//{
//	cout << "my31이 정의한 함수" << endl;
//	PrettyFunc();	// 같은 namespace
//	my32::SimpleFunc();;	// 다른 namespace
//}
//
//void my31::PrettyFunc()
//{
//	cout << "So Pretty!" << endl;
//}
//
//void my32::SimpleFunc()
//{
//	cout << "my32가 정의한 함수" << endl;
//}