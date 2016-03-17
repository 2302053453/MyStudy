//#include<iostream>
//using namespace std;
///*
//	2016-03-16
//	상속 클래스간의 관계
//	기본 클래스의 오브젝트를 파생 클래스의 오브젝트로 대입할 수 없다.
//
//	- 기본 클래스에 파생 클래스로 대입할 수 항목이 없을 수 있다.
//
//	파생 클래스 오브젝트의 어드레스를 기본 클래스의 포인터에 대입할 수 있다.
//	- 기본 클래스의 포인터를 사용하여 파생 클래스의 포인터 함수를 호출할 수 있다.
//*/
//
//class Food
//{
//private:
//	int price;
//public:
//	void SetPrice(int myPrice)
//	{
//		cout << "Food4 : " << myPrice << endl;
//	}
//};
//
//class Fruit : public Food
//{
//public:
//	void SetPrice2()
//	{
//		cout << "Fruit4 : " << endl;
//	}
//};
//
//class Snack : public Food
//{
//public:
//	void SetPrice2()
//	{
//		cout << "Snack4 : " << endl;
//	}
//};
//
//int main()
//{
//	// 포인터 형식으로만 받을 수 있다.
//	Food *food[2];
//	Fruit fruit;
//	Snack snack;
//
//	// 자식클래스를 부모클래스로 값을 넘긴다
//	// 이 경우 부모클래스에 해당하는 부분은 부모클래스로 넘어간다.
//	food[0] = &fruit;
//	food[1] = &snack;
//
//	food[0]->SetPrice(100);
//
//	// 부모클래스에 없는 함수는 호출이 되지 않는다.
//	// food[0]->SetPrice2();
//
//	return 0;
//}