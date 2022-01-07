#pragma once
#include "Header files/Expense.h"
class IPaymentStrategy
{
public:
	virtual void calculatePaidAmount(Expense* expense) =0;
};

