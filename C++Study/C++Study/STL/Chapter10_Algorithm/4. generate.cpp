//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
///*
//	2016-03-18
//	generate (변경 가능 시퀀스 알고리즘) 예제
//	특정구간을 동일하지 않은 특정값으로 채우고 싶을 때 사용 
//	단, insert가 아닌 update이다( 기존의 값을 변경시킨다.)
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
