// Your Name
// Today's date
// Lab 6

#include "Account.h"

// Prevent multiple includes of this class
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account
{
public:
	// Constructor
	CheckingAccount(int newAccountNum);

	// Applies an interest rate to the balance
	void accrueInterest();
	

};

#endif
