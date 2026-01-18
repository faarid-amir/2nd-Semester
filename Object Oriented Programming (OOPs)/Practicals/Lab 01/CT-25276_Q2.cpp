#include <iostream> 
using namespace std;

void swap(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b; 
    *b = *c;
    *c = temp;
}

int main() {
    int x, y, z; 
    cout << "Enter three integers: ";
    cin >> x >> y >> z;

    cout << "Before swapping: \n x = " << x << ", y = " << y << ", z = " << z << endl;

    swap(&x, &y, &z);

    cout << "After swapping: \n x = " << x << ", y = " << y << ", z = " << z << endl;
    return 0;
}