//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-04
//	STL LIST ���� ���� ����
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
//	list<int>::iterator iterPos = list1.begin();
//	iterPos++;
//	while (iterPos != list1.end())
//	{
//		// 3���� ���������� ���� �����Ѵ�.
//		if (0 == (*iterPos % 3))
//		{
//			// ���� �Ǵ� ���� ���� �ݺ��ڸ� �����ϰ� �� �̵����� �ʵ��� �Ѵ�.
//			iterPos = list1.erase(iterPos);
//			continue;
//		}
//
//		cout << "list1 : " << *iterPos << endl;
//		iterPos++;
//	}
//
//}