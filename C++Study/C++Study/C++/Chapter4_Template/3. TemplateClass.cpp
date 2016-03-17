//#include<iostream>
//using namespace std;
///*
//	2016-03-17
//	template class 예제
//	템플릿 클래스 기능을 사용하면 복수의 형에 대응하는 클래스를 만들 수 있다.
//*/
//
//// template class 정의
//template<class T> 
//class Rectangle
//{
//public:
//	Rectangle(T n1, T n2, T n3, T n4)
//	{
//		left = n1;
//		top = n2;
//		width = n3;
//		height = n4;
//	}
//
//	T GetRight()
//	{
//		return left * width;
//	}
//
//	T GetBottom()
//	{
//		return top * height;
//	}
//
//private:
//	T left, top, width, height;
//};
//
//int main()
//{
//	Rectangle<int> rect1(50, 50, 100, 100);
//	cout << rect1.GetRight() << endl;
//
//
//	Rectangle<double> rect1(50.5, 50.5, 100.1, 100.1);
//	cout << rect1.GetRight() << endl;
//
//	return 0;
//}