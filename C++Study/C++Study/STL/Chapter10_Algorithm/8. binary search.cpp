//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
///*
//	2016-03-18
//	이미 정렬 되어 있는 것 중에서 특정 데이터(조건에 맞는 데이터)가 지정한 구간에 있는지 조사하는 알고리즘
//*/
//
//int main()
//{
//	vector<int> vec1;
//	vec1.push_back(10);
//	vec1.push_back(20);
//	vec1.push_back(15);
//	vec1.push_back(7);
//	vec1.push_back(100);
//	vec1.push_back(40);
//	vec1.push_back(11);
//	vec1.push_back(60);
//	vec1.push_back(140);
//
//	// 정렬하지 않고 binary_search를 사용하면 정상적인 결과값을 얻을 수 없다.
//	bool find = binary_search(vec1.begin(), vec1.end(), 15);
//	if (false == find)
//		cout << "15를 찾지 못했습니다." << endl;
//	else
//		cout << "15를 찾았습니다." << endl;
//
//	// 정렬 후 사용
//	sort(vec1.begin(), vec1.end());
//	find = binary_search(vec1.begin(), vec1.end(), 15);
//	if (false == find)
//		cout << "15를 찾지 못했습니다." << endl;
//	else
//		cout << "15를 찾았습니다." << endl;
//
//	return 0;
//}