//#include<iostream>
///*
//	2016-03-15
//	namespace 예제
//	연산자 :: 을 가리켜 '범위지정 연산자(scope resolution operator)'라 하며,
//	그 이름이 의미하듯이 이름공간을 지정할 때 사용하는 연산자이다.
//*/
//
//namespace My1
//{ 
//	void SimpleFunc()
//	{
//		std::cout << "my1이 정의한 함수" << std::endl;
//	}
//}
//
//namespace My2
//{
//	void SimpleFunc()
//	{
//		std::cout << "my2가 정의한 함수" << std::endl;
//	}
//}
//
//int main()
//{
//	// 서로 다른 namespace에서 함수 호출(서로 이름이 달라도 된다)
//	My1::SimpleFunc();
//	My2::SimpleFunc();
//	return 0;
//}