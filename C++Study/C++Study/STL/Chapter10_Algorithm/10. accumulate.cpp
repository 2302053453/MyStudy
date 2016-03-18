//#include<vector>
//#include<algorithm>
//#include<numeric>
//#include<iostream>
//
//using namespace std;
///*
//	2016-03-18
//	accumulate 예제
//	지정된 구간에 속한 값들을 모든 더한 값을 계산한다.
//	단, 조건자를 사용하면 더하기 이외의 연산도 할 수 있다.
//*/
//
//struct  User
//{
//	int uID;
//	int money;
//};
//
//// 조건자로 덧셈이 아닌 뺼셈을 수행
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
//	// accumulate를 사용하여 합계를 구한다.
//	User result = accumulate(users.begin(), users.end(), initUser, USER_MONEY_ADD());
//	cout << result.money << endl;
//
//	return 0;
//}
//
