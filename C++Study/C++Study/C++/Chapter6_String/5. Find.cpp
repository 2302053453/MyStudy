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
//	// 검색에 필요한 변수들 초기화
//	int cnt = 0;
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
//
//		// 찾은 개수와 현재 검색 위치 이동
//		++cnt;
//		++findOffset;
//	}
//
//	cout << "문자열 ( " << findStr << " ) 의 개수 : " << cnt << endl;
//
//	return 0;
//}