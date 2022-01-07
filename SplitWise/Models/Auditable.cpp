#include "Header files/Auditable.h"

Auditable::Auditable()
{

}

Auditable::Auditable(int id)
{
	this->ID = id;
	this->createdOn = time(0);
}
int Auditable::getId()
{
	return this->ID;
}
time_t Auditable::getCreatedOn()
{
	return this->createdOn;
}