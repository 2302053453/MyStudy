//#include<iostream>
//using namespace std;
///*
//	2016-03-17
//	template 예제
//*/
//
///*기존의 사용하던 overloading function
//	
//	int GetMax(int a, int b)
//	{
//		int buf;
//		if(a>b)
//			buf=a;
//		else
//			buf=b;
//		return buf;
//	}
//
//	double GetMax(double a, double b)
//	{
//		int buf;
//		if(a>b)
//			buf=a;
//		else
//			buf=b;
//		return buf;
//	}
//*/
//
//// template function으로 변경
//template<class T>
//T GetMax(T a, T b)
//{
//	T buf;
//	int buf;
//	if (a>b)
//		buf = a;
//	else
//		buf = b;
//	return buf;
//}
//
//int main()
//{
//	int n1 = 2, n2 = 3, ret1;
//	double r1 = 1.5, r2 = 3.5, ret2;
//	ret1 = GetMax(n1, n2);
//	ret1 = GetMax(r1, r2);
//
//	cout << ret1 << endl;
//	cout << ret2 << endl;
//}