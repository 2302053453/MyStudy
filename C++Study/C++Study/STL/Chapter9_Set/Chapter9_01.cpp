//#include<iostream>
//#include<functional>
//#include<set>
//using namespace std;
///*
//	2016-03-18
//	set 예제( insert 후 출력)
//	map은 (key, value)를 저장하지만 set은 key만을 저장한다.
//	사용하면 좋은 경우
//	- 정렬해야 할 때
//	- key가 있는지 없는지 알아야 할 때
//	- 많은 자료를 저장하고, 검색 속도가 빨라야 할 때 
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
//	set<int>::iterator iter = set1.begin();
//
//	++iter;
//	set1.insert(iter, 90);
//
//	cout << endl;
//	cout << "90을 추가 후 ser1의 모든 요소 출력" << endl;
//
//	for (set<int>::iterator iter = set1.begin(); iter != set1.end(); ++iter)
//		cout << *iter << endl;
//
//	return 0;
//}