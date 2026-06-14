#include <iostream>
using namespace std;

class HotelMercato {
private:
    const double rent_per_day; 
    string customer_name;
    int days_stayed;

public:

    HotelMercato(string customer_name, int days_stayed) : rent_per_day(1000.85), customer_name(customer_name), days_stayed(days_stayed) {}
   
    double getPerDayRent() const {
        return rent_per_day;
    }

    double calculateRent() {
        if (days_stayed > 7) {
            return (days_stayed - 1) * getPerDayRent(); 
        } else {
            return days_stayed * getPerDayRent(); 
        }
    }


   
    void display() {
        cout << "Customer name: " << customer_name << endl;
        cout << "Days stayed: " << days_stayed << endl;
        cout << "Rent: " << calculateRent() << endl;
    }
};

int main(){
    HotelMercato customer1("Faarid Amir", 20); 
    customer1.display();
    
    return 0;
}

