//#include<iostream>
///*
//	2016-03-15
//	namespace ����
//	������ :: �� ������ '�������� ������(scope resolution operator)'�� �ϸ�,
//	�� �̸��� �ǹ��ϵ��� �̸������� ������ �� ����ϴ� �������̴�.
//*/
//
//namespace My1
//{ 
//	void SimpleFunc()
//	{
//		std::cout << "my1�� ������ �Լ�" << std::endl;
//	}
//}
//
//namespace My2
//{
//	void SimpleFunc()
//	{
//		std::cout << "my2�� ������ �Լ�" << std::endl;
//	}
//}
//
//int main()
//{
//	// ���� �ٸ� namespace���� �Լ� ȣ��(���� �̸��� �޶� �ȴ�)
//	My1::SimpleFunc();
//	My2::SimpleFunc();
//	return 0;
//}