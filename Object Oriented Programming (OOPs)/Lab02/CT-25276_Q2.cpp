#include <iostream>
using namespace std;

class BankAccount
{
private:
    int balance, transactionCount;

public:
    BankAccount(int amt) : balance(amt), transactionCount(0) {}

    int getBalance()
    {
        return balance;
    }
    int getTransactionCount()
    {
        return transactionCount;
    }
    bool deposit(int amt)
    {
        if (amt > 0)
        {
            balance += amt;
            transactionCount++;
            return false;
        }
        return true;
    }
    bool withdraw(int amt)
    {
        if (amt > 0 && amt <= balance)
        {
            balance -= amt;
            transactionCount++;
            return false;
        }
        return true;
    }
};

int main()
{
    cout << "Welcome to ABC Bank!" << endl;
    BankAccount myAccount(5000);
    int choice;
    do
    {
        cout << "\n\nSelect options from below:" << endl;
        cout << "1. Display balance" << endl;
        cout << "2. Display number of transactions" << endl;
        cout << "3. Display interest earned for this period" << endl;
        cout << "4. Make a deposit" << endl;
        cout << "5. Make a withdrawal" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Current balance: ";
            cout << myAccount.getBalance() << endl;
            break;
        case 2:
            cout << "Number of transactions: ";
            cout << myAccount.getTransactionCount() << endl;
            break;
        case 3:
            cout << "Enter annual interest rate (in %): ";
            float rate;
            cin >> rate;
            cout << "Interest earned for this period: ";
            cout << (myAccount.getBalance() * rate / 100) / 12 << endl;
            break;
        case 4:
            cout << "Current balance: ";
            cout << myAccount.getBalance() << endl;
            cout << "Enter amount to deposit: ";
            int depositAmount;
            cin >> depositAmount;
            if (myAccount.deposit(depositAmount))
                cout << "Invalid deposit amount!" << endl;
            else
            {
                cout << "New balance: ";
                cout << myAccount.getBalance() << endl;
            }
            break;
        case 5:
            cout << "Current balance: ";
            cout << myAccount.getBalance() << endl;
            cout << "Enter amount to withdraw: ";
            int withdrawAmount;
            cin >> withdrawAmount;
            if (myAccount.withdraw(withdrawAmount))
                cout << "Invalid withdrawal amount!" << endl;
            else
            {
                cout << "New balance: ";
                cout << myAccount.getBalance() << endl;
            }
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}
