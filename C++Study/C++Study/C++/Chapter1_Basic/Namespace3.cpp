//#include<iostream>
///*
//	2016-03-15
//	namespace ����
//*/
//
//// std namespace�� �����ϸ� std:: ���� cout,cin, endl�� ����� �� �ִ�.
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
//	cout << "my31�� ������ �Լ�" << endl;
//	PrettyFunc();	// ���� namespace
//	my32::SimpleFunc();;	// �ٸ� namespace
//}
//
//void my31::PrettyFunc()
//{
//	cout << "So Pretty!" << endl;
//}
//
//void my32::SimpleFunc()
//{
//	cout << "my32�� ������ �Լ�" << endl;
//}