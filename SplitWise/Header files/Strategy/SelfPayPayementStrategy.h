#pragma once
#include "Header files/Strategy/IPaymentStrategy.h"
class SelfPayPaymentStrategy : public IPaymentStrategy
{
public:
	void calculatePaidAmount(Expense* expense);
};