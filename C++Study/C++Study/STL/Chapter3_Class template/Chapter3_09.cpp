//#include<iostream>
//using namespace std;
///*
//	2016-03-03
//	클래스 탬플릿 부분 전문화 
//*/
//
//template<typename T>
//class  TestP
//{
//public:
//	void Add()
//	{
//		cout << "일반 탬플릿을 사용했습니다." << endl;
//	}
//private:
//};
//
//// T를 T*로 부분 전문화
//template<typename T>
//class  TestP<T*>
//{
//public:
//	void Add()
//	{
//		cout << "포인터를 사용한 부분전문화 탬플릿을 사용했습니다." << endl;
//	}
//private:
//};
//
//
//
//
//
//void main()
//{
//	TestP<int> test1;
//	test1.Add();
//
//	TestP<int*> test2;
//	test2.Add();
//}