//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
///*
//	2016-03-18
//	find_if (변경 불가 시퀀스 알고리즘, 값을 찾을수는 있으나 변경은 할 수 없다) 예제
//	사용자 정의형에 대하여 사용가능 하다
//	값을 검색할 때 조건자를 받아 해당 조건에 따른 검색을 한다.
//*/
//
//struct User
//{
//	int money;
//	int level;
//};
//
//// find_if조건에 들어갈 함수객체
//// -> inline화된다.
//struct FindMoneyUser
//{
//	bool operator() (User &user) const
//	{
//		return user.money == compareMoney;
//	}
//	int compareMoney;
//};
//
//int main()
//{
//	vector < User> users;
//
//	User user1;
//	user1.level = 10; 
//	user1.money = 2000;
//
//	User user2;
//	user2.level = 5;
//	user2.money = -10;
//
//	User user3;
//	user3.level = 20;
//	user3.money = 35000;
//
//	users.push_back(user1);
//	users.push_back(user2);
//	users.push_back(user3);
//
//	vector<User>::iterator iter;
//	
//	FindMoneyUser findUser;
//	findUser.compareMoney = 2000;
//
//	// find_if로 조건에 맞는 값을 구한다.
//	iter = find_if(users.begin(), users.end(), findUser);
//
//	if (iter != users.end())
//		cout << "소지하고 있는 돈은 : " << iter->money << "입니다" << endl;
//	else
//		cout << "유저가 없습니다" << endl;
//
//	return 0;
//}