//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<numeric>
//
//using namespace std;
///*
//	2016-03-18
//	inner_product 예제
//	두 시퀀스의 내적을 계산하는 알고리즘
//	단 두 입력 시퀀수 구간 중 두번째는 첫번째 구간보다 크거나 같아야 한다.
//	ex) 첫번째 데이터 5개 -> 두번째 는 5개 이상이어야 한다.
//*/
//
//int main()
//{
//	vector<int> vec1, vec2;
//
//	for (int i = 1; i < 4; ++i)
//		vec1.push_back(i);
//
//	for (int i = 1; i < 4; ++i)
//		vec2.push_back(i);
//
//	// 내적 : 0+(1*1)+(2*2)+(3*3) 
//	int result = inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
//	cout << result << endl;
//
//	return 0;
//
//}