//#include<iostream>
//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
//#include<hash_map>
//using namespace std;
//using namespace stdext;
///*
//	2016-03-11
//	hash map ����(lower_bound, upper_bound)
//	lower_bound : ���ڷ� ���� ���� ���� ���� ���������� �����´�
//	upper_bound : ���ڷ� ���� ���� ���� ���� ���������� �����´�
//*/
//
//
//
//
//// ����ĳ����
//struct GameCharacter
//{
//	// �Ʒ��� ���ڸ� ������ �����ڸ� ������ ����
//	// �� �⺻ �����ڸ� �����ؾ� �����̳ʿ��� ����� �� �ִ�.
//	GameCharacter() { }
//
//	GameCharacter(int charCd, int level, int money)
//	{
//		_charCd = charCd;
//		_level = level;
//		_money = money;
//	}
//
//	int _charCd;	//ĳ���� �ڵ�
//	int _level;		// ĳ���� ����
//	int _money;		// ehs
//};
//
//void main()
//{
//	hash_map<int, GameCharacter> Characters;
//
//	GameCharacter character1(12, 7, 1000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(12, character1));
//	GameCharacter character2(15, 20, 111000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(15, character2));
//	GameCharacter character3(7, 34, 3345000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(7, character3));
//	GameCharacter character4(14, 12, 112200);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(14, character4));
//	GameCharacter character5(25, 3, 5000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(25, character5));
//
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.begin(); iter != Characters.end(); iter++)
//		cout << " ĳ���� �ڵ� : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// lower_bound
//	cout << "lower_bound(12)"<<endl;
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.lower_bound(12); iter != Characters.end(); iter++)
//		cout << " ĳ���� �ڵ� : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// upper_bound
//	cout << "upper_bound(12)" << endl;
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.upper_bound(12); iter != Characters.end(); iter++)
//		cout << " ĳ���� �ڵ� : " << iter->second._charCd << endl;
//	cout << endl;
//	system("PAUSE");
//}