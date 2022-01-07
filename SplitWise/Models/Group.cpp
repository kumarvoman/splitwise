#include "Header files/Group.h"
string Group::getGroupName()
{
	return this->Name;
}
void Group::setGroupName(string name)
{
	this->Name = name;
}

string Group::getGroupDescription()
{
	return this->Description;
}
void Group::setGroupDescription(string desc)
{
	this->Description = desc;
}

User* Group::getGroupAdmin() 
{
	return this->Admin;
}
void Group::setGroupAdmin(User* user)
{
	this->Admin = user;
}