//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<map>
//
//using namespace std;
//
///*
//2016-03-15
//������ ������ Key ������ ����Ͽ� �������� �����ϰ� ������������ ����� ����.
//multi_map�� ����� ��
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
//	// multimap ����
//	multimap<int, Item> items;
//	multimap<int, Item>::iterator iterPos;
//	typedef pair<int, Item> itemPair;
//
//	Item item1;
//	strncpy(item1.name, "��Į", 32);
//	item1.kind = 1;
//	item1.buyMoney = 500;
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
//	// Items�� ������ �߰�(key���� �ߺ����� ����)
//	items.insert(multimap<int, Item>::value_type(item2.buyMoney, item2));
//	items.insert(itemPair(item1.buyMoney, item1));
//	items.insert(itemPair(item3.buyMoney, item3));
//
//	// Items�� ��� �����ʴٸ�
//	if (items.empty() == false)
//		cout << "����� ������ ���� - " << items.size() << endl;
//
//	for (multimap<int, Item>::reverse_iterator iterPos = items.rbegin(); iterPos != items.rend(); ++iterPos)
//		cout << "����: " << iterPos->first << ", �̸� : " << iterPos->second.name << endl;
//
//	// �ߺ��� key������ ã�� ��� �ߺ��� �� �� ���� ó���� �����͸� ����Ų��
//	iterPos = items.find(500);
//	cout << "����: " << iterPos->first << ", �̸� : " << iterPos->second.name << endl;
//
//	if (iterPos == items.end())
//		cout << "������ '��Į'�� �����ϴ�." << endl;
//
//	system("pause");
//	return 0;
//}