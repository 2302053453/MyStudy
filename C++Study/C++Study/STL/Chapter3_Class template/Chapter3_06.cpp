//#include<iostream>
//using namespace std;
///*
//	2016-02-25
//	템플릿을 사용한 stack 클래스
//	클래스 템플릿에서 non-type 파라메터 사용
//	템플릿 파라메터 디폴트 값 사용
//	스택 클래스의 크기를 스택 생성자에서 지정
//*/
//
//// 템플릿 파라메터 디폴트 값 사용
//// 클래스 템플릿에서 non-type 파라메터 사용
//template<typename T, int size = 100>
//class Stack
//{
//public:
//	// 생성자에서 스택 클래스의 크기를 지정
//	// 생성자를 암시적으로 형 변환을 할 수 없도록 한다.
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
//	// 초기화한다
//	void Clear()
//	{
//		m_Count = 0;
//	}
//
//	// 스택에 저장된 개수
//	int Count()
//	{
//		return m_Count;
//	}
//
//	// 저장된 데이터가 없는가?
//	bool IsEmpty()
//	{
//		return 0 == m_Count ? true : false;
//	}
//
//	// 경험치를 저장한다
//	bool push(T data)
//	{
//		// 저장할 수 있는 개수를 넘는지 조사한다.
//		if (m_Count >= size)
//			return false;
//
//		// 경험치를 저장 후 개수를 하나 늘린다
//		m_aData[m_Count] = data;
//		++m_Count;
//
//		return true;
//	}
//
//	// 최대 담을수 있는스택의 갯수
//	int GetStackSize()
//	{
//		return m_size;
//	}
//
//	// 스택에서 경험치를 빼낸다
//	T pop()
//	{
//		// 저장된 것이 없다면 0.0f를 반환한다.
//		if (m_Count < 1)
//			return 0;
//
//		// 개수를 하나 감소 후 반환한다.
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
//	// double형 경험치 스택, 
//	Stack<double, 64> kStack1;
//	cout << "스택의 크기는 ? " << kStack1.GetStackSize() << endl;
//	
//	// 템플릿 디폴트 값사용하여 스택 선언 및 초기화
//	Stack<int> kStack2;
//	cout << "스택의 크기는 ? " << kStack2.GetStackSize() << endl;
//
//}