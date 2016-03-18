//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
///*
//	2016-03-18
//	 for_each 예제
//	 - 순차적으로 컨테이너들에 담긴 데이터를 
//	   함수의 파라메터로 넘겨서 함수를 실행시킨다.
//*/
//
//struct User
//{
//	int uID;
//	int playTime;
//};
//
//struct UpdatePlayTime
//{
//	void operator() (User &user)
//	{
//		user.playTime += playtime;
//	}
//
//	int playtime;
//};
//
//int main()
//{
//	vector<User> users;
//
//	User user1; user1.uID = 1; user1.playTime = 40000;
//	User user2; user1.uID = 2; user1.playTime = 0;
//	User user3; user1.uID = 3; user1.playTime = 25000;
//
//	users.push_back(user1);
//	users.push_back(user2);
//	users.push_back(user3);
//
//	vector<User>::iterator iter;
//	for (iter = users.begin(); iter != users.end(0; ++iter)
//		cout << iter->uID <<"의 플레이시간 : " << iter->playTime << endl;
//
//	UpdatePlayTime updateTime;
//		updateTime.playtime = 200;
//	
//	// for_each를 통하여 값 변경
//	for_each(users.begin()+1, users.end(), updateTime);
//
//	for (iter = users.begin(); iter != users.end(0; ++iter)
//		cout << iter->uID << "의 플레이시간 : " << iter->playTime << endl;
//
//	return 0;
//}