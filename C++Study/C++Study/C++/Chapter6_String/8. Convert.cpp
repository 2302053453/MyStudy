#include<iostream>
#include<string>
#include<sstream>
using namespace std;
/*
	2016-03-17
	Convert( 숫자를 문자로 변환) 예제
	stream은 binary로 데이터를 읽어들인다.
	이 데이터를 string으로 변환시키면 된다.
*/

int main()
{
	int i = 232;
	stringstream strStream;
	// 정수를 읽는다.
	strStream << i;

	// string type으로 변환
	string s = "Cpmputer score : " + strStream.str();
	cout << s << endl;

	return 0;
}