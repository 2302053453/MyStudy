//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector 예제
//*/
//
//// 방의 유저 정보
//struct RoomUser
//{
//	int charCd;	// 캐릭터 코드
//	int level;	// 레벨
//};
//
//void main()
//{
//	// 유저1
//	RoomUser roomUser1;
//	roomUser1.charCd = 1;
//	roomUser1.level = 10;
//
//	// 유저2
//	RoomUser roomUser2;
//	roomUser2.charCd = 2;
//	roomUser2.level = 5;
//
//	// 유저3
//	RoomUser roomUser3;
//	roomUser3.charCd = 3;
//	roomUser3.level = 12;
//
//	// 방의 유저들을 저장할 vector
//	vector<RoomUser> roomUsers;
//
//	// 추가
//	roomUsers.push_back(roomUser1);
//	roomUsers.push_back(roomUser2);
//	roomUsers.push_back(roomUser3);
//
//	// 방에 있는 유저 수
//	int userCount = roomUsers.size();
//
//	// 방에 있는 유저 정보 출력
//	// 반복자로 접근 - 순방향
//	for (vector<RoomUser>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
//	{
//		cout << "유저코드 : " << iter->charCd << endl;
//		cout << "유저레벨 : " << iter->level << endl;
//	}
//
//	// 반복자로 접근 - 역방향
//	for (vector<RoomUser>::reverse_iterator iter = roomUsers.rbegin(); iter != roomUsers.rend(); iter++)
//	{
//		cout << "유저코드 : " << iter->charCd << endl;
//		cout << "유저레벨 : " << iter->level << endl;
//	}
//
//	// 배열방식으로 접근
//	for (int i = 0; i < userCount; i++)
//	{
//		cout << "유저코드 : " << roomUsers[i].charCd << endl;
//		cout << "유저레벨 : " << roomUsers[i].level << endl;
//	}
//
//	// 첫번째 유저 데이터 접근
//	RoomUser& firstRoomUser = roomUsers.front();
//	cout << "유저레벨 : " << firstRoomUser.level << endl;
//	// 마지막 데이터 접근
//	RoomUser& lastRoomUser = roomUsers.back();
//	cout << "유저레벨 : " << lastRoomUser.level << endl;
//	// at사용하여 두 번째 유저의 레벨을 출력
//	RoomUser& roomUserAt = roomUsers.at(1);
//	cout << "유저레벨 : " << roomUserAt.level << endl;
//	// 삭제
//	roomUsers.pop_back();
//
//	cout << "남은 유저수 : " << roomUsers.size() << endl;
//
//	if (false == roomUsers.empty())
//	{
//		roomUsers.clear();
//	}
//	cout << "남은 유저수 : " << roomUsers.size() << endl;
//
//	system("PAUSE");
//}
