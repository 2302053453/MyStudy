//#include<iostream>
//using namespace std;
///*
//	2016-03-16
//	���߻�� ����
//*/
//
//class Phone
//{
//public:
//	void power()
//	{
//		cout << "Phone : called " << endl;
//	}
//};
//
//class Printer
//{
//public:
//	void power()
//	{
//		cout << "printer : called" << endl;
//	}
//
//};
//
//// Phone�� Printer 2���� ��� (���߻��)
//// ���߻���� ��� ������ �� ������ ������ �����ؼ� �� ��(�������� Ŭ���� ���߻���� �ƴ� �������̽��� �����Լ��� ���(?) )
//class Fax : public Phone, public Printer
//{
//public:
//	void power()
//	{
//		cout << " Fax : called" << endl;
//	}
//};
//
//int main()
//{
//	Fax fax;
//	// ���߻���� �޾� �θ�Ŭ������ �����̸� �Լ��� ȣ���Ϸ���
//	// ���Ŭ�������� ������ ��� �Ѵ�.
//	fax.Phone::power();
//	fax.Printer::power(); 
//	fax.power();
//
//	Phone p = fax;
//	Printer pr = fax;
//
//	return 0;
//}