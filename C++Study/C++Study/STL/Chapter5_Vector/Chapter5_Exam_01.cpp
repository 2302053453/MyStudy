//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-07
//	1. vector�� LIFO������� ������ ����ÿ�
//*/
//
//template<typename T> class Stack
//{
//public:
//	Stack() { Clear(); }
//
//	// �ʱ�ȭ�Ѵ�
//	void Clear()
//	{
//		if (empty())
//			m_Datas.clear();
//	}
//
//	// ���ÿ� ����� ����
//	int count() { return static_cast(m_Datas.size()); }
//
//	// ����� �����Ͱ� ���°�?
//	bool empty() { return m_Datas.empty(); }
//
//	// �����͸� �����Ѵ�
//	void push(T data)
//	{
//		m_Datas.push_back(data);
//	}
//
//	// ���ÿ��� ������
//	bool pop(T* data)
//	{
//		if (empty())
//		{
//			return false();
//		}
//		memcpy(data, &m_Datas.back(), sizeof(T));
//		m_Datas.pop_back();
//
//
//		return true;
//	}
//private:
//	vector<T> m_Datas;
//};
//
//void main()
//{
//	Stack<int> int_Stack;
//	int_Stack.push(10);
//	int_Stack.push(20);
//	int_Stack.push(30);
//
//	int value = 0;
//	int_Stack.pop(&value);
//	cout << "LIFo pop : " << value << endl;
//	int_Stack.pop(&value);
//	cout << "LIFo pop : " << value << endl;
//	int_Stack.Clear();
//
//	system("pause");
//
//}