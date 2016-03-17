//#include<iostream>
//#include<string>
//using namespace std;
///*
//2016-03-17
//strinf find 예제
//*/
//
//int main()
//{
//	// 원본 문자열을 입력 받음
//	string src = "ABCDEFG 홍길동 HIJKLM 길동 OPQRSTU 동 VWXYZ";
//
//	// 찾을 문자열을 입력받음
//	cout << "찾을 문자열 입력 : ";
//	string findStr;
//	getline(cin, findStr);
//
//	// 바꿀 문자열 입력 받음
//	cout << "바꿀 문자열 입력 : ";
//	string replaceStr;
//	getline(cin, replaceStr);
//
//	// 원본 문자열 출력
//	cout << "원본 문자열 : " << src << endl;
//
//	// 검색에 필요한 변수들 초기화
//	string::size_type findOffset = 0;
//
//	while (true)
//	{
//		// 검색
//		findOffset = src.find(findStr, findOffset);
//
//		// 찾지 못했을 때
//		if (string::npos == findOffset)
//			break;
//		else
//			// 찾은 문자열을 바꿀 문자열로 바꿈
//			src.replace(findOffset, findStr.length(), replaceStr);
//	}
//
//	cout << "바뀐문자열 : " << src << endl;
//
//	return 0;
//}