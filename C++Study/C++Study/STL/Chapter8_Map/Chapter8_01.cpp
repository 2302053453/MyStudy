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
//	Map ����
//*/
//
//struct Item
//{
//	char name[32]; // �̸�
//	char kind;	// ����
//	int buyMoney;	// ���� ����
//	int skillCd;	// ��ų �ڵ�
//};
//
//int main()
//{
//	map<char*, Item> items;
//	map<char*, Item>::iterator iterPos;
//	typedef pair<char*, Item> itemPair;
//
//	Item item1;
//	strncpy(item1.name, "��Į", 32);
//	item1.kind = 1;
//	item1.buyMoney = 200;
//	item1.skillCd = 0;
//
//	Item item2;
//	strncpy(item2.name, "�������� ����", 32);
//	item2.kind = 2;
//	item2.buyMoney = 1000;
//	item2.skillCd = 4;
//	
//	Item item3;
//	strncpy(item3.name, "�ظ�", 32);
//	item3.kind = 1;
//	item3.buyMoney = 500;
//	item3.skillCd = 0;
//
//	// Items�� ������ �߰�
//	items.insert(map<char*, Item>::value_type(item2.name, item2));
//	items.insert(itemPair(item1.name, item1));
//
//	// Items�� ��� �����ʴٸ�
//	if (items.empty() == false)
//		cout << "����� ������ ���� - " << items.size() << endl;
//
//	for (iterPos = items.begin(); iterPos != items.end(); ++iterPos)
//		cout << "�̸�: " << iterPos->first << ", ���� : " << iterPos->second.buyMoney << endl;
//
//	// �ڷ������� char*�� ����߱� ������ ���ڿ��� ã�� �� ����.
//	iterPos = items.find("��Į");
//	
//	if (iterPos == items.end())
//		cout << "������ '��Į'�� �����ϴ�." << endl;
//
//	cout << "�ø��������� ���ĵǾ��ִ� map(Key �ڷ�������string ���)" << endl;
//
//	map< string, Item, less<string> > Items2;
//	map< string, Item, less<string> >::iterator IterPos2;
//	Items2.insert(map< string, Item >::value_type(item2.name, item2));
//	Items2.insert(itemPair(item1.name, item1));
//
//	// operator[]�� ����Ͽ� ����
//	Items2[item3.name] = item3;
//	for (IterPos2 = Items2.begin(); IterPos2 != Items2.end(); ++IterPos2)
//	{
//		cout << "�̸�: " << IterPos2->first << ", ����: " << IterPos2->second.buyMoney << endl;
//	}
//	cout << endl;
//	cout << "�ظ��� ������ ��? ";
//	IterPos2 = Items2.find("�ظ�");
//	if (IterPos2 != Items2.end()) {
//		cout << IterPos2->second.buyMoney << endl;
//	}
//	else {
//		cout << "�ظӴ� �����ϴ�" << endl;
//	}
//	cout << endl;
//	// ������ "��Į"�� �����Ѵ�.
//	IterPos2 = Items2.find("��Į");
//	if (IterPos2 != Items2.end()) {
//		Items2.erase(IterPos2);
//	}
//	cout << "Items2�� �ִ� ������ ����: " << Items2.size() << endl;
//	return 0;
//}