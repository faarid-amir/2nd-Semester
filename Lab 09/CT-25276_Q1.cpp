#include <iostream>
using namespace std;

// Abstract base class
class ArrayMultiplier
{
public:
    virtual void calculate() = 0; // Pure virtual function
};

class ArrayMultiplier1D : public ArrayMultiplier
{
    int arr[10];
    int size;

public:
    ArrayMultiplier1D(int a[], int n)
    {
        size = n;
        for (int i = 0; i < size; i++)
            arr[i] = a[i];
    }

    void calculate() override
    {
        int result = 1;
        for (int i = 0; i < size; i++)
            result *= arr[i];
        cout << "1D Array Multiplication Result: " << result << endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier
{
    int arr[10][10];
    int rows, cols;

public:
    ArrayMultiplier2D(int a[][10], int r, int c)
    {
        rows = r;
        cols = c;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                arr[i][j] = a[i][j];
    }

    void calculate() override
    {
        int result = 1;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result *= arr[i][j];
        cout << "2D Array Multiplication Result: " << result << endl;
    }
};

int main()
{

    int a[] = {1, 2, 3, 4};
    ArrayMultiplier1D obj1(a, 4);
    obj1.calculate();

    int b[2][10] = {{1, 2, 3}, {4, 5, 6}};
    ArrayMultiplier2D obj2(b, 2, 3);
    obj2.calculate();

    return 0;
}