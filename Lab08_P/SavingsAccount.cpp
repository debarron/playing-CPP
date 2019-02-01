// Your Name
// Today's date
// Lab 6

#include "Account.h"
#include "SavingsAccount.h"

// Constructor
SavingsAccount::SavingsAccount(int newAccountNum)
{
	accountNum = newAccountNum;
	type = "SAVINGS";
}

// Applies an interest rate to the balance
void SavingsAccount::accrueInterest()
{
	if (balance >= 100.00 && balance < 1000.00)
		balance *= 1.01;
	else if (balance >= 1000.00)
		balance *= 1.02;
}
