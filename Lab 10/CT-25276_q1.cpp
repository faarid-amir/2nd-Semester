#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Calculator
{
    T1 num1;
    T2 num2;

public:
    Calculator(T1 n1, T2 n2)
    {
        num1 = n1;
        num2 = n2;
    }

    void add()
    {
        cout << "Addition: " << num1 + num2 << endl;
    }

    void subtract()
    {
        cout << "Subtraction: " << num1 - num2 << endl;
    }

    void multiply()
    {
        cout << "Multiplication: " << num1 * num2 << endl;
    }

    void divide()
    {
        if (num2 != 0)
            cout << "Division: " << (double)num1 / num2 << endl;
        else
            cout << "Division by zero is not allowed!" << endl;
    }
};

int main()
{

    cout << "=== Int & Int ===" << endl;
    Calculator<int, int> c1(10, 3);
    c1.add();
    c1.subtract();
    c1.multiply();
    c1.divide();

    cout << "\n=== Int & Double ===" << endl;
    Calculator<int, double> c2(10, 3.5);
    c2.add();
    c2.subtract();
    c2.multiply();
    c2.divide();

    return 0;
}