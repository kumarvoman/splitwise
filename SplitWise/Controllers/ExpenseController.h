#include "Repositories/IExpenseRepo.h"
#include "Repositories/IUserRepo.h"
#include "Header files/Strategy/ISplitStrategy.h"
#include "Header files/Exception/UserException.h"
#include "Header files/Strategy/IPaymentStrategy.h"

class ExpenseController : public IExpenseRepo, UserException
{
public:
	IUserRepo *userRepo;
	IExpenseRepo *expenseRepo;
	UserException *ex;

	ExpenseController(IUserRepo *uRepo, IExpenseRepo* eRepo)
	{

	}

	Expense* createExpenseWithUser(	string name, 
									string description, 
									int Createdby, 
									vector<int> participants, 
									double amount, 
									ISplitStrategy *split,
									time_t date)
	{
		//check if user is existing or not
		User* current = userRepo->getUserById(Createdby);
		if (nullptr == current)
		{
			ex->UserNotFoundException();
		}

		//check if participants are existing or not -> this job can also be done by userValidationService else we can do here as well
		set<User*> users = userRepo->getUsers(participants);

		Expense *expense = new Expense(current, users, name, description, date, amount); //create the expense
		split->calculatePaidAmount(expense); //split the expense using provided strategy
		return nullptr;
	}

	Expense* createExpenseWithOtherUsers(string name, string description, list<string> *participants, int ownerId, double amount, ISplitStrategy *split, IPaymentStrategy *payment)
	{
		return createExpenseWithGroup();
	}

	Expense* createExpenseWithGroup()
	{
		return nullptr;
	}

	double getExpense()
	{
		return 0.0;
	}

	bool settle()
	{
		return true;
	}

	User* getUserById(int id) 
	{
		User* u;
		return u;
	}

	User* getUserByName(string name) 
	{
		User* u;
		return u;
	}

	set<User*> getUsers(vector<int> users) 
	{
		set<User*> fsa;
		return fsa;
	}

	bool isUserPresent(string userName) 
	{
		return true;
	}

	void saveUser(User* u) 
	{

	}

	User* saveUser(string userName, string password, string phNo) 
	{
		User* u;
		return u;
	}

};