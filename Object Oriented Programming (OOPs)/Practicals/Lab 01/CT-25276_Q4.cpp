#include <iostream> 
using namespace std;

const int size  = 3; 

void readMatrix(int a[size][size], int b[size][size]) {

    cout << "Enter elements of first 3x3 matrix: " << endl;

    for(int i = 0; i< size; i++) {
        for(int j = 0; j < size; j++) {  //input matrix1 elements
            cin >> a[i][j];
        }
    }
    cout << "Enter elements of second 3x3 matrix: " << endl;

    for(int i = 0; i< size; i++) {
        for(int j = 0; j < size; j++) {    //input matrix2 elements
            cin >> b[i][j];
        }
    }
}

int displaysum(int a[size][size], int b[size][size]) {
    int sum[size][size] = {0};

    for(int i = 0; i< size; i++) {
        for(int j =0 ; j< size; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Sum of the two matrices is: " << endl;

    for (int i = 0; i< size; i++) {
        for ( int j = 0; j< size; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}

int displayproduct(int a[size][size], int b[size][size]) {
    int product[size][size] = {0};
    int sum = 0;

    for(int i = 0; i< size; i++) {
        for (int j = 0; j < size; j++) {
            for ( int k = 0; k < size; k++) {
                sum += a[i][k] * b[k][j];
            }
            product[i][j] = sum;
            sum  = 0;
        }
    }

    cout << "Product of the two matrices is: " << endl;
    for( int i = 0; i< size; i++) {
        for (int j = 0; j< size; j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    int arr1[size][size];
    int arr2[size][size];

    readMatrix(arr1, arr2);
    displaysum(arr1, arr2);
    displayproduct(arr1, arr2);

    
    
    return 0;
}