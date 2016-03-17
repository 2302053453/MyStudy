//#include<iostream>
//#include<string>
//using namespace std;
///*
//	2016-03-17
//	sstring append 예제
//	append가 str1+str2보다 좀 더 빠르다.
//*/
//
//int main()
//{
//	string str = "Nobody is Perfect";
//	string s = ""; // Empty String
//	char *ch = "abcdef";
//
//	// append string str at the end of s
//	// return s
//
//	s.append(str, 0, 6);
//	cout << "s is : " << s << endl;
//
//	// appends copies of the characters in the range[inpIt1, inpIt2] to s
//	// return s
//	string::iterator inpIt1 = str.begin() + 6;
//	string::iterator inpIt2 = str.end();
//	
//	s.append(inpIt1, inpIt2);
//	cout << " s is : " << s << endl;
//
//	// appends three 
//	s.append(3, '!');
//	cout << " s is : " << s << endl;
//	
//	// appends the firts nm characters in ch at the end of s
//	// return s
//	s.append(ch, 3);
//	cout << " s is : " << s << endl;
//
//	// appends charArray ayt the end of s
//	// returns s
//	s.append(ch, 3);
//	cout << " s is : " << s << endl;
//
//	return 0;
//}