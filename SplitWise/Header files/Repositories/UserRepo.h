#pragma once
#include <set>
#include <string.h>
#include <unordered_map>
#include "Repositories/IUserRepo.h"

class User;
class Expense;
class Group;

using namespace std;

class UserInMemoryRepo : public IUserRepo
{
	unordered_map<int, User*> UserId;
	unordered_map<string, User*> UserName;

public:
	User* getUserById(int id)
	{
		return UserId[id];
	}

	User* getUserByName(string name)
	{
		User* currUser = UserName[name];
		return currUser;
	}

	set<User*> getUsers(vector<int> users)
	{
		set<User*> participants;
		return participants;
	}

	bool isUserPresent(string userName)
	{
		auto x = UserName.find(userName);
		if (x != UserName.end())
			return true;
		return false;
	}

	void saveUser(User* u)
	{
		string name = u->getName();
		int Id = u->getUserId();
		UserName.insert(pair<string, User*>(name, u));
		UserId.insert(pair<int, User*>(Id, u));
	}

	User* saveUser(string userName, string password, string phNo)
	{
		User *u = new User(userName, phNo, password);
		UserId.insert(pair<int, User*>(UserId.size() + 1, u));
		UserName.insert(pair<string, User*>(userName, u));
		return u;
	}
};