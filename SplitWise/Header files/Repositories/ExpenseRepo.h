#pragma once
#include "Repositories/IExpenseRepo.h"
class ExpenseRepo : public IExpenseRepo
{
public:
	double getExpense() override
	{
		return 0.0;
	}

	bool settle() override
	{
		return true;
	}
};