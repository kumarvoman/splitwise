#pragma once
#include <string.h>
#include <set>
#include <map>
#include "Auditable.h"
//#include "User.h"
class User;

using namespace std;
class Expense : public Auditable
{
	double amount;
	string Name;
	string Description;
	
	User* Owner;

	set<User*> participants;
	map<User*, double> amountPaid; //to keep track of amount paid by each user
	map<User*, double> amountOwner;

public:
	Expense(User* current, set<User*> users, string name, string description, time_t date, double amount);

	double getAmount();
	void setAmount(double amt);

	string getName();
	void setName(string name);

	string getDescription();
	void setDescription(string desc);

	User* getUser();
	void setUser(User* user);

	set<User*> getParticipants();
	void setParticipants(set<User*> users);

	map<User*, double> getAmtPaid();
	void setAmtPaid(map<User*, double>);

	map<User*, double> getAmtOwner();
	void setAmtOwner(map<User*, double>);
};

