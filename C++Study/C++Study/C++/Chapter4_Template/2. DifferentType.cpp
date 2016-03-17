//#include<iostream>
//using namespace std;
///*
//	2016-03-17
//	template 서로다른 매개변수 예제
//*/
//
//template<class T1,class T2>
//T2 GetMax(T1 a, T2 b)
//{
//	T2 buf;
//	if (a > b)
//		buf = (T2)a;
//	else
//		buf = (T2)b;
//
//	return buf;
//}
//
//int main()
//{
//	int n1 = 2, n2 = 3, ret1;
//	double r1 = 1.5, r2 = 3.5, ret2;
//	ret1 = GetMax<int, double>(n1, n2);
//	ret2 = GetMax<double, int>(r1, r2);
//
//	cout << ret1 << endl;
//	cout << ret2 << endl;
//}