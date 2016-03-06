//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector assign 예제
//	1. 특정값을 n만큼 채운다
//	2. 특정 범위의 값을 특정 범위의 값으로 채운다
//*/
//
//void main()
//{
//	vector<int> vector1;
//	
//	// 4를 7개 채운다
//	// 
//	vector1.assign(7, 4);
//	int count = vector1.size();
//
//	for (int i = 0; i < count; i++)
//		cout << "vector1 : " << vector1[i] << endl;
//
//	vector<int> vector2;
//	vector2.push_back(10);
//	vector2.push_back(20);
//	vector2.push_back(30);
//
//	// vector2의 요소로 채운다
//	vector1.assign(vector2.begin(), vector2.end());
//
//	count = vector1.size();
//
//	for (int i = 0; i < count; i++)
//		cout << "vector1 : " << vector1[i] << endl;
//}