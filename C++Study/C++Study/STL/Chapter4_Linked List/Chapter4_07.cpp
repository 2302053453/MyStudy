//#include<iostream>
//#include<list>
//using namespace std;
//
//// 함수 객체 정의
//template <typename T> struct COMPARE_ITEM
//{
//	bool operator() (const T l, const T r) const
//	{
//		// 정렬시에는 올림차순으로 된다.
//		// 내림차순으로 하고싶으면 <를 >로 변경하면 된다
//		return l.itemCd < r.itemCd;
//	}
//};
//
//// 아이템 구조체
//struct Item
//{
//	Item(int itemcd, int buymoney)
//	{
//		itemCd = itemcd;
//		buyMoney = buymoney;
//	}
//
//	int itemCd;	// 아이템코드
//	int buyMoney; // 판매금액
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
//	cout << "sort 올림차순" << endl;
//
//	// 올림차순으로 정렬한다
//	list1.sort();
//
//	list<int>::iterator iterEnd = list1.end();
//	for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//		cout << "list 1 : " << *iterPos << endl;
//
//	//cout << "sort 내림차순" << endl;
//
//	//// 내림차순으로 정렬한다
//	//list1.sort(greater<int>());
//
//	//list<int>::iterator iterEnd = list1.end();
//	//for (list<int>::iterator iterPos = list1.begin(); iterPos != iterEnd; ++iterPos)
//	//	cout << "list 1 : " << *iterPos << endl;
//
//	cout << "sort - 사용자가 정의한 방식으로 정렬" << endl;
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
//	// 정렬한다
//	itemList.sort(COMPARE_ITEM<Item>());
//
//	list<Item>::iterator iterEnd2 = itemList.end();
//	for (list<Item>::iterator iterPos = itemList.begin(); iterPos != iterEnd2; ++iterPos)
//		cout << "list 2 : " << iterPos->itemCd << endl;
//
//
//}