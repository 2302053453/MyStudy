//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
///*
//	2016-03-18
//	generate (���� ���� ������ �˰���) ����
//	Ư�������� �������� ���� Ư�������� ä��� ���� �� ��� 
//	��, insert�� �ƴ� update�̴�( ������ ���� �����Ų��.)
//*/
//
//struct User
//{
//	int uID;
//	int raceType;
//	int sex;
//	int money;
//};
//
//struct  SetUserInfo
//{
//	SetUserInfo() { userCount = 0; }
//
//	User operator()()
//	{
//		User user;
//		++userCount;
//		user.uID = userCount;
//		user.money = 2000;
//
//		if (0 == (userCount % 2))
//		{
//			user.raceType = 1;
//			user.sex = 1;
//			user.money += 1000;
//		}
//		else
//		{
//			user.raceType = 0;
//			user.sex = 0;
//		}
//
//		return user;
//	}
//
//	int userCount;
//};
//
//int main()
//{
//	vector<User> users(5);
//
//	generate(users.begin(), users.end(), SetUserInfo());
//
//	char szUserInfo[256] = { 0, };
//
//	vector<User>::iterator iter;
//
//	for (iter = users.begin(); iter != users.end(); ++iter)
//	{
//		sprintf(szUserInfo, "UID %d, RaceType : %d", iter->uID, iter->raceType);
//		cout << szUserInfo << endl;
//	}
//
//	return 0;
//}
//
//
//
