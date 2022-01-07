#pragma once
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <map>
#include <list>
#include "Repositories/IUserRepo.h"
#include "Repositories/IExpenseRepo.h"
#include "Controllers/ExpenseController.h"
#include "Controllers/UserController.h"
#include "Header files/Repositories/ExpenseRepo.h"
#include "Header files/Strategy/SplitByPercentStrategy.h"
#include "Header files/Strategy/SelfPayPayementStrategy.h"
using namespace std;

int main()
{
	IUserRepo *userRepo  = new UserInMemoryRepo();
	IExpenseRepo *expenseRepo = new ExpenseRepo();
	UserController *c = new UserController(userRepo);
	User* u1 = c->RegisterUser("u1", "u1password", "9234576890");
	User* u2 = c->RegisterUser("u2", "u1password", "9234576890");
	User* u3 = c->RegisterUser("u3", "u1password", "9234576890");
	ExpenseController *e = new ExpenseController(userRepo, expenseRepo);
	list<string> *participants = new list<string>();
	participants->push_back(u1->getName());
	participants->push_back(u2->getName());
	participants->push_back(u3->getName());
	unordered_map<int, double> percentage;
	percentage.insert(pair<int, double>(u1->getId(), 30.0));
	percentage.insert(pair<int, double>(u2->getId(), 50.0));
	percentage.insert(pair<int, double>(u3->getId(), 20.0));
	ISplitStrategy *split = new SplitByPercentStrategy(percentage);
	IPaymentStrategy *payment =  new SelfPayPaymentStrategy();
	e->createExpenseWithOtherUsers("First", "First expense", participants, u1->getId(), 1000.0, split, payment);
}