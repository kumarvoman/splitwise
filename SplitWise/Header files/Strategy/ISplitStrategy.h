#pragma once
#include "Repositories/IExpenseRepo.h"

class ISplitStrategy
{
public:
	virtual void calculatePaidAmount(Expense *expense) = 0;
	//virtual ~ISplitStrategy() = 0;
};