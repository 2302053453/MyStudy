//#include<iostream>
//using namespace std;
///*
//	2016-03-15
//	function의 반환형과 매개변수가 참조형인경우의 예제
//*/
//
//// 함수의 반환형, 매개변수가 참조형
//int & RefFuncOne(int &ref)
//{
//	ref++;
//	return ref;
//}
//
//
//int main()
//{
//	int num1 = 1;
//
//	// 함수의 결과값을 num2에 저장( num2는 참조형이 아니므로 값은 같으나 주소값은 다르므로 num1 != num2이다.
//	int num2 = RefFuncOne(num1);
//	
//	// 만일 num2를 참조형으로 선언하는 경우 주소또한 동일하므로 num1 = num2가 된다
//	// int &num2 = RefFuncOne(num1);
//	
//	num1++;
//	num2+=100;
//
//	cout << "num1 : " << num1 << endl;
//	cout << "num2 : " << num2 << endl;
//	return 0;
//}