#include <iostream> 
using namespace std;

float Calculations(int* radius, float volume, float area) {
    volume = (4.0 / 3.0 ) * 3.14 * (*radius) * (*radius) * (*radius);
    area = 4 * 3.14 * (*radius) * (*radius);

    cout << "Volume of the sphere: "  << volume << endl;
    cout << "Surface area of the sphere: " << area << endl;
    
    return 0;
}

int main() {
    int r;
    float volume, area;
    cout << "Enter the radius of the sphere: ";
    cin >> r;

    Calculations(&r, volume, area);

}