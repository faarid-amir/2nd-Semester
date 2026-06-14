#include <iostream>
using namespace std;

template <typename T>
class mycontainer {
    T element;

public:
    mycontainer(T el) {
        element = el;
    }

    void increase() {
        element++;
        cout << "Increased Value: " << element << endl;
    }
};

// Template specialization for char
template <>
class mycontainer<char> {
    char element;

public:
    mycontainer(char el) {
        element = el;
    }

    void uppercase() {
        if (element >= 'a' && element <= 'z')
            element = element - 32; // converts to uppercase
        cout << "Uppercase: " << element << endl;
    }
};

int main() {
    
    cout << "=== Int Container ===" << endl;
    mycontainer<int> c1(5);
    c1.increase();

    
    cout << "\n=== Double Container ===" << endl;
    mycontainer<double> c2(3.14);
    c2.increase();

    
    cout << "\n=== Char Container (Specialization) ===" << endl;
    mycontainer<char> c3('h');
    c3.uppercase();

    return 0;
}