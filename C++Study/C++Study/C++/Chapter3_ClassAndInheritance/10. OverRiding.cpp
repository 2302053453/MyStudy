//#include<iostream>
//
//using namespace std;
//
///*
//	2016-03-16
//	�������̵� ����
//	
//*/
//
//namespace a
//{
//	class Food
//	{
//	public:
//		void print(int i)
//		{
//			cout << "Food : " << i << endl;
//		}
//	private:
//	};
//}
//
//namespace b
//{
//	// �ٸ� namespace�� �־ ����� �����ϴ�.
//	class Fruit: public a::Food 
//	{
//	public:
//		// �Լ��� ������ : �Լ���, �μ�, ��ȯ���� �����ؾ� �Ѵ�.
//		// �̷��� ������ �������̵��̶�� �Ѵ�.
//		void print(int i)
//		{
//			cout << "Food : " << i*100 << endl;
//		}
//	private:
//	};
//
//}
//
//int main()
//{
//	using namespace b;
//	Fruit fruit;
//
//	// �������̵��� �Լ� ȣ��
//	fruit.print(10);
//
//	// ���� �Լ� ȣ��
//	fruit.a::Food::print(20);
//
//	return 0;
//}
