#include<iostream>
#include<string>
#include<sstream>
using namespace std;
/*
	2016-03-17
	Convert( ���ڸ� ���ڷ� ��ȯ) ����
	stream�� binary�� �����͸� �о���δ�.
	�� �����͸� string���� ��ȯ��Ű�� �ȴ�.
*/

int main()
{
	int i = 232;
	stringstream strStream;
	// ������ �д´�.
	strStream << i;

	// string type���� ��ȯ
	string s = "Cpmputer score : " + strStream.str();
	cout << s << endl;

	return 0;
}