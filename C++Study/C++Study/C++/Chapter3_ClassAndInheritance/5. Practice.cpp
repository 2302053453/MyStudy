//#include<iostream>
//
//using namespace std;
///*
//	2016-03-16
//	Class ����
//*/
//
//// Ŭ����: �ɹ� ����, �Լ��� ����
//class OrangeBox
//{
//private:
//	int total;
//public:
//	// ������ : ������Ʈ�� ������ �� �ڵ������� ȣ��Ǵ� Ư���� �Լ�
//	//		  : ��ȯ���� ������, void ���� �������� �ʴ´�.
//	OrangeBox()
//	{
//		cout << "������Ʈ ������" << endl;
//		total = 0;
//	}
//
//	// ������ �����ε�
//	OrangeBox(int n)
//	{
//		cout << "������Ʈ ������"<< n << endl;
//		total = n;
//	}
//
//	// �Ҹ��� : ������Ʈ�� ������ ������ �� �ڵ������� ȣ��Ǵ� Ư���� �Լ�
//	//		  : ��ȯ���� ������, void���� �������� �ʴ´�.
//	~OrangeBox()
//	{
//		cout << "������Ʈ �Ҹ��" << endl;
//	}
//
//	void Add(int num);
//	void Del(int num);
//	void Empty();
//	
//	// �ɹ��Լ� ���ο� ���� 
//	void GetTotal()
//	{
//		cout << "TOTAL : " << total << endl;
//	}
//
//};	// �������� ;
//
//// �ɹ��Լ� �ܺο� ����
//void OrangeBox::Add(int num)
//{
//	total += num;
//}
//
//void OrangeBox::Del(int num)
//{
//	total -= num;
//
//	// ���� ������Ʈ ���� �ɹ� �Լ� ȣ���ϱ�
//	if (total < 0)
//		Empty();
//}
//
//void OrangeBox::Empty()
//{
//	total = 0;
//}
//
//int main()
//{
//	// ���� ��ü ����-> �����ڰ� �ڵ������� ȣ��, ��ȿ������ ���� ��-> �Ҹ��ڰ� �ڵ������� ȣ��ȴ�.
//	OrangeBox obox;
//	obox.Empty();
//	obox.Add(5);
//	obox.Del(4);
//	obox.GetTotal();
//
//	// ��ü ���� ���� (�Ű����� ����)
//	OrangeBox obox1(10);
//	obox1.GetTotal();
//
//	// ��ü�� �������� ����, �������� ������ ��ü�� �Ҹ��ڸ� ���� ȣ���ؾ� �ȴ�.
//	OrangeBox * obox2 = new OrangeBox;
//	obox2->GetTotal();
//	obox2->~OrangeBox();
//
//	// �������� ������ ��ü�� �Ҹ��ڸ� ȣ������ ������ �Ҹ���� �ʴ´�.
//	OrangeBox * obox3 = new OrangeBox(20);
//	obox3->GetTotal();
//
//	return 0;
//}