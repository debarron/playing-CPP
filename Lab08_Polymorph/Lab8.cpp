// Your Name
// Today's date
// Lab 6

#include "Account.h"
#include "CertificateOfDeposit.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <fstream>
#include <string>
using namespace std;

#define N 30

int main()
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Stores up to 30 accounts
	Account* accounts[N];

	Account *account;

	// Number of accounts that have been opened
	int numAccounts = 0;

	// For file input processing
	string command, acctType;
	int acctNum1, acctNum2;
	double amount;

	// Do the input and math
	while(fin >> command)
	{
		if(command == "NEW")
		{
			fin >> acctType;
			fin >> acctNum1;

			if(acctType == "SAVINGS"){
				account = new SavingsAccount(acctNum1);
			}
			else if(acctType == "CHECKING"){
				account = new CheckingAccount(acctNum1);
			}
			else if(acctType == "CERTIFICATE"){
				account = new CertificateOfDeposit(acctNum1);
			}

			accounts[numAccounts] = account;
			numAccounts++;
		}


		else if (command == "WITHDRAWAL")
		{
			fin >> acctNum1;
			fin >> amount;

			for (int i = 0; i < numAccounts; i++) {
				if(acctNum1 == accounts[i]->getAccountNum()){

					if(accounts[i]->getAccountType() == "CERTIFICATE")
						((CertificateOfDeposit *) accounts[i])->withdrawal(amount);
					else
						accounts[i]->withdrawal(amount);
				}
			}

    }
		else if (command == "DEPOSIT")
		{
			fin >> acctNum1;
			fin >> amount;

			for (int i = 0; i < numAccounts; i++) {
				if(acctNum1 == accounts[i]->getAccountNum()){
						accounts[i]->deposit(amount);
				}
			}


		}
		else if (command == "TRANSFER")
		{
			fin >> acctNum1;
			fin >> acctNum2;
			fin >> amount;

			for (int i = 0; i < numAccounts; i++) {
				if(acctNum1 == accounts[i]->getAccountNum()){

					for (int j = 0; j < numAccounts; j++) {
						if(acctNum2 == accounts[j]->getAccountNum()){

							if(accounts[i]->getAccountType() == "CERTIFICATE")
								((CertificateOfDeposit *) accounts[i])->withdrawal(amount);
							else
								accounts[i]->withdrawal(amount);

							accounts[j]->deposit(amount);
						}
					}
				}
			}
    }
		else if (command == "INTEREST")
		{
			for (int i = 0; i < numAccounts; i++) {

				if(accounts[i]->getAccountType() == "SAVINGS")
					((SavingsAccount *) accounts[i])->accrueInterest();

				else if(accounts[i]->getAccountType() == "CHECKING")
					((CheckingAccount *) accounts[i])->accrueInterest();

				else if (accounts[i]->getAccountType() == "CERTIFICATE")
					((CertificateOfDeposit *) accounts[i])->accrueInterest();
			}
    }
	}
	// Print output

	fout << "BANK STATEMENT" << endl << endl;

	for(int i = 0; i < numAccounts; i++)
	{
		fout << "Account number: " << accounts[i]->getAccountNum() << endl;
		fout << "Type of account: " << accounts[i]->getAccountType() << endl;
		fout << "Balance: $" << accounts[i]->getBalance() << endl;
		fout << endl;
	}

    // Delete accounts
	// for (int i = 0; i < numAccounts; i++)
	// 	delete accounts[i];

    // Close files
    fin.close();
    fout.close();
    return 0;
}
