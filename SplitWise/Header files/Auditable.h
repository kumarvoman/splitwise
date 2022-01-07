#pragma once
#include <string>
#include <time.h>
using namespace std;

//Abstract class
class Auditable
{
	int ID;
	time_t createdOn;
	string createdBy;

public:
	Auditable();
	Auditable(int id);
	int getId();
	time_t getCreatedOn();
};