// Your Name
// Today's date
// Lab 6

#include "Account.h"
#include "CertificateOfDeposit.h"

// Constructor
CertificateOfDeposit::CertificateOfDeposit(int newAccountNum)
{
  accountNum = newAccountNum;
  type = "CERTIFICATE";
  hasWithdrawn = false;
}

// Applies an interest rate to the balance
void CertificateOfDeposit::accrueInterest()
{
  // interest is 10% if no writhdraw has been madre
  double interest;
  if(hasWithdrawn == false){
    interest = 0.10 * balace;
  }
  else{
    interest = 0.01 * balace;
  }
  balace += interest;
}

// Removes money from the bank account
void CertificateOfDeposit::withdrawal(double amount)
{
  hasWithdrawn = true;
  balance -= amount;
}
