//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-05
//	STL LIST remove ����
//*/
//
//
//// ������ ����ü
//struct Item
//{
//	Item(int itemcd, int buymoney)
//	{
//		itemCd = itemcd;
//		buyMoney = buymoney;
//	}
//
//	int itemCd;	// ������ �ڵ�
//	int buyMoney;	// �Ǹ� �ݾ�
//};
//void main()
//{
//	list<int> list1;
//	list1.push_back(10);
//	list1.push_back(20);
//	list1.push_back(20);
//	list1.push_back(30);
//
//	list<int>::iterator iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	cout << "remove �׽�Ʈ 1" << endl;
//	list1.remove(20);
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	cout << "remove �׽�Ʈ 2 - ����ü�� ���� " << endl;
//	// Item �����͸� ��ƾ��Ѵ�.
//	list<Item*> itemList;
//	itemList.push_back(new Item(10, 100));
//	itemList.push_back(new Item(20, 200));
//	Item* item = new Item(30, 300);
//	itemList.remove(item);
//
//	list<Item*>::iterator itemEnd = itemList.end();
//	for (list<Item*>::iterator iterPos = itemList.begin(); iterPos != itemEnd; ++iterPos)
//		cout << "list 1 : " << (*iterPos)->itemCd << endl;
//	
//	system("PAUSE");
//}