//#include<iostream>
//using namespace std;
///*
//	2016-03-17
//	������ �����ε� ����
//	C++ ������ +�� - ���� �̹� ���ǵ� �����ڿ� �������� ����� ������ �� �ִ�.
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
//// ������ �����ε�( +�ڿ� ������ �Ű������� ������ �ش��Լ��� ����ȴ�)
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
//	cout << st3.hour << "�ð� : " << st3.minite << "��" << endl;
//
//	return 0;
//}