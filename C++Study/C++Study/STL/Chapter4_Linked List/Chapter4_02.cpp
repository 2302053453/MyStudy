//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-03
//	STL LIST insert ����
//*/
//
//void main()
//{
//	list<int> list1;
//	list1.push_back(20);
//	list1.push_back(30);
//
//	cout << "���� �׽�Ʈ 1" << endl;
//	// ù��° ��ġ�� �����Ѵ�.
//	list<int>::iterator iterInserrtPos = list1.begin();
//	list1.insert(iterInserrtPos, 100);
//
//	list<int>::iterator iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	cout << "���� �׽�Ʈ 2" << endl;
//	// �� ��° ��ġ�� 200�� 2�� �����Ѵ�.
//	iterInserrtPos = list1.begin();
//	iterInserrtPos++;
//	list1.insert(iterInserrtPos, 2, 200);
//	
//	iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	cout << "���� �׽�Ʈ 3" << endl;
//
//	list<int> list2;
//	list2.push_back(1000);
//	list2.push_back(2000);
//	list2.push_back(3000);
//
//	// �� ��° ��ġ�� list2�� ��� �����͸� �����ѵ�.
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