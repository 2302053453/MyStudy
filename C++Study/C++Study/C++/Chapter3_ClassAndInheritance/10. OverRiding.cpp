//#include<iostream>
//
//using namespace std;
//
///*
//	2016-03-16
//	오버라이딩 예제
//	
//*/
//
//namespace a
//{
//	class Food
//	{
//	public:
//		void print(int i)
//		{
//			cout << "Food : " << i << endl;
//		}
//	private:
//	};
//}
//
//namespace b
//{
//	// 다른 namespace에 있어도 상속이 가능하다.
//	class Fruit: public a::Food 
//	{
//	public:
//		// 함수의 재정의 : 함수명, 인수, 반환형이 동일해야 한다.
//		// 이러한 행위를 오버라이딩이라고 한다.
//		void print(int i)
//		{
//			cout << "Food : " << i*100 << endl;
//		}
//	private:
//	};
//
//}
//
//int main()
//{
//	using namespace b;
//	Fruit fruit;
//
//	// 오버라이딩한 함수 호출
//	fruit.print(10);
//
//	// 기존 함수 호출
//	fruit.a::Food::print(20);
//
//	return 0;
//}
