//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-03
//	STL LIST insert 예제
//*/
//
//void main()
//{
//	list<int> list1;
//	list1.push_back(20);
//	list1.push_back(30);
//
//	cout << "삽입 테스트 1" << endl;
//	// 첫번째 위치에 삽입한다.
//	list<int>::iterator iterInserrtPos = list1.begin();
//	list1.insert(iterInserrtPos, 100);
//
//	list<int>::iterator iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	cout << "삽입 테스트 2" << endl;
//	// 두 번째 위치에 200을 2개 삽입한다.
//	iterInserrtPos = list1.begin();
//	iterInserrtPos++;
//	list1.insert(iterInserrtPos, 2, 200);
//	
//	iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	cout << "삽입 테스트 3" << endl;
//
//	list<int> list2;
//	list2.push_back(1000);
//	list2.push_back(2000);
//	list2.push_back(3000);
//
//	// 두 번째 위치에 list2의 모든 데이터를 삽입한디.
//	iterInserrtPos = list1.begin();
//	
//	list1.insert(++iterInserrtPos, list2.begin(), list2.end());
//
//	iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//
//}