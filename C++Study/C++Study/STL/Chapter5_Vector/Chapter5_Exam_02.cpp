#include<iostream>
#include<vector>
using namespace std;
/*
	2016-03-07
	온라인 게임에서 방에 있는 유저를 관리하는 부분을 vector르 사옹하여 만드시오
	유저 정보 구조체와 클래스의 변수, 함수명은 기본적으로 제공된다.

	// 유저 정보
	struct UserInfo
	{
	char acUserName[21]; // 이름
	int Level; // 레벨
	int Exp; // 경험치
	};

	// 게임 방의 유저를 관리하는 클래스
	// 방에는 최대 6명까지 들어 갈 수 있다.
	// 방에 들어 오는 순서 중 가장 먼저 들어 온 사람이 방장이 된다.
	class GameRoomUser
	{
	public:
	GameRoomUser() 

	~GameRoomUser() 

	// 방에 유저 추가
	bool AddUser(UserInfo& tUserInfo)

	// 방에서 유저 삭제.
	// 만약 방장이 나가면 acMasterUserName에 새로운 방장의 이름을 설정 해야 된다.
	bool DelUser(char* pcUserName)

	// 방에 유저가 없는지 조사. 없으면 true 리턴
	bool IsEmpty()	

	// 방에 유저가 꽉 찼는지 조사. 꽉 찼다면 true 리턴
	bool IsFull()

	// 특정 유저의 정보
	UserInfo& GetUserOfName(char* pcName)

	// 방장의 유저 정보
	UserInfo& GetMasterUser()

	// 가장 마지막에 방에 들어 온 유저의 정보
	UserInfo& GetUserOfLastOrder()	

	bool BanUser(int OrderNum)

	// 모든 유저를 삭제한다.
	void Clear() 

	vector< UserInfo > Users;
	char acMasterUserName[21]; // 방장의 이름
	};
*/

// 유저 정보
struct UserInfo
{
	char acUserName[21]; // 이름
	int Level; // 레벨
	int Exp; // 경험치
};

// 게임 방의 유저를 관리하는 클래스
// 방에는 최대 6명까지 들어 갈 수 있다.
// 방에 들어 오는 순서 중 가장 먼저 들어 온 사람이 방장이 된다.
class GameRoomUser
{
public:
	GameRoomUser() { }
	
	~GameRoomUser() { Clear();}

	// 방에 유저 추가
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
	// 방에서 유저 삭제.
	// 만약 방장이 나가면 acMasterUserName에 새로운 방장의 이름을 설정 해야 된다.
	bool DelUser(char* pcUserName)
	{
		if (IsEmpty())
			return false;

		for (vector<UserInfo>::iterator iter = Users.begin(); iter != Users.end(); iter++)
		{
			if (iter->acUserName == pcUserName)
			{ 
				// 나간 유저가 방장
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
	// 방에 유저가 없는지 조사. 없으면 true 리턴
	bool IsEmpty()	{ return Users.empty();	}
	// 방에 유저가 꽉 찼는지 조사. 꽉 찼다면 true 리턴
	bool IsFull() { return Users.size() == 6; }
	// 특정 유저의 정보
	UserInfo& GetUserOfName(char* pcName)
	{
		for (vector<UserInfo>::iterator iter = Users.begin(); iter != Users.end(); iter++)
			if (iter->acUserName == pcName)
				return *iter;
	}
	// 방장의 유저 정보
	UserInfo& GetMasterUser()
	{
		for (vector<UserInfo>::iterator iter = Users.begin(); iter != Users.end(); iter++)
			if (iter->acUserName == acMasterUserName)
				return *iter;
	}
	// 가장 마지막에 방에 들어 온 유저의 정보
	UserInfo& GetUserOfLastOrder()	{	return Users[Users.size()];	}
	// 특정 순서에 들어 온 유저를 쫒아낸다.
	bool BanUser(int OrderNum) 
	{
		return DelUser(Users[OrderNum - 1].acUserName);
	}
	// 모든 유저를 삭제한다.
	void Clear() { Users.clear(); }
private:
	vector< UserInfo > Users;
	char acMasterUserName[21]; // 방장의 이름
};