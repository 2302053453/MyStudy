//#include<iostream>
//using namespace std;
//
///*
//	2016-03-16
//	상속에서의 접근제한 예제
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
//		// private 는 오직 해당 클래스에서만 접근이 가능하다
//		// cout << "price1 : " << price1 << endl;
//	}
//
//	void print2()
//	{
//		// pritected는 해당 클래스와 상속받은 클래스에서 접근이 가능하다.
//		cout << "price2 : " << price2 << endl;
//	}
//
//	void print3()
//	{
//		// public은 어디에서나 접근이 가능하다.
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
//	// public인 price3은 외부에서도 접근가능
//	int num = fruit.price3;
//
//	return 0;
//}