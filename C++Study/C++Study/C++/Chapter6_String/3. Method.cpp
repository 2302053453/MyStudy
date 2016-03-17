//#include<iostream>
//#include<string>
//using namespace std;
///*
//	2016-03-17
//	string Method 예제
//
//	  str( "sample", 16 ) : sample        // 16자리를 확보하고 문자열을 채운 빈 자리는 \0 문자로 채움.
//	  string size : 16                    // sample 과 뒤에 채워진 \0 문자들을 합한 총 문자열 길이.
//	  string length : 16                  // length()는 '\0' 문자를 포함한 길이를 반환한다.
//
//	  string capacity : 31                // 재할당하지 않고 늘릴 수 있는 문자열의 크기.
//	  string max_size : 4294967294        // 할당할 수 있는 최대 메모리 크기.
//
//	  str.reserve( 32 ) : sample
//	  string size : 16
//	  string length : 16
//	  string capacity : 47
//	  string max_size : 4294967294
//
//	  str = "this is a sample : simple is the best. isn't it? "this is a sample : simple is the best. isn't it?
//	  string size : 48
//	  string length : 48
//	  string capacity : 70
//	  string max_size : 4294967294
//
//	  capacity 는 reserve 한 크기가 그대로 적용되지 않고 reserve 한 크기와 비교해 적당한 크기가 된다.
//*/
//
//int main()
//{
//	// 생성자로 string 초기화, 16ㅈ리의 문자열을 생성하고 빈자리는 \0로 채움
//	string str = "sample홍길동";
//	cout << "str(\"sample\",16 ) : " << str << endl;
//	cout << "string size : " << str.size() << endl;
//	cout << "string length : " << str.length() << endl;
//	cout << "string capacity : " << str.capacity() << endl;
//	cout << "string max_size : " << str.max_size() << endl;
//
//	// reverse로 공간 예약
//	str.reserve(32);
//	cout << "str.reverse(32)  : " << str << endl;
//	cout << "string size : " << str.size() << endl;
//	cout << "string length : " << str.length() << endl;
//	cout << "string capacity : " << str.capacity() << endl;
//	cout << "string max_size : " << str.max_size() << endl;
//
//	// 32자리 보다 큰 문자열 할당
//	str = "this is a sample : simple is the best. isn't it?";
//	cout << "str = \"this is a sample : simple is the best. isn't it?\" : " << str << endl;
//	cout << "string size : " << str.size() << endl;
//	cout << "string length : " << str.length() << endl;
//	cout << "string capacity : " << str.capacity() << endl;
//	cout << "string max_size : " << str.max_size() << endl;
//
//	return 0;
//}