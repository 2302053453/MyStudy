//#include<iostream>
//
//// hash map을 사용하려면 #define으로 에러를 지정해 줘애한다
//// unordered map을 대신 사용할 것을 권장한다. 
//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
//#include<hash_map>
//using namespace std;
///*
//	2016-03-11
//	hash map 예제(insert, erase, search)
//	많은 자료에 삽입, 삭제가 빈번하지 않고
//	검색을 해야 할 때 사용 (ex : 온라인게임 유저 계정)
//	추후 사용할 때에는 hash_map 대신 unordered_map으로 대체 할 것(명칭만 다름, 개념과 사용법은 동일하다.)
//*/
//
//
//// hash map은 namespace가 std가 아닌 stdext이다
//using namespace stdext;
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
//
//	GameCharacter character2(15, 20, 111000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(15, character2));
//
//	GameCharacter character3(200, 34, 3345000);
//	Characters.insert(hash_map<int, GameCharacter>::value_type(200, character3));
//
//	// iterator와 begin,end 사용
//	// 저장한 요소를 정방향으로 순회
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.begin(); iter != Characters.end(); iter++)
//		cout << " 캐릭터 코드 : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// rbegin, end 사용
//	for (hash_map<int, GameCharacter>::reverse_iterator iter = Characters.rbegin(); iter != Characters.rend(); iter++)
//		cout << " 캐릭터 코드 : " << iter->second._charCd << endl;
//	cout << endl;
//
//	//Characters에 저장한 요소 수
//	int characterCount = Characters.size();
//
//	// 검색
//	// 캐릭터 코드 15인 캐릭터를 찾는다
//	hash_map<int, GameCharacter>::iterator findIter = Characters.find(15);
//	// 찾지 못했다면 findIter은 end 위치의 반복자가 반환된다
//	if (Characters.end() == findIter)
//		cout << "캐릭터 코드가 15인 캐릭터가 없습니다" << endl;
//	else
//	{
//		cout << "캐릭터 코드가 15인 캐릭터를 찾았습니다." << endl;
//		cout << " 캐릭터 코드 : " << findIter->second._charCd << endl;
//	}
//	cout << endl;
//
//	// 삭제
//	// 캐릭터 코드가 15인 캐릭터를 삭제한다
//	Characters.erase(15);
//	for (hash_map<int, GameCharacter>::iterator iter = Characters.begin(); iter != Characters.end(); iter++)
//		cout << " 캐릭터 코드 : " << iter->second._charCd << endl;
//	cout << endl;
//
//	// 모든 캐릭터를 삭제
//	Characters.erase(Characters.begin(), Characters.end());
//	if (Characters.empty())
//		cout << "Characters는 비어 있습니다" << endl;
//
//}