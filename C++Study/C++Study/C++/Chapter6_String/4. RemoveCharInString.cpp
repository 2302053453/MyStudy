//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
///*
//	2016-03-17
//	string remove 예제
//	형식 : template <class ForwardIterator, class T>
//	ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& val);
//	설명 : 해당하는 문자열에서 단일 문자를 삭제한다. 찾는 단일 문자가 없으면 아무것도 삭제하지 않는다
//*/
//
//int main()
//{
//	string astring;
//	
//	// getline => cin>>하고 동일한 동작을 하는 함수 
//	// input -> test hello world를 입력하자
//	getline(cin, astring);
//
//	// 't' charracter 삭제
//	remove(astring.begin(), astring.end(), 't');
//
//	cout << astring << endl;
//	return 0;
//}