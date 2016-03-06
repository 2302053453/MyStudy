//#include<iostream>
//#include<list>
//using namespace std;
///*
//	2016-03-03
//	STL LIST 예제
//*/
//
//// 아이템 구조체
//struct Item
//{
//	Item(int itemCd, int buyMoney)
//	{
//		itemcd = itemCd;
//		buymoney = buyMoney;
//	}
//
//	int itemcd; // 아이템 코드
//	int buymoney; // 판매금액
//};
//
//void main()
//{
//	list<Item> Itemlist;
//	
//	// 앞에 데이터 추가
//	Item item1(1, 2000);
//	Itemlist.push_front(item1);
//
//	Item item2(2, 1000);
//	Itemlist.push_front(item2);
//
//	// 뒤에 데이터 추가
//	Item item3(3, 3000);
//	Itemlist.push_back(item3);
//
//	Item item4(4, 4000);
//	Itemlist.push_back(item4);
//
//	// 아이템 코드 번호가 2, 1, 3, 4의 순서로 출력된다.
//	list<Item>::iterator iterEnd = Itemlist.end();
//	for (list<Item>::iterator iterPos = Itemlist.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "아이템 코드 : " << iterPos->itemcd << endl;
//
//	// 앞에 있는 데이터를 삭제한다.
//	Itemlist.pop_front();
//
//	// 앞에 있는 데이터의 참조를 리턴한다.
//	Item front_Item = Itemlist.front();
//	// 아이템 코드 1이 출력된다.
//	cout << "아이템 코드 : " << front_Item.itemcd << endl;
//
//	// 마지막에 있는 데이터를 삭제한다.
//	Itemlist.pop_back();
//
//	// 마지막에 있는 데이터의 참조를 리턴한다.
//	Item back_Item = Itemlist.back();
//	// 아이템 코드 3이 출력된다.
//	cout << "아이템 코드 : " << back_Item.itemcd << endl;
//
//	// 저장된 데이터가 있는가?
//	if (false == Itemlist.empty())
//	{
//		list<Item>::size_type count = Itemlist.size();
//		cout << "남아 있는 아이템 개수 : " << count << endl;
//	}
//
//	// 모든 데이터를 지운다
//	Itemlist.clear();
//	list<Item>::size_type count = Itemlist.size();
//	cout << "남아 있는 아이템 개수 : " << count << endl;
//
//}