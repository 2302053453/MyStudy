//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<map>
//
//using namespace std;
//
///*
//2016-03-15
//아이템 가격을 Key 값으로 사용하여 아이템을 저장하고 내림차순으로 출력해 보라.
//multi_map을 사용할 것
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
//	// multimap 선언
//	multimap<int, Item> items;
//	multimap<int, Item>::iterator iterPos;
//	typedef pair<int, Item> itemPair;
//
//	Item item1;
//	strncpy(item1.name, "긴칼", 32);
//	item1.kind = 1;
//	item1.buyMoney = 500;
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
//	// Items에 아이템 추가(key값이 중복으로 들어간다)
//	items.insert(multimap<int, Item>::value_type(item2.buyMoney, item2));
//	items.insert(itemPair(item1.buyMoney, item1));
//	items.insert(itemPair(item3.buyMoney, item3));
//
//	// Items가 비어 있지않다면
//	if (items.empty() == false)
//		cout << "저장된 아이템 개수 - " << items.size() << endl;
//
//	for (multimap<int, Item>::reverse_iterator iterPos = items.rbegin(); iterPos != items.rend(); ++iterPos)
//		cout << "가격: " << iterPos->first << ", 이름 : " << iterPos->second.name << endl;
//
//	// 중복된 key값으로 찾을 경우 중복된 값 중 제일 처음의 데이터를 가리킨다
//	iterPos = items.find(500);
//	cout << "가격: " << iterPos->first << ", 이름 : " << iterPos->second.name << endl;
//
//	if (iterPos == items.end())
//		cout << "아이템 '긴칼'이 없습니다." << endl;
//
//	system("pause");
//	return 0;
//}