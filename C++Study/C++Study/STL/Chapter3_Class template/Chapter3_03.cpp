//#include<iostream>
//using namespace std;
///*
//	2016-02-24
//	���ø��� ����� stack Ŭ����
//*/
//
//// ����ġ�� ������ �� �ִ� �ִ� ����
//const int MAX_EXP_COUNT = 100;
//
//// ����ġ ���� ���� Ŭ����
//template<typename T>
//class Stack
//{
//public:
//	Stack()
//	{
//		Clear();
//	}
//
//	// �ʱ�ȭ�Ѵ�
//	void Clear()
//	{
//		m_Count = 0;
//	}
//
//	// ���ÿ� ����� ����
//	int Count()
//	{
//		return m_Count;
//	}
//
//	// ����� �����Ͱ� ���°�?
//	bool IsEmpty()
//	{
//		return 0 == m_Count ? true : false;
//	}
//
//	// ����ġ�� �����Ѵ�
//	bool push(T data)
//	{
//		// ������ �� �ִ� ������ �Ѵ��� �����Ѵ�.
//		if (m_Count >= MAX_EXP_COUNT)
//			return false;
//
//		// ����ġ�� ���� �� ������ �ϳ� �ø���
//		m_aData[m_Count] = data;
//		++m_Count;
//
//		return true;
//	}
//
//	// ���ÿ��� ����ġ�� ������
//	T pop()
//	{
//		// ����� ���� ���ٸ� 0.0f�� ��ȯ�Ѵ�.
//		if (m_Count < 1)
//			return 0;
//
//		// ������ �ϳ� ���� �� ��ȯ�Ѵ�.
//		--m_Count;
//		return m_aData[m_Count];
//	}
//
//private:
//	T m_aData[MAX_EXP_COUNT];
//	int m_Count;
//};
//
//void main()
//{
//	// double�� ����ġ ����
//	Stack<double> kExpStack;
//	cout << "ù��° ���� ���� - ���� ����ġ 145.5f" << endl;
//	kExpStack.push(145.5f);
//	cout << "�ι�° ���� ���� - ���� ����ġ 183.25f" << endl;
//	kExpStack.push(183.25f);
//	cout << "����° ���� ���� - ���� ����ġ 162.3f" << endl;
//	kExpStack.push(162.3f);
//
//	int count = kExpStack.Count();
//	for (int i = 0; i < count; ++i)
//		cout << "���� ����ġ -> " << kExpStack.pop() << endl;
//
//	// int�� �� ����
//	Stack<int> kMoneyStack;
//	cout << "ù��° ���� ���� - ���� �ݾ� 14000" << endl;
//	kMoneyStack.push(14000);
//	cout << "�ι�° ���� ���� - ���� �ݾ� 320000" << endl;
//	kMoneyStack.push(320000);
//	cout << "����° ���� ���� - ���� �ݾ� 6400" << endl;
//	kMoneyStack.push(6400);
//
//	count = kMoneyStack.Count();
//	for (int i = 0; i < count; ++i)
//		cout << "���� �����ݾ� -> " << kMoneyStack.pop() << endl;
//
//}