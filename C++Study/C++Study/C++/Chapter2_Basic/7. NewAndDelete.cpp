//#include<iostream>
//#include<string.h>
//using namespace std;
//
///*
//	2016-03-15
//	new, delete ����
//
//	C������ �����Ҵ��� ������ ����
//	- �Ҵ��� ����� ������ ������ ����Ʈ ũ������� �����ؾ� �Ѵ�.
//	- ��ȯ���� void�� �������̱� ������ ������ �� ��ȯ�� ���ľ� �Ѵ�.
//	- �����ڰ� ȣ����� �ʴ´� ***
//*/
//
//char* MakeStrAdr2(int len)
//{
//	char * str = new char[len];
//	return str;
//}
//
//int main()
//{
//	char * str = MakeStrAdr2(20);
//	strncpy(str, "I am so happy",sizeof("I am so happy"));
//	cout << str << endl;
//
//	// �迭�� ���·� �Ҵ�� �޸� ������ ����
//	delete[] str;
//
//	return 0;
//}