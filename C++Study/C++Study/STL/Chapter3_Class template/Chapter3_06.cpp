//#include<iostream>
//using namespace std;
///*
//	2016-02-25
//	���ø��� ����� stack Ŭ����
//	Ŭ���� ���ø����� non-type �Ķ���� ���
//	���ø� �Ķ���� ����Ʈ �� ���
//	���� Ŭ������ ũ�⸦ ���� �����ڿ��� ����
//*/
//
//// ���ø� �Ķ���� ����Ʈ �� ���
//// Ŭ���� ���ø����� non-type �Ķ���� ���
//template<typename T, int size = 100>
//class Stack
//{
//public:
//	// �����ڿ��� ���� Ŭ������ ũ�⸦ ����
//	// �����ڸ� �Ͻ������� �� ��ȯ�� �� �� ������ �Ѵ�.
//	explicit Stack()
//	{
//		m_size = size;
//		m_aData = new T[m_size];
//
//		Clear();
//	}
//	~Stack()
//	{
//		delete[]m_aData;
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
//		if (m_Count >= size)
//			return false;
//
//		// ����ġ�� ���� �� ������ �ϳ� �ø���
//		m_aData[m_Count] = data;
//		++m_Count;
//
//		return true;
//	}
//
//	// �ִ� ������ �ִ½����� ����
//	int GetStackSize()
//	{
//		return m_size;
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
//	T * m_aData;
//	int m_Count;
//
//	int m_size;
//};
//
//void main()
//{
//	// double�� ����ġ ����, 
//	Stack<double, 64> kStack1;
//	cout << "������ ũ��� ? " << kStack1.GetStackSize() << endl;
//	
//	// ���ø� ����Ʈ ������Ͽ� ���� ���� �� �ʱ�ȭ
//	Stack<int> kStack2;
//	cout << "������ ũ��� ? " << kStack2.GetStackSize() << endl;
//
//}