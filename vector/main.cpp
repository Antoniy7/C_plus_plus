#include <iostream>
#include "account.h"
#include "savings_account.h"
#include <cstring>

using namespace std;

bool isEmpty(Account account)
{
    return account.getBalance() <= 0;
}

void emptyAccount(Account account)
{
    account.withdraw(account.getBalance());
}

Account emptyBetterAccount(Account& account)
{
    account.withdraw(account.getBalance());
    return account;
}

void printAll(Account accounts[], int length)
{
    for(int i=0; i < length; ++i)
    {
        accounts[i].print();
        cout << endl;
    }
}

int main()
{
    Account myAccount(500, "current account");

    myAccount.deposit(200);

    Account thirdAccount = myAccount;

    emptyAccount(thirdAccount);
    cout << endl;
    thirdAccount.print();
    cout << endl;

    SavingsAccount savAccount("savings", 4.3);

    cout << "Savings balance: " << savAccount.getBalance() << endl;

    savAccount.deposit(200);
    savAccount.payInterest();

    cout << "Savings balance: " << savAccount.getBalance() << endl;

    return 0;
}
