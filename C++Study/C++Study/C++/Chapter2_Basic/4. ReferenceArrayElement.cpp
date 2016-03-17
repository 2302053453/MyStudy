//#include<iostream>
//using namespace std;
///*
//	2016-03-15
//	reference array element 예제
//	array의 요소에 대하여 참조자 선언이 가능하다
//
//	*참조자가 선언이 안되는 조건(ERROR 발생!)
//		- 상수대상의 참조자 선언 ( int &ref=20;, 단 const 참조자는 상수선언이 가능하다 )
//		- 참조자를 생성하고 초기화 시키지 않는 경우( int &ref;)
//		- NULL로 초기화 하는경우( int &ref=NULL;)
//*/
//
//int main()
//{
//	int arr[3] = { 1,3,5 };
//	
//	// Array의 요소에 대하여 reference를 선언
//	int &ref1 = arr[0];
//	int &ref2 = arr[1];
//	int &ref3 = arr[2];
//
//	cout << ref1 << endl;
//	cout << ref2 << endl;
//	cout << ref3 << endl;
//	return 0;
//}