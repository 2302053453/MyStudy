//#include<iostream>
//using namespace std;
///*
//	2016-03-03
//	Ŭ���� ���ø� �κ� ����ȭ 
//*/
//
//template<typename T>
//class  TestP
//{
//public:
//	void Add()
//	{
//		cout << "�Ϲ� ���ø��� ����߽��ϴ�." << endl;
//	}
//private:
//};
//
//// T�� T*�� �κ� ����ȭ
//template<typename T>
//class  TestP<T*>
//{
//public:
//	void Add()
//	{
//		cout << "�����͸� ����� �κ�����ȭ ���ø��� ����߽��ϴ�." << endl;
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