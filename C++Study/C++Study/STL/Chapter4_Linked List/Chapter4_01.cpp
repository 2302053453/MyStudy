//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-03
//	STL LIST ����
//*/
//
//// ������ ����ü
//struct Item
//{
//	Item(int itemCd, int buyMoney)
//	{
//		itemcd = itemCd;
//		buymoney = buyMoney;
//	}
//
//	int itemcd; // ������ �ڵ�
//	int buymoney; // �Ǹűݾ�
//};
//
//void main()
//{
//	list<Item> Itemlist;
//	
//	// �տ� ������ �߰�
//	Item item1(1, 2000);
//	Itemlist.push_front(item1);
//
//	Item item2(2, 1000);
//	Itemlist.push_front(item2);
//
//	// �ڿ� ������ �߰�
//	Item item3(3, 3000);
//	Itemlist.push_back(item3);
//
//	Item item4(4, 4000);
//	Itemlist.push_back(item4);
//
//	// ������ �ڵ� ��ȣ�� 2, 1, 3, 4�� ������ ��µȴ�.
//	list<Item>::iterator iterEnd = Itemlist.end();
//	for (list<Item>::iterator iterPos = Itemlist.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "������ �ڵ� : " << iterPos->itemcd << endl;
//
//	// �տ� �ִ� �����͸� �����Ѵ�.
//	Itemlist.pop_front();
//
//	// �տ� �ִ� �������� ������ �����Ѵ�.
//	Item front_Item = Itemlist.front();
//	// ������ �ڵ� 1�� ��µȴ�.
//	cout << "������ �ڵ� : " << front_Item.itemcd << endl;
//
//	// �������� �ִ� �����͸� �����Ѵ�.
//	Itemlist.pop_back();
//
//	// �������� �ִ� �������� ������ �����Ѵ�.
//	Item back_Item = Itemlist.back();
//	// ������ �ڵ� 3�� ��µȴ�.
//	cout << "������ �ڵ� : " << back_Item.itemcd << endl;
//
//	// ����� �����Ͱ� �ִ°�?
//	if (false == Itemlist.empty())
//	{
//		list<Item>::size_type count = Itemlist.size();
//		cout << "���� �ִ� ������ ���� : " << count << endl;
//	}
//
//	// ��� �����͸� �����
//	Itemlist.clear();
//	list<Item>::size_type count = Itemlist.size();
//	cout << "���� �ִ� ������ ���� : " << count << endl;
//
//}