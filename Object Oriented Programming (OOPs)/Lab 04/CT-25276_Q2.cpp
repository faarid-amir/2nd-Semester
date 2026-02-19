#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr; 
    int size;  

public:
   
    DynamicArray(int size) : size(size) {
        arr = new int[size]; 
        for (int i = 0; i < size; i++) {
            arr[i] = 0; 
        }
    }
    
    ~DynamicArray() {
        delete[] arr;
    }
    
    void push(int value) {
        if (size > 0) {
            arr[size - 1] = value; 
        }
    }
    
    int getSize() {
        return size;
    }
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " "; 
        }
        cout << endl; 

    }

};


int main(){
    DynamicArray myArray(5); 
    myArray.push(10); 

    cout << "Size of the array: " << myArray.getSize() << endl; 
    cout << "Array elements: ";
    myArray.printArray(); 

    
    return 0;
}

