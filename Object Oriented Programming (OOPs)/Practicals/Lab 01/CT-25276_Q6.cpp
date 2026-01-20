#include <iostream>
using namespace std;

 int saving(double* a)  {
    int amount;
    cout << "Enter the amount you want to withdraw from your Account: ";
    cin >> amount;

    if (amount > 100000) {
        cout << "You cannot withdraw more than 100000 from your Account. " << endl;
        return *a;

    }else if(amount > 50000) {
        *a = *a - amount - (amount * 0.02) - (amount * 0.05);
        cout << "You have withdrawn " << amount << " from your Savings Account." << endl;
        cout << "Your remaining balance is: " << *a << endl;

        return *a;

    }

    *a = *a - amount - (amount * 0.02);
    cout << "You have withdrawn " << amount << " from your Savings Account." << endl;
    cout << "Your remaining balance is: " << *a << endl;

    return *a;
    
 }

int current(double* a) {
    int amount;
    cout << "Enter the amount you want to withdraw form your Current Account: ";
    cin >> amount;

if(amount > 100000) {
        cout << "You cannot withdraw more than 100000 from your Account. " << endl;
        return *a;

}else if(amount > 50000) {
        *a = *a - amount - (amount * 0.05) - 100;
        cout << "You have withdrawn " << amount << " from your Current Account." << endl;
        cout << "Your remaining balance is: " << *a << endl;
        return *a;
    }

    *a = *a - amount - 100;
    cout << "You have withdrawn " << amount << " from your Current Account." << endl;
    cout << "Your remaining balance is: " << *a << endl;
    

    return *a;
}

int main(){
    double initial_amount = 200000;
    char option;
    int account_number; 

    cout << "Enter your account number: ";
    cin >> account_number;
    cout << "What account type do you want to open?\n (S) Savings Account \n (C) Current Account " << endl;
    cin >> option;

    switch(option){
        case 'S':
            cout << "You have chosen Savings Account." << endl;

            saving(&initial_amount);

            break;
        case 'C':
            cout << "You have chosen Current Account. " << endl;
            current(&initial_amount);

            break;
        default: 
            cout << "Invalid option selected!" << endl;
            break;
    }

     return 0;
}
