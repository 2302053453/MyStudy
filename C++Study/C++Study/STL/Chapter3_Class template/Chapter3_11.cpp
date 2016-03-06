//#include<iostream>
//using namespace std;
///*
//	2016-03-03
//	���ø��� ����� stack Ŭ����
//	Ŭ���� ���ø� ����� ���Ǹ� �и�
//*/
//
//
//// ����κ�
//template<typename T>
//class Stack
//{
//public:
//	explicit Stack(int size);
//
//	~Stack();
//
//	// �ʱ�ȭ�Ѵ�
//	void Clear();
//
//	// ���ÿ� ����� ����
//	int Count();
//
//	// ����� �����Ͱ� ���°�?
//	bool IsEmpty();
//
//	// �����͸� ���� �� �ִ� �ִ� ����
//	int GetStackSize();
//
//	// ����ġ�� �����Ѵ�
//	bool push(T data);
//
//	// ���ÿ��� ����ġ�� ������
//	T pop();
//
//private:
//	T* m_aData;
//	int m_Count;
//	int m_size;
//};
//
//// ���Ǻκ�
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
//	// ������ �� �ִ� ������ �Ѵ��� �����Ѵ�.
//	if (m_Count >= MAX_EXP_COUNT)
//		return false;
//
//	// ����ġ�� ���� �� ������ �ϳ� �ø���
//	m_aData[m_Count] = data;
//	++m_Count;
//
//	return true;
//}
//
//// ���ÿ��� ����ġ�� ������
//template<typename T> T Stack<T>::pop()
//{
//	// ����� ���� ���ٸ� 0.0f�� ��ȯ�Ѵ�.
//	if (m_Count < 1)
//		return 0;
//
//	// ������ �ϳ� ���� �� ��ȯ�Ѵ�.
//	--m_Count;
//	return m_aData[m_Count];
//}
//
//void main()
//{
//	Stack<int> kStack(7);
//	cout << "������ ũ���?" << kStack.GetStackSize() << endl;
//
//	system("PAUSE");
//}
//
