// Your Name
// Today's date
// Lab 6

#include "Account.h"

// Prevent multiple includes of this class
// #ifndef CERTIFICATEOFDEPOSIT_H
// #define CERTIFICATEOFDEPOSIT_H

class CertificateOfDeposit : public Account
{
private:
	bool hasWithdrawn;
public:
	// Constructor
	CertificateOfDeposit(int newAccountNum);

	// Applies an interest rate to the balance
	void accrueInterest();
	// Removes money from the bank account
	void withdrawal(double amount);
};

// #endif
