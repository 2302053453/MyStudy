//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
///*
//	2016-03-18
//	find_if (���� �Ұ� ������ �˰���, ���� ã������ ������ ������ �� �� ����) ����
//	����� �������� ���Ͽ� ��밡�� �ϴ�
//	���� �˻��� �� �����ڸ� �޾� �ش� ���ǿ� ���� �˻��� �Ѵ�.
//*/
//
//struct User
//{
//	int money;
//	int level;
//};
//
//// find_if���ǿ� �� �Լ���ü
//// -> inlineȭ�ȴ�.
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
//	// find_if�� ���ǿ� �´� ���� ���Ѵ�.
//	iter = find_if(users.begin(), users.end(), findUser);
//
//	if (iter != users.end())
//		cout << "�����ϰ� �ִ� ���� : " << iter->money << "�Դϴ�" << endl;
//	else
//		cout << "������ �����ϴ�" << endl;
//
//	return 0;
//}