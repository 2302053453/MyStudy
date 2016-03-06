#include<iostream>
#include<vector>
using namespace std;
/*
	2016-03-07
	�¶��� ���ӿ��� �濡 �ִ� ������ �����ϴ� �κ��� vector�� ����Ͽ� ����ÿ�
	���� ���� ����ü�� Ŭ������ ����, �Լ����� �⺻������ �����ȴ�.

	// ���� ����
	struct UserInfo
	{
	char acUserName[21]; // �̸�
	int Level; // ����
	int Exp; // ����ġ
	};

	// ���� ���� ������ �����ϴ� Ŭ����
	// �濡�� �ִ� 6����� ��� �� �� �ִ�.
	// �濡 ��� ���� ���� �� ���� ���� ��� �� ����� ������ �ȴ�.
	class GameRoomUser
	{
	public:
	GameRoomUser() 

	~GameRoomUser() 

	// �濡 ���� �߰�
	bool AddUser(UserInfo& tUserInfo)

	// �濡�� ���� ����.
	// ���� ������ ������ acMasterUserName�� ���ο� ������ �̸��� ���� �ؾ� �ȴ�.
	bool DelUser(char* pcUserName)

	// �濡 ������ ������ ����. ������ true ����
	bool IsEmpty()	

	// �濡 ������ �� á���� ����. �� á�ٸ� true ����
	bool IsFull()

	// Ư�� ������ ����
	UserInfo& GetUserOfName(char* pcName)

	// ������ ���� ����
	UserInfo& GetMasterUser()

	// ���� �������� �濡 ��� �� ������ ����
	UserInfo& GetUserOfLastOrder()	

	bool BanUser(int OrderNum)

	// ��� ������ �����Ѵ�.
	void Clear() 

	vector< UserInfo > Users;
	char acMasterUserName[21]; // ������ �̸�
	};
*/

// ���� ����
struct UserInfo
{
	char acUserName[21]; // �̸�
	int Level; // ����
	int Exp; // ����ġ
};

// ���� ���� ������ �����ϴ� Ŭ����
// �濡�� �ִ� 6����� ��� �� �� �ִ�.
// �濡 ��� ���� ���� �� ���� ���� ��� �� ����� ������ �ȴ�.
class GameRoomUser
{
public:
	GameRoomUser() { }
	
	~GameRoomUser() { Clear();}

	// �濡 ���� �߰�
	bool AddUser(UserInfo& tUserInfo)
	{
		if (IsFull())
			return false;
		else
		{
			Users.push_back(tUserInfo);
			return true;
		}
	}
	// �濡�� ���� ����.
	// ���� ������ ������ acMasterUserName�� ���ο� ������ �̸��� ���� �ؾ� �ȴ�.
	bool DelUser(char* pcUserName)
	{
		if (IsEmpty())
			return false;

		for (vector<UserInfo>::iterator iter = Users.begin(); iter != Users.end(); iter++)
		{
			if (iter->acUserName == pcUserName)
			{ 
				// ���� ������ ����
				if (iter->acUserName == acMasterUserName)
				{
					Users.erase(iter);
					*acMasterUserName = *(iter->acUserName);
				}
				else
					Users.erase(iter);

				return true;
			}
		}
	}
	// �濡 ������ ������ ����. ������ true ����
	bool IsEmpty()	{ return Users.empty();	}
	// �濡 ������ �� á���� ����. �� á�ٸ� true ����
	bool IsFull() { return Users.size() == 6; }
	// Ư�� ������ ����
	UserInfo& GetUserOfName(char* pcName)
	{
		for (vector<UserInfo>::iterator iter = Users.begin(); iter != Users.end(); iter++)
			if (iter->acUserName == pcName)
				return *iter;
	}
	// ������ ���� ����
	UserInfo& GetMasterUser()
	{
		for (vector<UserInfo>::iterator iter = Users.begin(); iter != Users.end(); iter++)
			if (iter->acUserName == acMasterUserName)
				return *iter;
	}
	// ���� �������� �濡 ��� �� ������ ����
	UserInfo& GetUserOfLastOrder()	{	return Users[Users.size()];	}
	// Ư�� ������ ��� �� ������ �i�Ƴ���.
	bool BanUser(int OrderNum) 
	{
		return DelUser(Users[OrderNum - 1].acUserName);
	}
	// ��� ������ �����Ѵ�.
	void Clear() { Users.clear(); }
private:
	vector< UserInfo > Users;
	char acMasterUserName[21]; // ������ �̸�
};