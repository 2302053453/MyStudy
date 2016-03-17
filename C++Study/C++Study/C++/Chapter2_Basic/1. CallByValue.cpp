//#include<iostream>
///*
//2016-03-15
//주소 Call By Value 예제
//C++에서는 함수 외부에 선언된 변수의 접근방법 두 가지
//- 주소 값을 이용한 Call-by-reference (*)
//- 참조자를 이용한 Call-by-reference (&)
//
//Call-by-value의 형태로 정의된 함수의 내부에서는, 함수외부에 선언된 변수에 접근이 불가능하다.
//- SwapByValue에 전달된 인자는 SwapByValue의 지역변수이다.
//*/
//using namespace std;
//
//// call by reference
//void Swap(int ref1, int ref2)
//{
//	int temp = ref1;
//	ref1 = ref2;
//	ref2 = ref1;
//}
//int main()
//{
//	int val1 = 10;
//	int val2 = 20;
//
//	// val1과 val2의 값을 바꾼다.(하지만 call by value이기 때문에 실제 값은 변경되지 않는다).
//	Swap(val1, val2);
//
//	cout << "val1 : " << val1 << endl;
//	cout << "val2 : " << val2 << endl;
//	return 0;
//}