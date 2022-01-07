#pragma once
#include <iostream>
class UserException : public std::exception
{
public:
	void UserNotFoundException();

	void UserNotRegistered();

	virtual ~UserException();
};

