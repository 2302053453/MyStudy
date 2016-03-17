#include<iostream>
/*
	2016-03-15
	using namespace 예제
*/

using namespace std;

// 전역변수 정의
int val = 100;

void SimpleFunc()
{
	// 지역변수 선언
	int val = 3;
	
	// 지역변수 값 증가
	val += 7;

	// 전역번수 깂 증가 (보통 이런식으로 사용하지 않는다.)
	::val += 7;
	cout << "지역변수 : " << val << endl;
	cout << "전역변수 : " << ::val << endl;
}

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

int main()
{
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;
	
	// namespace 줄인 명칭을 선언할 수 있다
	namespace ABC = AAA::BBB::CCC;
	
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;


	SimpleFunc();
	return 0;
}