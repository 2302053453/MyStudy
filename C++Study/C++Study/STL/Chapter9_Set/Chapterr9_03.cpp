//#include<iostream>
//#include<functional>
//#include<set>
//
//using namespace std;
//
///*
//	2016-03-18
//	����� class ���� �� ��� ����
//*/
//
//class Player
//{
//public:
//	Player(int m_level) 
//	{
//		level = m_level;
//	}
//	Player() {}
//
//	int level;
//	double exp;
//};
//
//// ������ ���� ������ ����
//template<class T>
//struct LEVEL_COMPARE : public binary_function< T, T, bool>
//{
//	bool operator() (const T& player1, const T& player2) const
//	{
//		return player1->level > player2->level;
//	}
//};
//
//int main()
//{
//	set<Player*, LEVEL_COMPARE<Player*>> playerList;
//
//	Player* player1 = new Player(10);
//	playerList.insert(player1);
//	Player* player2 = new Player(5);
//	playerList.insert(player2);
//	Player* player3 = new Player(15);
//	playerList.insert(player3);
//	Player* player4 = new Player(45);
//	playerList.insert(player4);
//
//	// �� �������� ��� ( ������ ���� ������)
//	for (set<Player*, LEVEL_COMPARE<Player*>>::iterator iter = playerList.begin(); iter != playerList.end(); ++iter)
//		cout << (*iter)->level << endl;
//	cout << endl;
//
//	// �� �������� ��� ( ������ ���� ������)
//	for (set<Player*, LEVEL_COMPARE<Player*>>::iterator iter = playerList.begin(); iter != playerList.end(); ++iter)
//		cout << (*iter)->level << endl;
//	cout << endl;
//
//	// �� �������� ��� ( ������ ���� ������)
//	for (set<Player*, LEVEL_COMPARE<Player*>>::reverse_iterator iter = playerList.rbegin(); iter != playerList.rend(); ++iter)
//		cout << (*iter) << endl;
//	cout << endl;
//
//	// player �˻�
//	set<Player*, LEVEL_COMPARE<Player*>>::iterator iter2 = playerList.find(player4);
//	
//	cout << (*iter2) << endl;
//	if (iter2 != playerList.end())
//		cout << "Player�� ã�ҽ��ϴ� : "<< (*iter2)->level << endl;
//	else
//	{
//		cout << "Player�� ��ã�ҽ��ϴ�" << endl;
//	}
//
//	cout << endl;
//	cout << "Total Player Count : " << playerList.size() << endl;
//	cout << endl;
//	
//	playerList.clear();
//	if (playerList.empty())
//		cout << "Player�� �����ϴ�." << endl;
//
//	delete player1;
//	delete player2;
//	delete player3;
//	delete player4;
//	return 0;
//}