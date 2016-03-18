//#include<iostream>
//#include<functional>
//#include<set>
//using namespace std;
///*
//	2016-03-18
//	set -> find로 찾은 key 변경? -> find()의 모든 반환자가 const형이므로 변경 불가!
//*/
//
//int main()
//{
//	set<int> set1;
//	set1.insert(10);
//	set1.insert(15);
//	set1.insert(12);
//	set1.insert(2);
//	set1.insert(100);
//
//	for (set<int>::iterator iter = set1.begin(); iter != set1.end(); ++iter)
//		cout << *iter << endl;
//
//	set<int>::iterator iter = set1.find(15);
//	if (iter != set1.end())
//		cout << "검색결과 : " << *iter << endl;
//
//	return 0;
//}