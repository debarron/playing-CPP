// Your Name
// Today's date
// Lab 6

#include <string>
using namespace std;

// Prevent multiple includes of this class
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
	// The identifying number of the account
	int accountNum;
	// The total amount of money stored in the account
	double balance;
	// The type of account
	string type;

public:
	// Default constructor
	Account();

	// Returns the account number
	int getAccountNum();
	// Returns the account type
	string getAccountType();
	// Returns the amount of money stored
	double getBalance();

	// Applies an interest rate to the balance
	virtual void accrueInterest() = 0;
	// Adds money to the bank account
	virtual void deposit(double amount);
	// Removes money from the bank account
	virtual void withdrawal(double amount);
};

#endif
