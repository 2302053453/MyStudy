#include<iostream>
/*
	2016-03-15
	using namespace ����
*/

using namespace std;

// �������� ����
int val = 100;

void SimpleFunc()
{
	// �������� ����
	int val = 3;
	
	// �������� �� ����
	val += 7;

	// �������� �� ���� (���� �̷������� ������� �ʴ´�.)
	::val += 7;
	cout << "�������� : " << val << endl;
	cout << "�������� : " << ::val << endl;
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
	
	// namespace ���� ��Ī�� ������ �� �ִ�
	namespace ABC = AAA::BBB::CCC;
	
	cout << ABC::num1 << endl;
	cout << ABC::num2 << endl;


	SimpleFunc();
	return 0;
}