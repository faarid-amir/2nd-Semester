#include <iostream>
using namespace std;

class Account {
private:
    int account_no;
    double account_bal;
    int security_code;
    static int object_count; 

public:
    
    Account() {
        account_no = 0;
        account_bal = 0.0;
        security_code = 0;
        object_count++; 
    }
    
    void initialize(int account_no, double account_bal, int security_code) {
        this->account_no = account_no;
        this->account_bal = account_bal;
        this->security_code = security_code;
    }
  
    void print() {
        cout << "Account Number: " << account_no << endl;
        cout << "Account Balance: " << account_bal << endl;
        cout << "Security Code: " << security_code << endl;
    }
   
    static int getObjectCount() {
        return object_count;
    }
};

int Account::object_count = 0; 

int main(){
    Account acc1;
    acc1.initialize(12345, 1000.0, 6789);
    cout << "Account " << Account::getObjectCount() << ":" << endl;
    acc1.print();
    cout << endl;

    Account acc2;
    acc2.initialize(67890, 2000.0, 1234);
    cout << "Account " << Account::getObjectCount() << ":" << endl;
    acc2.print();
    cout << endl;

    cout << "Total number of Account objects: " << Account::getObjectCount() << endl;

    return 0;
}

