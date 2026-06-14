#include <iostream>
using namespace std;

// Template function for swapping same datatype
template <typename T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Template function for swapping different datatypes
template <typename T1, typename T2>
void swapValues(T1 &a, T2 &b)
{
    T1 temp = a;
    a = (T1)b;
    b = (T2)temp;
}

int main()
{

    cout << "=== Int & Int ===" << endl;
    int x = 10, y = 20;
    cout << "Before Swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After Swap:  x = " << x << ", y = " << y << endl;

    cout << "\n=== Double & Double ===" << endl;
    double a = 3.14, b = 7.77;
    cout << "Before Swap: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After Swap:  a = " << a << ", b = " << b << endl;

    cout << "\n=== Int & Double ===" << endl;
    int p = 5;
    double q = 9.99;
    cout << "Before Swap: p = " << p << ", q = " << q << endl;
    swapValues(p, q);
    cout << "After Swap:  p = " << p << ", q = " << q << endl;

    return 0;
}