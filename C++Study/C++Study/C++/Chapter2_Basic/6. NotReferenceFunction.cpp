//#include<iostream>
//using namespace std;
///*
//	2016-03-15
//	function�� ��ȯ���� value�̸� �Ű������� �������ΰ���� ����
//*/
//
//// �Լ��� ��ȯ��, �Ű������� ������
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
//	// �Լ��� ������� num2�� ����
//	int num2 = RefFuncOne(num1);
//
//	// ��ȯ���� �������� �ƴ� value�̹Ƿ� ����! -> int &num2 = 2�� ����� �ƶ��̶� ���� �ȴ�.
//	// int &num2 = RefFuncOne(num1);
//
//	num1++;
//	num2 += 100;
//
//	cout << "num1 : " << num1 << endl;
//	cout << "num2 : " << num2 << endl;
//	return 0;
//}