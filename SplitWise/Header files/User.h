#pragma once
#include <string>
#include <set>
#include <unordered_set>
#include "Auditable.h"
//#include "Expense.h"
//#include "Group.h"
class Expense;
class Group;

using namespace std;

class User : public Auditable
{
	std::string Name;
	std::string Phone;
	std::string Password;
	set<Expense*> expenses;
	set<Group*> groups;

public:
	
	User(std::string name, std::string phone, std::string password);

	std::string getName();

	void setName(std::string name);

	std::string getPhone();

	void setPhone(std::string phone);

	void setPassword(std::string password);

	set<Expense*> getExpenses();

	set<Group*> getGroups();

	//Auditable fields

	int getUserId();
};
