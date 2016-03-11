//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-07
//	1. vector로 LIFO방식으로 스택을 만드시오
//*/
//
//template<typename T> class Stack
//{
//public:
//	Stack() { Clear(); }
//
//	// 초기화한다
//	void Clear()
//	{
//		if (empty())
//			m_Datas.clear();
//	}
//
//	// 스택에 저장된 개수
//	int count() { return static_cast(m_Datas.size()); }
//
//	// 저장된 데이터가 없는가?
//	bool empty() { return m_Datas.empty(); }
//
//	// 데이터를 저장한다
//	void push(T data)
//	{
//		m_Datas.push_back(data);
//	}
//
//	// 스택에서 빼낸다
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