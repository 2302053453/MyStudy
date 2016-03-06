//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector erase 예제
//	1. 지정된 데이터 삭제
//	2. 지정된 범위의 데이터 삭제
//*/
//
//void main()
//{
//	vector<int> vector1;
//
//	vector1.push_back(10);
//	vector1.push_back(20);
//	vector1.push_back(30);
//	vector1.push_back(40);
//	vector1.push_back(50);
//
//
//	int count = vector1.size();
//	for (int i = 0; i < count; i++)
//		cout << "vector 1 : " << vector1[i] << endl;
//	cout << endl;
//
//	cout << "erase 테스트 1" << endl;
//
//	// 첫 번째 데이터 삭제
//	vector1.erase(vector1.begin());
//
//	count = vector1.size();
//	for (int i = 0; i < count; i++)
//		cout << "vector 1 : " << vector1[i] << endl;
//	cout << endl;
//
//	cout << "erase 테스트 2" << endl;
//
//	// 지정한 범위의 데이터 삭제
//	vector<int>::iterator iterInsertPos = vector1.begin();
//	vector1.erase(iterInsertPos, vector1.end());
//
//	if (vector1.empty())
//		cout << "vector1에 아무 것도 없습니다" << endl;
//}