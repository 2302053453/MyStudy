//#include<vector>
//#include<iostream>
//#include<algorithm>
//#include<functional>
//
//using namespace std;
//
///*
//	2016-03-18
//	sort 예제
//	기본적으로 오름차순으로 정렬되면
//	내림차순으로 정렬하려면  기본형의 경우 greater<>()나 less
//	기본형이 아니면 직접 비교조건자를 만들어야하며
//	랜덤 접근이 가능한 컨테이너에서만 사용이 가능하다.
//*/
//
//int main()
//{
//	vector<int> vec1(10);
//	generate(vec1.begin(), vec1.end(), rand);
//
//	vector<int>::iterator iter;
//
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "오름차순 정렬" << endl;
//	sort(vec1.begin(), vec1.end());
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "내림차순 정렬" << endl;
//	sort(vec1.begin(), vec1.end(), greater<int>());
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "일부만 오름차순 정렬" << endl;
//	sort(vec1.begin()+3, vec1.end());
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	return 0;
//}