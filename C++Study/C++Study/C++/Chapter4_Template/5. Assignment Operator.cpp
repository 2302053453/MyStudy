//#include<iostream>
//#include<cstring>
//using namespace std;
///*
//	2016-03-17
//	���� ������ �����ε� ����
//*/
//
//class Person
//{
//private:
//	char * name;
//public:
//	Person() { name = NULL; }
//	Person(char *str)
//	{
//		int len = (int)strlen(str);
//		name = new char[len + 1];
//		strcpy(name, str);
//	}
//	~Person() { delete []name; }
//	Person & operator= (const Person & psn);
//
//	char * GetName()
//	{
//		return name;
//	}
//};
//
//// �ش� �����ε� �Լ��� ������ C++���� ����ϴ� string ��ü ó�� �����ϰ� �����ϴ� ���� �� ��
//Person & Person::operator= (const Person & psn)
//{
//	// �����ϸ� ���� ���� return
//	if (this == &psn)
//		return *this;
//
//	// ���ݱ����� �޸𸮸� ����
//	delete []name;
//	// ���ڿ��� ���̸� ���ؼ� �� ���� ��ŭ�� �迭�� ����
//	int len = (int)strlen(psn.name);
//	name = new char[len + 1];
//
//	// ���ڿ��� �ش� �迭�� ���� �� �ּҰ��� ����
//	strcpy(name, psn.name);
//	return *this;
//}
//
//int main()
//{
//	Person psn1("Orange"), psn2("Apple");
//	psn1 = psn2;
//	cout << psn1.GetName() << endl;
//
//	return 0;
//}