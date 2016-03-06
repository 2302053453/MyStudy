//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-04
//	STL LIST 랜덤 접근 예제
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
//		// 3으로 나누어지는 것은 제거한다.
//		if (0 == (*iterPos % 3))
//		{
//			// 삭제 되는 것의 다음 반복자를 저장하고 또 이동하지 않도록 한다.
//			iterPos = list1.erase(iterPos);
//			continue;
//		}
//
//		cout << "list1 : " << *iterPos << endl;
//		iterPos++;
//	}
//
//}