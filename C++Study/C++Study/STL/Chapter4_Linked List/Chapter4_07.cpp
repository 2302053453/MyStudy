//#include<iostream>
//#include<list>
//using namespace std;
//
//// �Լ� ��ü ����
//template <typename T> struct COMPARE_ITEM
//{
//	bool operator() (const T l, const T r) const
//	{
//		// ���Ľÿ��� �ø��������� �ȴ�.
//		// ������������ �ϰ������ <�� >�� �����ϸ� �ȴ�
//		return l.itemCd < r.itemCd;
//	}
//};
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
//	int itemCd;	// �������ڵ�
//	int buyMoney; // �Ǹűݾ�
//};
//
//void main()
//{
//	list<int> list1;
//	list1.push_back(20);
//	list1.push_back(10);
//	list1.push_back(35);
//	list1.push_back(15);
//	list1.push_back(12);
//
//	cout << "sort �ø�����" << endl;
//
//	// �ø��������� �����Ѵ�
//	list1.sort();
//
//	list<int>::iterator iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	//cout << "sort ��������" << endl;
//
//	//// ������������ �����Ѵ�
//	//list1.sort(greater<int>());
//
//	//list<int>::iterator iterEnd = list1.end();
//	//for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//	//	cout << "list 1 : " << *iterPos << endl;
//
//	cout << "sort - ����ڰ� ������ ������� ����" << endl;
//
//	list<Item> itemList;
//
//	Item item1(20, 100);
//	itemList.push_back(item1);
//	Item item2(10, 200);
//	itemList.push_back(item2);
//	Item item3(7, 300);
//	itemList.push_back(item3);
//
//
//	// �����Ѵ�
//	itemList.sort(COMPARE_ITEM<Item>());
//
//	list<Item>::iterator iterEnd2 = itemList.end();
//	for (list<Item>::iterator iterPos = itemList.begin(); iterPos != iterEnd2; ++iterPos)
//		cout << "list 2 : " << iterPos->itemCd << endl;
//
//
//}