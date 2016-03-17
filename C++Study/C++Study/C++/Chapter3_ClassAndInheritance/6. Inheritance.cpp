//#include<iostream>
//using namespace std;
///*
//	2016-03-16
//	상속 예제
//
//	부모클래스에게 상속 받은 자식클래스는 부모크래스의 함수, 변수등을 사용할 수 있다
//*/
//
//// 부모클래스
//class Food
//{
//public:
//	int num;
//	void print()
//	{
//		cout << "부모클래스(기반클래스) 프린트 : " << endl;
//	}
//};
//
//// 자식클래스 (부모클래스를 상속 받는다.)
//class Fruit : public Food
//{
//public: 
//	void printFruit()
//	{
//		cout << "자식클래스(파생클래스) 프린트 : " << endl;
//	}
//};
//
//int main()
//{
//	Fruit fruit;
//	
//	// 부모 클래스의 맴버 함수 호출
//	fruit.print();
//
//	// 본인 클래스의 맴버 함수 호출
//	fruit.printFruit();
//
//	return 0;
//		
//}