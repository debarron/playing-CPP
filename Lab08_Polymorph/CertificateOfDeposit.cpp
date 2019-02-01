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
}

// Applies an interest rate to the balance
void CertificateOfDeposit::accrueInterest()
{
  double interest;
  if(hasWithdrawn == true){
    interest = balance * 0.01;
  }
  else{
    interest = balance * 0.10;
  }

  balance += interest;
}

// Removes money from the bank account
void CertificateOfDeposit::withdrawal(double amount)
{
    hasWithdrawn = true;
    balance -= amount;
}
