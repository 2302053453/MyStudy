//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-04
//	STL LIST erase ����
//*/
//
//void main()
//{
//	list<int> list1;
//	list1.push_back(10);
//	list1.push_back(20);
//	list1.push_back(30);
//	list1.push_back(40);
//	list1.push_back(50);
//
//	cout << "erase �׽�Ʈ 1" << endl;
//	// ù ��° ������ ����
//	list1.erase(list1.begin());
//
//	// 20,30,40,50 ���
//	list<int>::iterator iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	cout << "erase �׽�Ʈ 2" << endl;
//	// �� ��° �����ͺ��� ���������� �����Ѵ�.
//	list<int>::iterator iterPos = list1.begin();
//	iterPos++;
//	list1.erase(iterPos, list1.end());
//
//	iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//}