//#include<iostream>
//#include<vector>
//using namespace std;
///*
//	2016-03-06
//	vector ����
//*/
//
//// ���� ���� ����
//struct RoomUser
//{
//	int charCd;	// ĳ���� �ڵ�
//	int level;	// ����
//};
//
//void main()
//{
//	// ����1
//	RoomUser roomUser1;
//	roomUser1.charCd = 1;
//	roomUser1.level = 10;
//
//	// ����2
//	RoomUser roomUser2;
//	roomUser2.charCd = 2;
//	roomUser2.level = 5;
//
//	// ����3
//	RoomUser roomUser3;
//	roomUser3.charCd = 3;
//	roomUser3.level = 12;
//
//	// ���� �������� ������ vector
//	vector<RoomUser> roomUsers;
//
//	// �߰�
//	roomUsers.push_back(roomUser1);
//	roomUsers.push_back(roomUser2);
//	roomUsers.push_back(roomUser3);
//
//	// �濡 �ִ� ���� ��
//	int userCount = roomUsers.size();
//
//	// �濡 �ִ� ���� ���� ���
//	// �ݺ��ڷ� ���� - ������
//	for (vector<RoomUser>::iterator iter = roomUsers.begin(); iter != roomUsers.end(); iter++)
//	{
//		cout << "�����ڵ� : " << iter->charCd << endl;
//		cout << "�������� : " << iter->level << endl;
//	}
//
//	// �ݺ��ڷ� ���� - ������
//	for (vector<RoomUser>::reverse_iterator iter = roomUsers.rbegin(); iter != roomUsers.rend(); iter++)
//	{
//		cout << "�����ڵ� : " << iter->charCd << endl;
//		cout << "�������� : " << iter->level << endl;
//	}
//
//	// �迭������� ����
//	for (int i = 0; i < userCount; i++)
//	{
//		cout << "�����ڵ� : " << roomUsers[i].charCd << endl;
//		cout << "�������� : " << roomUsers[i].level << endl;
//	}
//
//	// ù��° ���� ������ ����
//	RoomUser& firstRoomUser = roomUsers.front();
//	cout << "�������� : " << firstRoomUser.level << endl;
//	// ������ ������ ����
//	RoomUser& lastRoomUser = roomUsers.back();
//	cout << "�������� : " << lastRoomUser.level << endl;
//	// at����Ͽ� �� ��° ������ ������ ���
//	RoomUser& roomUserAt = roomUsers.at(1);
//	cout << "�������� : " << roomUserAt.level << endl;
//	// ����
//	roomUsers.pop_back();
//
//	cout << "���� ������ : " << roomUsers.size() << endl;
//
//	if (false == roomUsers.empty())
//	{
//		roomUsers.clear();
//	}
//	cout << "���� ������ : " << roomUsers.size() << endl;
//
//	system("PAUSE");
//}
