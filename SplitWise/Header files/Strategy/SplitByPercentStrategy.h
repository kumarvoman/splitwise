#pragma once
#include <unordered_map>
#include "Header files/Strategy/ISplitStrategy.h"
class SplitByPercentStrategy : public ISplitStrategy
{
	unordered_map<int, double> percentage;
public:
	SplitByPercentStrategy(unordered_map<int, double> per);
	//{
	//	this->percentage = per;
	//}


	void calculatePaidAmount(Expense* expense);
};