#include <iostream>
using namespace std;


class Array2D {
private:
    int** data;
    int rows, cols;

    void allocate() {
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols]{0};
    }

    void deallocate() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

public:
    Array2D() : rows(0), cols(0), data(nullptr) {}

    Array2D(int r, int c) : rows(r), cols(c) { allocate(); }

    Array2D(const Array2D& other) : rows(other.rows), cols(other.cols) {
        allocate();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
    }

    ~Array2D() { if (data) deallocate(); }

    Array2D& operator=(const Array2D& other) {
        if (this == &other) return *this;
        if (data) deallocate();
        rows = other.rows; cols = other.cols;
        allocate();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        return *this;
    }

    int* operator[](int i)             { return data[i]; }
    const int* operator[](int i) const { return data[i]; }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "\t";
            cout << "\n";
        }
    }
};



bool searchMatrix(const Array2D& matrix, int target) {
    int rows = matrix.getRows();
    int cols = matrix.getCols();

    if (rows == 0 || cols == 0) return false;

    int lo = 0;
    int hi = rows * cols - 1;   // treat as flat array

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // Convert flat index → 2D index
        int midVal = matrix[mid / cols][mid % cols];

        if (midVal == target)
            return true;
        else if (midVal < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return false;
}


int main() {

    // Build the matrix from the examples
    Array2D matrix(3, 4);
    int vals[3][4] = {
        { 1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = vals[i][j];

    cout << "Matrix:\n";
    matrix.print();
    cout << "\n";

    // Example 1: target = 3 → true
    int t1 = 3;
    cout << "Search " << t1 << ": "
         << (searchMatrix(matrix, t1) ? "true" : "false") << "\n";

    // Example 2: target = 13 → false
    int t2 = 13;
    cout << "Search " << t2 << ": "
         << (searchMatrix(matrix, t2) ? "true" : "false") << "\n";

    
    cout << "Search 1:  " << (searchMatrix(matrix,  1) ? "true" : "false") << "\n";
    cout << "Search 60: " << (searchMatrix(matrix, 60) ? "true" : "false") << "\n";
    cout << "Search 25: " << (searchMatrix(matrix, 25) ? "true" : "false") << "\n";

    return 0;
}