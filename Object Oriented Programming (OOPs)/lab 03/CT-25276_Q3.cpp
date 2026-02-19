#include <iostream>
using namespace std;

class TollBooth
{
    int totalCars;
    double totalMoney;
public:

    void payingCar(void)
    {
        totalCars++;
        totalMoney += 0.50;
    }
    void displayTollData()
    {
        cout << "Total Cars: " << totalCars << endl
             << "Total Money: $" << totalMoney << endl
             << endl;
    }

    TollBooth() : totalCars(0), totalMoney(0.0) {}
};

int main()
{

    TollBooth hyderabadStation;

    cout << "Morning Shift:-" << endl;
    for (int i = 0; i < 50; i++)
        hyderabadStation.payingCar();
    hyderabadStation.displayTollData();

    cout << "Evening Shift:-" << endl;
    for (int i = 0; i < 100; i++)
        hyderabadStation.payingCar();
    hyderabadStation.displayTollData();

    cout << "Night Shift:-" << endl;
    for (int i = 0; i < 10; i++)
        hyderabadStation.payingCar();
    hyderabadStation.displayTollData();
    return 0;
}
