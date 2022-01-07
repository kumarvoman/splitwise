#include <iostream>
#include <string>
#include "Header files/Group.h"
#include "Header files/User.h"
#include "Header files/Expense.h"
#include "Header files/Repositories/UserRepo.h"
#include "Repositories/IUserRepo.h"
#include "Header files/Exception/UserException.h"

using namespace std;

class UserController : public IUserRepo, UserException
{
	IUserRepo *rep;
public:
	UserController(IUserRepo *repo)
	{
		this->rep = repo;
	}

	User* RegisterUser(string name, string phone, string pass)
	{
		UserInMemoryRepo* u = new UserInMemoryRepo();
		User* current = u->getUserByName(name);
		if (nullptr == current)
		{
			User* newuser = u->saveUser(name, phone, pass);
			return newuser;
		}
		else
			return current;
	}

	User* getUserById(int id) override
	{
		User* u = rep->getUserById(id);
		return u;
	}

	User* getUserByName(string name) override
	{
		User* u = rep->getUserByName(name);
		return u;
	}

	set<User*> getUsers(vector<int> users) override
	{
		
		set<User*> fsa = rep->getUsers(users);
		return fsa;
	}

	bool isUserPresent(string userName) override
	{
		if(nullptr != rep->getUserByName(userName))
			return true;
		return false;
	}

	void saveUser(User* u) override
	{

	}

	User* saveUser(string userName, string password, string phNo) override
	{
		User* u = new User(userName, phNo, password);
		return u;
	}
};