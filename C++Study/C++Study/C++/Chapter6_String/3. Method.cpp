//#include<iostream>
//#include<string>
//using namespace std;
///*
//	2016-03-17
//	string Method ����
//
//	  str( "sample", 16 ) : sample        // 16�ڸ��� Ȯ���ϰ� ���ڿ��� ä�� �� �ڸ��� \0 ���ڷ� ä��.
//	  string size : 16                    // sample �� �ڿ� ä���� \0 ���ڵ��� ���� �� ���ڿ� ����.
//	  string length : 16                  // length()�� '\0' ���ڸ� ������ ���̸� ��ȯ�Ѵ�.
//
//	  string capacity : 31                // ���Ҵ����� �ʰ� �ø� �� �ִ� ���ڿ��� ũ��.
//	  string max_size : 4294967294        // �Ҵ��� �� �ִ� �ִ� �޸� ũ��.
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
//	  capacity �� reserve �� ũ�Ⱑ �״�� ������� �ʰ� reserve �� ũ��� ���� ������ ũ�Ⱑ �ȴ�.
//*/
//
//int main()
//{
//	// �����ڷ� string �ʱ�ȭ, 16������ ���ڿ��� �����ϰ� ���ڸ��� \0�� ä��
//	string str = "sampleȫ�浿";
//	cout << "str(\"sample\",16 ) : " << str << endl;
//	cout << "string size : " << str.size() << endl;
//	cout << "string length : " << str.length() << endl;
//	cout << "string capacity : " << str.capacity() << endl;
//	cout << "string max_size : " << str.max_size() << endl;
//
//	// reverse�� ���� ����
//	str.reserve(32);
//	cout << "str.reverse(32)  : " << str << endl;
//	cout << "string size : " << str.size() << endl;
//	cout << "string length : " << str.length() << endl;
//	cout << "string capacity : " << str.capacity() << endl;
//	cout << "string max_size : " << str.max_size() << endl;
//
//	// 32�ڸ� ���� ū ���ڿ� �Ҵ�
//	str = "this is a sample : simple is the best. isn't it?";
//	cout << "str = \"this is a sample : simple is the best. isn't it?\" : " << str << endl;
//	cout << "string size : " << str.size() << endl;
//	cout << "string length : " << str.length() << endl;
//	cout << "string capacity : " << str.capacity() << endl;
//	cout << "string max_size : " << str.max_size() << endl;
//
//	return 0;
//}