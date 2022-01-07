#pragma once
#include <string.h>
#include <set>
#include "Auditable.h"
//#include "User.h"
//#include "Expense.h"

class User;
class Expense;
using namespace std;

class Group : public Auditable
{
	string Name;
	string Description;
	User* Admin;
	set<User*> participants;
	set<Expense*> expenses;

public:
	string getGroupName();
	void setGroupName(string name);

	string getGroupDescription();
	void setGroupDescription(string desc);

	User* getGroupAdmin();
	void setGroupAdmin(User* user);
};

