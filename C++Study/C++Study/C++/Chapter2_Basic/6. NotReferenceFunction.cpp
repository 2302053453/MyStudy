//#include<iostream>
//using namespace std;
///*
//	2016-03-15
//	function의 반환형이 value이며 매개변수가 참조형인경우의 예제
//*/
//
//// 함수의 반환형, 매개변수가 참조형
//int RefFuncOne(int &ref)
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
//	// 함수의 결과값을 num2에 저장
//	int num2 = RefFuncOne(num1);
//
//	// 반환형이 참조형이 아닌 value이므로 에러! -> int &num2 = 2와 비슷한 맥락이라 보면 된다.
//	// int &num2 = RefFuncOne(num1);
//
//	num1++;
//	num2 += 100;
//
//	cout << "num1 : " << num1 << endl;
//	cout << "num2 : " << num2 << endl;
//	return 0;
//}