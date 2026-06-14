#include <iostream>
using namespace std;

class Array2D
{
private:
    int **data;
    int rows, cols;

    // allocating memory
    void allocate()
    {
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols]{0}; // initialize to 0
    }

    // deallocating memory
    void deallocate()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

public:
    Array2D() : rows(0), cols(0), data(nullptr) {}

    Array2D(int r, int c) : rows(r), cols(c)
    {
        allocate();
    }

    Array2D(const Array2D &other) : rows(other.rows), cols(other.cols)
    {
        allocate();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
    }

    // Destructor
    ~Array2D()
    {
        if (data)
            deallocate();
    }

    Array2D &operator=(const Array2D &other)
    {
        if (this == &other)
            return *this; // self-assignment guard

        if (data)
            deallocate();

        rows = other.rows;
        cols = other.cols;
        allocate();

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];

        return *this;
    }

    Array2D operator+(const Array2D &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Error: Size mismatch for +\n";
            return Array2D();
        }
        Array2D result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Array2D operator-(const Array2D &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Error: Size mismatch for -\n";
            return Array2D();
        }
        Array2D result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    Array2D operator*(const Array2D &other) const
    {
        if (cols != other.rows)
        {
            cout << "Error: Invalid dimensions for *\n";
            return Array2D();
        }
        Array2D result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    int *operator[](int i)
    {
        return data[i];
    }

    const int *operator[](int i) const
    {
        return data[i];
    }

    void print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "\t";
            cout << "\n";
        }
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

int main()
{

    Array2D A(2, 3), B(2, 3);

    int val = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            A[i][j] = val++;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            B[i][j] = val++;

    cout << "Matrix A:\n";
    A.print();
    cout << "\nMatrix B:\n";
    B.print();

    Array2D C = A + B;
    cout << "\nA + B:\n";
    C.print();

    Array2D D = A - B;
    cout << "\nA - B:\n";
    D.print();

    Array2D X(2, 3), Y(3, 2);
    X[0][0] = 1;
    X[0][1] = 2;
    X[0][2] = 3;
    X[1][0] = 4;
    X[1][1] = 5;
    X[1][2] = 6;

    Y[0][0] = 7;
    Y[0][1] = 8;
    Y[1][0] = 9;
    Y[1][1] = 10;
    Y[2][0] = 11;
    Y[2][1] = 12;

    Array2D Z = X * Y;
    cout << "\nX (2x3):\n";
    X.print();
    cout << "\nY (3x2):\n";
    Y.print();
    cout << "\nX * Y (2x2):\n";
    Z.print();

    Array2D E = A;
    cout << "\nCopy of A:\n";
    E.print();

    Array2D F;
    F = B;
    cout << "\nAssigned B to F:\n";
    F.print();

    return 0;
}