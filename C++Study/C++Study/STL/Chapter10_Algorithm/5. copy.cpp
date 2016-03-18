//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<list>
//
//using namespace std;
//
///*
//	2016-03-18
//	copy 예제
//	컨테이너에 저정한 것과 같은 자료형을 저장하는 
//	다른 컨테이너에 저장하고 싶을 떄 사용
//	복사할때 A를 B로 copy할 때 B는 최소한 A만큼의 크기를 
//	확보하고 있어야 한다.
//	-> copy를 할 떄 미리 공간을 지정해 두어야 한다.
//*/
//
//int main()
//{
//	vector<int> vec1(10);
//	// copy를 할 수 있도롤 미리 공간을 할당
//	vector<int> vec2(10);
//	generate(vec1.begin(), vec1.end(), rand);
//
//	cout << "vec1의 모든 데이터를 vec2에 copy" << endl;
//	copy(vec1.begin(), vec1.end(), vec2.begin());
//	int count = vec2.size();
//
//	for (int i = 0; i < count; i++)
//		cout << vec2[i] << endl;
//
//	cout << "vec1의 모든 데이터를 list1에 copy" << endl;
//	// copy를 할 수 있도롤 미리 공간을 할당
//	list<int> list1(10);
//	copy(vec1.begin(), vec1.end(), list1.begin());
//	for (list<int>::iterator iter = list1.begin(); iter != list1.end(); ++iter)
//		cout << *iter << endl;
//	return 0;
//}