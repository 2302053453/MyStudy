//#include<iostream>
///*
//2016-03-15
//주소 Call By Reference 예제
//C++에서는 함수 외부에 선언된 변수의 접근방법 두 가지
//- 주소 값을 이용한 Call-by-reference (*)
//- 참조자를 이용한 Call-by-reference (&)
//
//본래 C언어에서 말하는 Call-by-reference는 다음의 의미를 지닌다.
//- 주소 값을 전달받아서, 함수 외부에 선언된 변수에 접근하는 형태의 함수호출
//*/
//using namespace std;
//
//// call by reference
//void Swap(int *ref1, int *ref2)
//{
//	int temp = *ref1;
//	*ref1 = *ref2;
//	*ref2 = *ref1;
//}
//int main()
//{
//	int val1 = 10;
//	int val2 = 20;
//
//	// val1과 val2의 값을 바꾼다.
//	Swap(&val1, &val2);
//
//	cout << "val1 : " << val1 << endl;
//	cout << "val2 : " << val2 << endl;
//	return 0;
//}