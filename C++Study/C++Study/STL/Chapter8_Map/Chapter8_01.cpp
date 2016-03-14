//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<map>
//
//
//using namespace std;
//
///*
//	2016-03-15
//	Map 예제
//*/
//
//struct Item
//{
//	char name[32]; // 이름
//	char kind;	// 종류
//	int buyMoney;	// 구입 가격
//	int skillCd;	// 스킬 코드
//};
//
//int main()
//{
//	map<char*, Item> items;
//	map<char*, Item>::iterator iterPos;
//	typedef pair<char*, Item> itemPair;
//
//	Item item1;
//	strncpy(item1.name, "긴칼", 32);
//	item1.kind = 1;
//	item1.buyMoney = 200;
//	item1.skillCd = 0;
//
//	Item item2;
//	strncpy(item2.name, "성스러운 방패", 32);
//	item2.kind = 2;
//	item2.buyMoney = 1000;
//	item2.skillCd = 4;
//	
//	Item item3;
//	strncpy(item3.name, "해머", 32);
//	item3.kind = 1;
//	item3.buyMoney = 500;
//	item3.skillCd = 0;
//
//	// Items에 아이템 추가
//	items.insert(map<char*, Item>::value_type(item2.name, item2));
//	items.insert(itemPair(item1.name, item1));
//
//	// Items가 비어 있지않다면
//	if (items.empty() == false)
//		cout << "저장된 아이템 개수 - " << items.size() << endl;
//
//	for (iterPos = items.begin(); iterPos != items.end(); ++iterPos)
//		cout << "이름: " << iterPos->first << ", 가격 : " << iterPos->second.buyMoney << endl;
//
//	// 자료형으로 char*을 사용했기 때문에 문자열로 찾을 수 없다.
//	iterPos = items.find("긴칼");
//	
//	if (iterPos == items.end())
//		cout << "아이템 '긴칼'이 없습니다." << endl;
//
//	cout << "올림차순으로 정렬되어있는 map(Key 자료형으로string 사용)" << endl;
//
//	map< string, Item, less<string> > Items2;
//	map< string, Item, less<string> >::iterator IterPos2;
//	Items2.insert(map< string, Item >::value_type(item2.name, item2));
//	Items2.insert(itemPair(item1.name, item1));
//
//	// operator[]를 사용하여 저장
//	Items2[item3.name] = item3;
//	for (IterPos2 = Items2.begin(); IterPos2 != Items2.end(); ++IterPos2)
//	{
//		cout << "이름: " << IterPos2->first << ", 가격: " << IterPos2->second.buyMoney << endl;
//	}
//	cout << endl;
//	cout << "해머의 가격은 얼마? ";
//	IterPos2 = Items2.find("해머");
//	if (IterPos2 != Items2.end()) {
//		cout << IterPos2->second.buyMoney << endl;
//	}
//	else {
//		cout << "해머는 없습니다" << endl;
//	}
//	cout << endl;
//	// 아이템 "긴칼"을 삭제한다.
//	IterPos2 = Items2.find("긴칼");
//	if (IterPos2 != Items2.end()) {
//		Items2.erase(IterPos2);
//	}
//	cout << "Items2에 있는 아이템 개수: " << Items2.size() << endl;
//	return 0;
//}