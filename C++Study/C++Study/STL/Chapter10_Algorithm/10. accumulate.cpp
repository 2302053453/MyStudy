//#include<vector>
//#include<algorithm>
//#include<numeric>
//#include<iostream>
//
//using namespace std;
///*
//	2016-03-18
//	accumulate ����
//	������ ������ ���� ������ ��� ���� ���� ����Ѵ�.
//	��, �����ڸ� ����ϸ� ���ϱ� �̿��� ���굵 �� �� �ִ�.
//*/
//
//struct  User
//{
//	int uID;
//	int money;
//};
//
//// �����ڷ� ������ �ƴ� �E���� ����
//struct USER_MONEY_ADD
//{
//	User operator()(const User &user1, const User &user2)
//	{
//		User user;
//		user.money = user1.money - user2.money;
//		return user;
//	}
//};
//
//int main()
//{
//	User user1;
//	user1.uID = 1; 
//	user1.money = 1000;
//	User user2;
//	user2.uID = 2;
//	user2.money = 2000;
//	User user3;
//	user3.uID = 3;
//	user3.money = 3000;
//	User user4;
//	user4.uID = 3;
//	user4.money = 3000;
//
//	vector<User> users;
//	users.push_back(user1);
//	users.push_back(user2);
//	users.push_back(user3);
//	users.push_back(user4);
//
//	User initUser;
//	initUser.money = 300;
//
//	// accumulate�� ����Ͽ� �հ踦 ���Ѵ�.
//	User result = accumulate(users.begin(), users.end(), initUser, USER_MONEY_ADD());
//	cout << result.money << endl;
//
//	return 0;
//}
//
