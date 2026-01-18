#include <iostream> 
using namespace std;

int main() {

    float fahrenheit, celsius;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;

    celsius = (fahrenheit - 32) / 1.8;

    cout << "Temperature in Celsius: " << celsius << " C" << endl;


    return 0;
}