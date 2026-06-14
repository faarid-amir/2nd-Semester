#include <iostream>
using namespace std;

// Abstract base class
class Store {
protected:
    double total_bill;

public:
    Store(double bill) {
        total_bill = bill;
    }

    virtual void calculateFinalBill() = 0; // Pure virtual function
};

// Derived class for ImtiazStore (7% discount)
class ImtiazStore : public Store {
public:
    ImtiazStore(double bill) : Store(bill) {}

    void calculateFinalBill() override {
        double discount = total_bill * 0.07;
        double final_bill = total_bill - discount;
        cout << "ImtiazStore - Total Bill: " << total_bill << endl;
        cout << "ImtiazStore - Discount (7%): " << discount << endl;
        cout << "ImtiazStore - Final Bill: " << final_bill << endl;
    }
};

// Derived class for BinHashimStore (5% discount)
class BinHashimStore : public Store {
public:
    BinHashimStore(double bill) : Store(bill) {}

    void calculateFinalBill() override {
        double discount = total_bill * 0.05;
        double final_bill = total_bill - discount;
        cout << "\nBinHashimStore - Total Bill: " << total_bill << endl;
        cout << "BinHashimStore - Discount (5%): " << discount << endl;
        cout << "BinHashimStore - Final Bill: " << final_bill << endl;
    }
};

int main() {
    ImtiazStore store1(5000);
    store1.calculateFinalBill();

    BinHashimStore store2(5000);
    store2.calculateFinalBill();

    return 0;
}