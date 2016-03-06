//#include<iostream>
//using namespace std;
///*
//	2016-03-03
//	템플릿을 사용한 stack 클래스
//	클래스 탬플릿 선언과 정의를 분리
//*/
//
//
//// 선언부분
//template<typename T>
//class Stack
//{
//public:
//	explicit Stack(int size);
//
//	~Stack();
//
//	// 초기화한다
//	void Clear();
//
//	// 스택에 저장된 개수
//	int Count();
//
//	// 저장된 데이터가 없는가?
//	bool IsEmpty();
//
//	// 데이터를 담을 수 있는 최대 개수
//	int GetStackSize();
//
//	// 경험치를 저장한다
//	bool push(T data);
//
//	// 스택에서 경험치를 빼낸다
//	T pop();
//
//private:
//	T* m_aData;
//	int m_Count;
//	int m_size;
//};
//
//// 정의부분
//template<typename T> Stack<T>::Stack(int size)
//{
//	m_size = size;
//	m_aData = new T[m_size];
//	Clear();
//}
//
//template<typename T> Stack<T>::~Stack()
//{
//	delete[] m_aData;
//}
//
//template<typename T> void Stack<T>::Clear()
//{
//	m_Count = 0;
//}
//
//template<typename T> int Stack<T>::Count()
//{
//	return m_Count;
//}
//
//template<typename T> bool Stack<T>::IsEmpty()
//{
//	return 0 == m_Count ? true : false;
//}
//
//template<typename T> int Stack<T>::GetStackSize()
//{
//	return m_size;
//}
//
//template<typename T> bool Stack<T>::push(T data)
//{
//	// 저장할 수 있는 개수를 넘는지 조사한다.
//	if (m_Count >= MAX_EXP_COUNT)
//		return false;
//
//	// 경험치를 저장 후 개수를 하나 늘린다
//	m_aData[m_Count] = data;
//	++m_Count;
//
//	return true;
//}
//
//// 스택에서 경험치를 빼낸다
//template<typename T> T Stack<T>::pop()
//{
//	// 저장된 것이 없다면 0.0f를 반환한다.
//	if (m_Count < 1)
//		return 0;
//
//	// 개수를 하나 감소 후 반환한다.
//	--m_Count;
//	return m_aData[m_Count];
//}
//
//void main()
//{
//	Stack<int> kStack(7);
//	cout << "스택의 크기는?" << kStack.GetStackSize() << endl;
//
//	system("PAUSE");
//}
//
