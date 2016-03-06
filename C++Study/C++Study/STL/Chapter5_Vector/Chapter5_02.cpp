//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector insert 예제
//*/
//
//void main()
//{
//	vector<int> vector1;
//
//	vector1.push_back(20);
//	vector1.push_back(30);
//
//	cout << "삽입 테스트 1" << endl;
//
//	// 첫번째 위치에 삽입한다.
//	vector<int>::iterator iterInsertPos = vector1.begin();
//	vector1.insert(iterInsertPos, 100);
//
//	vector<int>::iterator iterEnd = vector1.end();
//	for (vector<int>::iterator iterPos = vector1.begin(); iterPos != iterEnd; iterPos++)
//		cout << "vector 1 : " << *iterPos << endl;
//
//	cout << "삽입 테스트 2" << endl;
//
//	// 두 번째 위치에 200을 2개 삽입한다.
//	iterInsertPos = vector1.begin();
//	++iterInsertPos;
//	vector1.insert(iterInsertPos, 2, 200);
//
//	iterEnd = vector1.end();
//	for (vector<int>::iterator iterPos = vector1.begin(); iterPos != iterEnd; iterPos++)
//		cout << "vector 1 : " << *iterPos << endl;
//
//	cout << "삽입 테스트 3" << endl;
//	vector<int> vector2;
//	vector2.push_back(1000);
//	vector2.push_back(2000);
//	vector2.push_back(3000);
//
//	// 두 번째 위치에 vector2의 모든 데이터를 삽입한다.
//	iterInsertPos = vector1.begin();
//	
//	vector1.insert(++iterInsertPos, vector2.begin(), vector2.end());
//	iterEnd = vector1.end();
//	for (vector<int>::iterator iterPos = vector1.begin(); iterPos != iterEnd; iterPos++)
//		cout << "vector 1 : " << *iterPos << endl;
//}