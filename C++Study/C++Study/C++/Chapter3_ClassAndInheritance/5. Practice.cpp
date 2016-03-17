//#include<iostream>
//
//using namespace std;
///*
//	2016-03-16
//	Class 연습
//*/
//
//// 클래스: 맴버 변수, 함수의 선언
//class OrangeBox
//{
//private:
//	int total;
//public:
//	// 생성자 : 오브젝트를 생성할 때 자동적으로 호출되는 특수한 함수
//	//		  : 반환값이 없으며, void 형도 지정하지 않는다.
//	OrangeBox()
//	{
//		cout << "오브젝트 생성됨" << endl;
//		total = 0;
//	}
//
//	// 생성자 오버로딩
//	OrangeBox(int n)
//	{
//		cout << "오브젝트 생성됨"<< n << endl;
//		total = n;
//	}
//
//	// 소멸자 : 오브젝트가 역할을 마쳤을 때 자동적으로 호출되는 특수한 함수
//	//		  : 반환값이 없으며, void형도 지정하지 않는다.
//	~OrangeBox()
//	{
//		cout << "오브젝트 소멸됨" << endl;
//	}
//
//	void Add(int num);
//	void Del(int num);
//	void Empty();
//	
//	// 맴버함수 내부에 정의 
//	void GetTotal()
//	{
//		cout << "TOTAL : " << total << endl;
//	}
//
//};	// 마지막에 ;
//
//// 맴버함수 외부에 정의
//void OrangeBox::Add(int num)
//{
//	total += num;
//}
//
//void OrangeBox::Del(int num)
//{
//	total -= num;
//
//	// 같은 오브젝트 내의 맴버 함수 호출하기
//	if (total < 0)
//		Empty();
//}
//
//void OrangeBox::Empty()
//{
//	total = 0;
//}
//
//int main()
//{
//	// 정적 객체 생성-> 생성자가 자동적으로 호출, 유효범위가 끝날 때-> 소멸자가 자동적으로 호출된다.
//	OrangeBox obox;
//	obox.Empty();
//	obox.Add(5);
//	obox.Del(4);
//	obox.GetTotal();
//
//	// 객체 정적 생성 (매개변수 포함)
//	OrangeBox obox1(10);
//	obox1.GetTotal();
//
//	// 객체를 동적으로 생성, 동적으로 생성한 객체는 소멸자를 직접 호출해야 된다.
//	OrangeBox * obox2 = new OrangeBox;
//	obox2->GetTotal();
//	obox2->~OrangeBox();
//
//	// 동적으로 생성된 객체는 소멸자를 호출하지 않으면 소멸되지 않는다.
//	OrangeBox * obox3 = new OrangeBox(20);
//	obox3->GetTotal();
//
//	return 0;
//}