//#include<iostream>
//#include<string.h>
//using namespace std;
///*
//	2016-03-03
//	템플릿을 사용한 stack 클래스
//	전문화된 클래스 팀플릿 정의
//*/
//
//
//
//template<typename T>
//class Stack
//{
//public:
//	// 생성자에서 스택 클래스의 크기를 지정
//	// 생성자를 암시적으로 형 변환을 할 수 없도록 한다.
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
//		if (m_Count >= m_size)
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
//
//const int MAX_ID_LENGTH = 21;
//
//// 아래의 코드는 문자열을 저장하기 위해 char*으로 전문화한 Stack 클래스입니다.
//template<>
//class Stack<char*>
//{
//public:
//	// 생성자에서 스택 클래스의 크기를 지정
//	// 생성자를 암시적으로 형 변환을 할 수 없도록 한다.
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
//	bool push(char* pID)
//	{
//		// 저장할 수 있는 개수를 넘는지 조사한다.
//		if (m_Count >= m_size)
//			return false;
//
//		// 경험치를 저장 후 개수를 하나 늘린다
//		strncpy_s(m_ppData[m_Count], MAX_ID_LENGTH, pID, MAX_ID_LENGTH);
//		m_ppData[m_Count][MAX_ID_LENGTH - 1] = '\0';
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
//	char* pop()
//	{
//		// 저장된 것이 없다면 0.0f를 반환한다.
//		if (m_Count < 1)
//			return 0;
//
//		// 개수를 하나 감소 후 반환한다.
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
//	cout << "스택의 크기는 ?" << kStack1.GetStackSize() << endl;
//	kStack1.push(10);
//	kStack1.push(11);
//	kStack1.push(12);
//	int count1 = kStack1.Count();
//	for (int i = 0; i < count1; i++)
//		cout << "유저의 레벨 변화 -> " << kStack1.pop() << endl;
//	cout << endl;
//
//	char GameID1[MAX_ID_LENGTH] = "NiceChoi";
//	char GameID2[MAX_ID_LENGTH] = "NiceCho";
//	char GameID3[MAX_ID_LENGTH] = "NiceC";
//	// Stack 클래스 탬플릿의 char* 전문화 버전을 생성한다
//	Stack<char*> kstack2(64);
//	kstack2.push(GameID1);
//	kstack2.push(GameID2);
//	kstack2.push(GameID3);
//	
//	int count2 = kstack2.Count();
//	for (int i = 0; i < count2; i++)
//		cout << "같이 게임을 한유저의 ID -> " << kstack2.pop() << endl;
//
//	system("PAUSE");
//
//	return 0;
//}