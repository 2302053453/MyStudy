//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<list>
//
//using namespace std;
//
///*
//	2016-03-18
//	remove 예제
//	컨테이너에 있는 특정값을 삭제한다
//	단 컨테이너의 크기는 변하지 않는다.
//	삭제가 성공하면 삭제 대상이 아닌 데이터를 앞으로 옮겨놓고
//	마지막위치(end()가 아닌 삭제 후 빈 공간에 디른데이터를 쓰기 시작한 위치) 반복자를 반환한다.
//	공간을 진짜 삭제하려면 erase를()를 사용해야 한다.
//*/
//
//int main()
//{
//	vector<int> vec1;
//	vec1.push_back(10); 
//	vec1.push_back(20);
//	vec1.push_back(20);
//	vec1.push_back(40);
//	vec1.push_back(50);
//	vec1.push_back(30);
//
//	vector<int>::iterator iter;
//	cout << "vec1에 있는 모든 데이터 출력 " << endl;
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "vec1에서 20 remove  " << endl;
//	vector<int>::iterator removeIter = remove(vec1.begin(), vec1.end(), 20);
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	cout << "vec1에서 20 remove 이후 사용하지 않는 영역 완전 제거 " << endl;
//	while (removeIter != vec1.end())
//		removeIter = vec1.erase(removeIter);
//
//	for (iter = vec1.begin(); iter != vec1.end(); ++iter)
//		cout << *iter << endl;
//
//	return 0;
//
//}