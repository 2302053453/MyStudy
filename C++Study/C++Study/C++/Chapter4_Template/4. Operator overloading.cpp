//#include<iostream>
//using namespace std;
///*
//	2016-03-17
//	연산자 오버로딩 예제
//	C++ 언어에서는 +나 - 같이 이미 정의된 연산자에 독자적인 기능을 정의할 수 있다.
//*/
//
//class SimpleTime
//{
//public:
//	SimpleTime() {};
//	SimpleTime(int h, int m)
//	{
//		hour = h;
//		minite = m;
//	}
//	SimpleTime operator+(const SimpleTime &st);
//	int hour;
//	int minite;
//};
//
//// 연산자 오버로딩( +뒤에 형식이 매개변수와 같으면 해당함수가 실행된다)
//SimpleTime SimpleTime::operator+(const SimpleTime &st)
//{
//	int hour_buf, minite_buf, total;
//
//	total = (hour * 60 + minite) + (st.hour * 60 + st.minite);
//	hour_buf = total / 60;
//	minite_buf = total % 60;
//
//	return SimpleTime(hour_buf, minite_buf);
//}
//
//int main()
//{
//	SimpleTime st1(5, 30);
//	SimpleTime st2(2, 50);
//	SimpleTime st3;
//
//	st3 = st1 + st2;
//
//	cout << st3.hour << "시간 : " << st3.minite << "분" << endl;
//
//	return 0;
//}