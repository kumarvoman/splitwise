#include "Header files/User.h"

User::User(string name, string phone, string password)
{
	this->Name = name;
	this->Phone = phone;
	this->Password = password; // use salted hash before storing the password
	this->expenses.clear();
	this->groups.clear();
}

string User::getName()
{
	return Name;
}

void User::setName(string name)
{
	this->Name = name;
}

string User::getPhone()
{
	return Phone;
}

void User::setPhone(string phone)
{
	this->Phone = phone;
}

void User::setPassword(string password)
{
	this->Password = password;
}

set<Expense*> User::getExpenses()
{
	return this->expenses;
}

set<Group*> User::getGroups()
{
	return this->groups;
}

int User::getUserId()
{
	return this->getId();
}