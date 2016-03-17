//#include<iostream>
//#include<cstring>
//using namespace std;
///*
//	2016-03-17
//	대입 연산자 오버로딩 예제
//*/
//
//class Person
//{
//private:
//	char * name;
//public:
//	Person() { name = NULL; }
//	Person(char *str)
//	{
//		int len = (int)strlen(str);
//		name = new char[len + 1];
//		strcpy(name, str);
//	}
//	~Person() { delete []name; }
//	Person & operator= (const Person & psn);
//
//	char * GetName()
//	{
//		return name;
//	}
//};
//
//// 해당 오버로딩 함수의 내용은 C++에서 사용하는 string 객체 처리 로직하고 동일하니 참고 할 것
//Person & Person::operator= (const Person & psn)
//{
//	// 동일하면 지금 값을 return
//	if (this == &psn)
//		return *this;
//
//	// 지금까지의 메모리를 해제
//	delete []name;
//	// 문자열의 길이를 구해서 그 길이 만큼의 배열을 선언
//	int len = (int)strlen(psn.name);
//	name = new char[len + 1];
//
//	// 문자열을 해당 배열에 복사 후 주소값을 리턴
//	strcpy(name, psn.name);
//	return *this;
//}
//
//int main()
//{
//	Person psn1("Orange"), psn2("Apple");
//	psn1 = psn2;
//	cout << psn1.GetName() << endl;
//
//	return 0;
//}