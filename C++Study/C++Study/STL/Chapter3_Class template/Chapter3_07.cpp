//#include<iostream>
//#include<string.h>
//using namespace std;
///*
//	2016-03-03
//	���ø��� ����� stack Ŭ����
//	����ȭ�� Ŭ���� ���ø� ����
//*/
//
//
//
//template<typename T>
//class Stack
//{
//public:
//	// �����ڿ��� ���� Ŭ������ ũ�⸦ ����
//	// �����ڸ� �Ͻ������� �� ��ȯ�� �� �� ������ �Ѵ�.
//	explicit Stack(int size)
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
//		if (m_Count >= m_size)
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
//
//const int MAX_ID_LENGTH = 21;
//
//// �Ʒ��� �ڵ�� ���ڿ��� �����ϱ� ���� char*���� ����ȭ�� Stack Ŭ�����Դϴ�.
//template<>
//class Stack<char*>
//{
//public:
//	// �����ڿ��� ���� Ŭ������ ũ�⸦ ����
//	// �����ڸ� �Ͻ������� �� ��ȯ�� �� �� ������ �Ѵ�.
//	explicit Stack(int size)
//	{
//		m_size = size;
//
//		m_ppData = new char*[m_size];
//		for (int i = 0; i < m_size; i++)
//			m_ppData[i] = new char[MAX_ID_LENGTH];
//		Clear();
//	}
//	~Stack()
//	{
//		for (int i = 0; i < m_size; i++)
//			delete[] m_ppData[i];
//		delete[] m_ppData;
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
//	bool push(char* pID)
//	{
//		// ������ �� �ִ� ������ �Ѵ��� �����Ѵ�.
//		if (m_Count >= m_size)
//			return false;
//
//		// ����ġ�� ���� �� ������ �ϳ� �ø���
//		strncpy_s(m_ppData[m_Count], MAX_ID_LENGTH, pID, MAX_ID_LENGTH);
//		m_ppData[m_Count][MAX_ID_LENGTH - 1] = '\0';
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
//	char* pop()
//	{
//		// ����� ���� ���ٸ� 0.0f�� ��ȯ�Ѵ�.
//		if (m_Count < 1)
//			return 0;
//
//		// ������ �ϳ� ���� �� ��ȯ�Ѵ�.
//		--m_Count;
//		return m_ppData[m_Count];
//	}
//
//private:
//	char** m_ppData;
//	int m_Count;
//
//	int m_size;
//};
//
//
//int main()
//{
//	Stack<int> kStack1(64);
//	cout << "������ ũ��� ?" << kStack1.GetStackSize() << endl;
//	kStack1.push(10);
//	kStack1.push(11);
//	kStack1.push(12);
//	int count1 = kStack1.Count();
//	for (int i = 0; i < count1; i++)
//		cout << "������ ���� ��ȭ -> " << kStack1.pop() << endl;
//	cout << endl;
//
//	char GameID1[MAX_ID_LENGTH] = "NiceChoi";
//	char GameID2[MAX_ID_LENGTH] = "NiceCho";
//	char GameID3[MAX_ID_LENGTH] = "NiceC";
//	// Stack Ŭ���� ���ø��� char* ����ȭ ������ �����Ѵ�
//	Stack<char*> kstack2(64);
//	kstack2.push(GameID1);
//	kstack2.push(GameID2);
//	kstack2.push(GameID3);
//	
//	int count2 = kstack2.Count();
//	for (int i = 0; i < count2; i++)
//		cout << "���� ������ �������� ID -> " << kstack2.pop() << endl;
//
//	system("PAUSE");
//
//	return 0;
//}