#include "Header files/Expense.h"

Expense::Expense(User* current, set<User*> users, string name, string description, time_t date, double amount)
{
	this->Description = description;
	this->Owner = current;
	this->participants = users;
	this->amount = amount;
}

double Expense::getAmount()
{
	return this->amount;
}

void Expense::setAmount(double amt)
{

}

string Expense::getName()
{
	return this->Name;
}
void Expense::setName(string name)
{

}

string Expense::getDescription()
{
	return this->Description;
}
void Expense::setDescription(string desc)
{

}

User* Expense::getUser()
{
	return this->Owner;
}
void Expense::setUser(User* user)
{

}

set<User*> Expense::getParticipants()
{
	return this->participants;
}
void Expense::setParticipants(set<User*> users)
{

}

map<User*, double> Expense::getAmtPaid()
{
	return this->amountPaid;
}
void Expense::setAmtPaid(map<User*, double>)
{

}

map<User*, double> Expense::getAmtOwner()
{
	return this->amountPaid;
}
void Expense::setAmtOwner(map<User*, double>) 
{

}