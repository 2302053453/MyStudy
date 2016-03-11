//#include<iostream>
//
//// hash map�� ����Ϸ��� #define���� ������ ������ ����Ѵ�
//// unordered map�� ��� ����� ���� �����Ѵ�. 
//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
//#include<hash_map>
//using namespace std;
///*
//	2016-03-11
//	hash map ����(insert, erase, search)
//	���� �ڷῡ ����, ������ ������� �ʰ�
//	�˻��� �ؾ� �� �� ��� (ex : �¶��ΰ��� ���� ����)
//	���� ����� ������ hash_map ��� unordered_map���� ��ü �� ��(��Ī�� �ٸ�, ����� ������ �����ϴ�.)
//*/
//
//
//// hash map�� namespace�� std�� �ƴ� stdext�̴�
//using namespace stdext;
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
//
//	GameCharacter character2(15, 20, 111000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(15, character2));
//
//	GameCharacter character3(200, 34, 3345000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(200, character3));
//
//	// iterator�� begin,end ���
//	// ������ ��Ҹ� ���������� ��ȸ
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.begin(); iter != Characters.end(); iter++)
//		cout << " ĳ���� �ڵ� : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// rbegin, end ���
//	for (hash_map<int, GameCharacter>::reverse_iterator iter = Characters.rbegin(); iter != Characters.rend(); iter++)
//		cout << " ĳ���� �ڵ� : " << iter->second._charCd << endl;
//	cout << endl;
//
//	//Characters�� ������ ��� ��
//	int characterCount = Characters.size();
//
//	// �˻�
//	// ĳ���� �ڵ� 15�� ĳ���͸� ã�´�
//	hash_map<int, GameCharacter>::iterator findIter = Characters.find(15);
//	// ã�� ���ߴٸ� findIter�� end ��ġ�� �ݺ��ڰ� ��ȯ�ȴ�
//	if (Characters.end() == findIter)
//		cout << "ĳ���� �ڵ尡 15�� ĳ���Ͱ� �����ϴ�" << endl;
//	else
//	{
//		cout << "ĳ���� �ڵ尡 15�� ĳ���͸� ã�ҽ��ϴ�." << endl;
//		cout << " ĳ���� �ڵ� : " << findIter->second._charCd << endl;
//	}
//	cout << endl;
//
//	// ����
//	// ĳ���� �ڵ尡 15�� ĳ���͸� �����Ѵ�
//	Characters.erase(15);
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.begin(); iter != Characters.end(); iter++)
//		cout << " ĳ���� �ڵ� : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// ��� ĳ���͸� ����
//	Characters.erase(Characters.begin(), Characters.end());
//	if (Characters.empty())
//		cout << "Characters�� ��� �ֽ��ϴ�" << endl;
//
//}