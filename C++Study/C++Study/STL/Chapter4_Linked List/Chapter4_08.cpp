//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-05
//	list�� stack ���� ����
//*/
//
//template<typename T> class Stack
//{
//public:
//	Stack(){ Clear(); }
//
//	// �����ğ� �����Ѵ�
//	void SetInOutType(bool bLIFO) { m_bLIFO = bLIFO; }
//
//	// �ʱ�ȭ�Ѵ�
//	void Clear()
//	{
//		if (false == m_Datas.empty())
//			mDatas.clear();
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
//		if (m_bLIFO)
//		{
//			memcpy(data, &m_Datas.back(), sizeof(T));
//			m_Datas.pop_back();
//		}
//		else
//		{
//			memcpy(data, &m_Datas.front(), sizeof(T));
//			m_Datas.pop_front();
//		}
//
//		return true;
//	}
//private:
//	list<T> m_Datas;	
//	bool m_bLIFO;	// true�� ���Լ���, false�� ���Լ���
//};
//
//void main()
//{
//	Stack<int> int_Stack;
//	int_Stack.SetInOutType(true);
//	int_Stack.push(10);
//	int_Stack.push(20);
//	int_Stack.push(30);
//
//	int value = 0;
//	int_Stack.pop(&value);
//	cout << "LIFo pop : " << value << endl;
//
//	int_Stack.Clear();
//	
//}