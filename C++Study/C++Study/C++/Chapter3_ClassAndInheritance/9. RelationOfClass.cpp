//#include<iostream>
//using namespace std;
///*
//	2016-03-16
//	��� Ŭ�������� ����
//	�⺻ Ŭ������ ������Ʈ�� �Ļ� Ŭ������ ������Ʈ�� ������ �� ����.
//
//	- �⺻ Ŭ������ �Ļ� Ŭ������ ������ �� �׸��� ���� �� �ִ�.
//
//	�Ļ� Ŭ���� ������Ʈ�� ��巹���� �⺻ Ŭ������ �����Ϳ� ������ �� �ִ�.
//	- �⺻ Ŭ������ �����͸� ����Ͽ� �Ļ� Ŭ������ ������ �Լ��� ȣ���� �� �ִ�.
//*/
//
//class Food
//{
//private:
//	int price;
//public:
//	void SetPrice(int myPrice)
//	{
//		cout << "Food4 : " << myPrice << endl;
//	}
//};
//
//class Fruit : public Food
//{
//public:
//	void SetPrice2()
//	{
//		cout << "Fruit4 : " << endl;
//	}
//};
//
//class Snack : public Food
//{
//public:
//	void SetPrice2()
//	{
//		cout << "Snack4 : " << endl;
//	}
//};
//
//int main()
//{
//	// ������ �������θ� ���� �� �ִ�.
//	Food *food[2];
//	Fruit fruit;
//	Snack snack;
//
//	// �ڽ�Ŭ������ �θ�Ŭ������ ���� �ѱ��
//	// �� ��� �θ�Ŭ������ �ش��ϴ� �κ��� �θ�Ŭ������ �Ѿ��.
//	food[0] = &fruit;
//	food[1] = &snack;
//
//	food[0]->SetPrice(100);
//
//	// �θ�Ŭ������ ���� �Լ��� ȣ���� ���� �ʴ´�.
//	// food[0]->SetPrice2();
//
//	return 0;
//}