//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-05
//	list로 stack 구현 예제
//*/
//
//template<typename T> class Stack
//{
//public:
//	Stack(){ Clear(); }
//
//	// 저장방식읋 설정한다
//	void SetInOutType(bool bLIFO) { m_bLIFO = bLIFO; }
//
//	// 초기화한다
//	void Clear()
//	{
//		if (false == m_Datas.empty())
//			mDatas.clear();
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
//	bool m_bLIFO;	// true면 후입선출, false면 선입선출
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