//#include<iostream>
//using namespace std;
//
///*
//	2016-03-16
//	��ӿ����� �������� ����
//*/
//
//class Food
//{
//private:
//	int price1;
//protected:
//	int price2;
//public:
//	int price3;
//
//	Food()
//	{
//		price1 = 100;
//		price2 = 200;
//		price3 = 300;
//	}
//};
//
//class Fruit : public Food
//{
//public:
//	void print1()
//	{
//		// private �� ���� �ش� Ŭ���������� ������ �����ϴ�
//		// cout << "price1 : " << price1 << endl;
//	}
//
//	void print2()
//	{
//		// pritected�� �ش� Ŭ������ ��ӹ��� Ŭ�������� ������ �����ϴ�.
//		cout << "price2 : " << price2 << endl;
//	}
//
//	void print3()
//	{
//		// public�� ��𿡼��� ������ �����ϴ�.
//		cout << "price3 : " << price3 << endl;
//	}
//
//};
//
//int main()
//{
//	Fruit fruit;
//	fruit.print1();
//	fruit.print2();
//	fruit.print3();
//
//	// public�� price3�� �ܺο����� ���ٰ���
//	int num = fruit.price3;
//
//	return 0;
//}