#include <iostream>
using namespace std;


class Account {
protected:
    double balance;

public:
   
    Account() {
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    // Parameterized constructor
    Account(double balance) : balance(balance) {}

    
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << "\n";
    }

    virtual void withdraw(double amount) {
        if (amount > balance)
            cout << "Insufficient funds!\n";
        else {
            balance -= amount;
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << "\n";
        }
    }

    void checkBalance() const {
        cout << "Balance: " << balance << "\n";
    }

    double getBalance() const { return balance; }

    virtual ~Account() {} // Virtual Destructor.
};



class InterestAccount : public Account {
protected:
    double interest;   

public:
   
    InterestAccount() : Account() {
        cout << "Enter interest rate (default 0.30): ";
        cin >> interest;
    }

    // Parameterized constructor
    InterestAccount(double balance, double interest = 0.30)
        : Account(balance), interest(interest) {}

    
    void deposit(double amount) override {
        double withInterest = amount + (amount * interest);
        balance += withInterest;
        cout << "Deposited: " << amount
             << " + Interest(" << interest * 100 << "%): " << amount * interest
             << " | New Balance: " << balance << "\n";
    }
};



class ChargingAccount : public Account {
protected:
    double fee;     

public:
   
    ChargingAccount() : Account() {
        cout << "Enter withdrawal fee (default 25): ";
        cin >> fee;
    }

    // Parameterized constructor
    ChargingAccount(double balance, double fee = 25.0)
        : Account(balance), fee(fee) {}

    
    void withdraw(double amount) override {
        double total = amount + fee;
        if (total > balance)
            cout << "Insufficient funds (amount + fee Rs." << fee << ")!\n";
        else {
            balance -= total;
            cout << "Withdrawn: " << amount
                 << " + Fee: " << fee
                 << " | New Balance: " << balance << "\n";
        }
    }
};



class ACI : public InterestAccount, public ChargingAccount {
public:
    // Default constructor — takes user input
    ACI() {
        cout << "\n-- ACI Account Setup --\n";
        cout << "Enter balance: ";
        // balance is ambiguous
        cin >> InterestAccount::balance;
        ChargingAccount::balance = InterestAccount::balance;

        cout << "Enter interest rate (default 0.30): ";
        cin >> interest;

        cout << "Enter withdrawal fee (default 25): ";
        cin >> fee;
    }

    // Parameterized constructor
    ACI(double balance, double interest = 0.30, double fee = 25.0)
        : InterestAccount(balance, interest),
          ChargingAccount(balance, fee) {}

    
    void deposit(double amount) override {
        InterestAccount::deposit(amount);
        ChargingAccount::balance = InterestAccount::balance; 
    }

    void withdraw(double amount) override {
        ChargingAccount::withdraw(amount);
        InterestAccount::balance = ChargingAccount::balance; 
    }

    void checkBalance() const {
        cout << "Balance: " << InterestAccount::balance << "\n";
    }

  
    void transfer(double amount, Account& target) {
        if (amount > InterestAccount::balance) {
            cout << "Insufficient funds for transfer!\n";
            return;
        }
        InterestAccount::balance -= amount;
        ChargingAccount::balance  = InterestAccount::balance;
        target.deposit(amount);
        cout << "Transferred " << amount << " to Account.\n";
    }

    
    void transfer(double amount, InterestAccount& target) {
        if (amount > InterestAccount::balance) {
            cout << "Insufficient funds for transfer!\n";
            return;
        }
        InterestAccount::balance -= amount;
        ChargingAccount::balance  = InterestAccount::balance;
        target.deposit(amount);     // deposit with interest applied
        cout << "Transferred " << amount << " to InterestAccount (with interest).\n";
    }

    
    void transfer(double amount, ChargingAccount& target) {
        if (amount > InterestAccount::balance) {
            cout << "Insufficient funds for transfer!\n";
            return;
        }
        InterestAccount::balance -= amount;
        ChargingAccount::balance  = InterestAccount::balance;
        target.deposit(amount);
        cout << "Transferred " << amount << " to ChargingAccount.\n";
    }
};



int main() {

    cout << "======= Interest Account =======\n";
    InterestAccount ia(1000, 0.30);
    ia.checkBalance();
    ia.deposit(500);        
    ia.checkBalance();
    ia.withdraw(200);
    ia.checkBalance();

    cout << "\n======= Charging Account =======\n";
    ChargingAccount ca(1000, 25);
    ca.checkBalance();
    ca.deposit(300);
    ca.checkBalance();
    ca.withdraw(200);       
    ca.checkBalance();

    cout << "\n======= ACI Account =======\n";
    ACI aci(5000, 0.30, 25);
    aci.checkBalance();
    aci.deposit(1000);      
    aci.checkBalance();
    aci.withdraw(500);      
    aci.checkBalance();

    cout << "\n-- Transfer to generic Account --\n";
    Account plain(2000);
    plain.checkBalance();
    aci.transfer(300, plain);
    plain.checkBalance();

    cout << "\n-- Transfer to InterestAccount --\n";
    InterestAccount ia2(500, 0.30);
    ia2.checkBalance();
    aci.transfer(400, ia2);     
    ia2.checkBalance();

    cout << "\n-- Transfer to ChargingAccount --\n";
    ChargingAccount ca2(800, 25);
    ca2.checkBalance();
    aci.transfer(200, ca2);
    ca2.checkBalance();

    return 0;
}