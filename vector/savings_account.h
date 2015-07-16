#ifndef SAVINGS_ACCOUNT_H_INCLUDED
#define SAVINGS_ACCOUNT_H_INCLUDED

#include "account.h"
#include <cstring>
using namespace std;

class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(const char* name, double interestRate) : Account(name)
    {
        if (interestRate > 0) {
            this->interestRate = interestRate;
        } else {
            this->interestRate = 5;
        }
    }

    double payInterest()
    {
        double interest = getBalance() * interestRate / 100;

        deposit(interest);

        return interest;
    }
};

#endif 
