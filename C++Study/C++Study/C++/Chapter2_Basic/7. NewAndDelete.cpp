//#include<iostream>
//#include<string.h>
//using namespace std;
//
///*
//	2016-03-15
//	new, delete 예제
//
//	C언어에서의 동적할당의 불편한 사항
//	- 할당할 대상의 정보를 무조건 바이트 크기단위로 전달해야 한다.
//	- 반환형이 void형 포인터이기 때문에 적절한 형 변환을 거쳐야 한다.
//	- 생성자가 호출되지 않는다 ***
//*/
//
//char* MakeStrAdr2(int len)
//{
//	char * str = new char[len];
//	return str;
//}
//
//int main()
//{
//	char * str = MakeStrAdr2(20);
//	strncpy(str, "I am so happy",sizeof("I am so happy"));
//	cout << str << endl;
//
//	// 배열의 형태로 할당된 메모리 공간의 해제
//	delete[] str;
//
//	return 0;
//}