//#include<iostream>
//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
//#include<hash_map>
//using namespace std;
//using namespace stdext;
///*
//	2016-03-11
//	hash map 예제(lower_bound, upper_bound)
//	lower_bound : 인자로 넣은 값과 같은 값을 시작점으로 가져온다
//	upper_bound : 인자로 넣은 값의 다음 값을 시작점으로 가져온다
//*/
//
//
//
//
//// 게임캐릭터
//struct GameCharacter
//{
//	// 아래의 인자를 가지는 생성자를 정의한 경우는
//	// 꼭 기본 생성자를 정의해야 컨테이너에서 사용할 수 있다.
//	GameCharacter() { }
//
//	GameCharacter(int charCd, int level, int money)
//	{
//		_charCd = charCd;
//		_level = level;
//		_money = money;
//	}
//
//	int _charCd;	//캐릭터 코드
//	int _level;		// 캐릭터 레벨
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
//		cout << " 캐릭터 코드 : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// lower_bound
//	cout << "lower_bound(12)"<<endl;
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.lower_bound(12); iter != Characters.end(); iter++)
//		cout << " 캐릭터 코드 : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// upper_bound
//	cout << "upper_bound(12)" << endl;
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.upper_bound(12); iter != Characters.end(); iter++)
//		cout << " 캐릭터 코드 : " << iter->second._charCd << endl;
//	cout << endl;
//	system("PAUSE");
//}