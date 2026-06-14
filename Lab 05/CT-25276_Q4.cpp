#include <iostream>
using namespace std;

// ================= Base Class =================
class Item {
protected:
    string Name;
    int Quantity;

public:
    void setItem(string name, int qty) {
        Name = name;
        Quantity = qty;
    }

    string getName() {
        return Name;
    }

    int getQuantity() {
        return Quantity;
    }
};


class BakedGoods : public Item {
protected:
    double discount = 0.10;   

public:
    double applyDiscount(double total) {
        return total - (total * discount);
    }
};


class Cakes : public BakedGoods {
private:
    double price = 600;

public:
    double calculateBill() {
        double total = price * Quantity;
        return applyDiscount(total);
    }
};


class Bread : public BakedGoods {
private:
    double price = 200;

public:
    double calculateBill() {
        double total = price * Quantity;
        return applyDiscount(total);
    }
};


class Drinks : public Item {
private:
    double price = 100;
    double discount = 0.05;   

public:
    double calculateBill() {
        double total = price * Quantity;
        return total - (total * discount);
    }
};


int main() {

    int choice, qty;
    string name;

    while (true) {
    cout << "Select Item:\n";
    cout << "1. Cake (600, 10% discount)\n";
    cout << "2. Bread (200, 10% discount)\n";
    cout << "3. Drink (100, 5% discount)\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 4 ) {
        cout << "Exiting..." << endl;
        break;
    }

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice. " << endl;
        continue;
    }

    cout << "Enter quantity: ";
    cin >> qty;

    if (choice == 1) {
        Cakes c;
        c.setItem("Cake", qty);
        cout << "Total Bill: " << c.calculateBill() << "\n" << endl;
    }
    else if (choice == 2) {
        Bread b;
        b.setItem("Bread", qty);
        cout << "Total Bill: " << b.calculateBill() << "\n" << endl;
    }
    else if (choice == 3) {
        Drinks d;
        d.setItem("Drink", qty);
        cout << "Total Bill: " << d.calculateBill() << "\n" << endl;
    }
    
}

    return 0;
}

