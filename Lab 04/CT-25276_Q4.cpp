#include <iostream>
using namespace std;

class Student {
private:
    const int rollNumber;   
    string name;
    int age;

public:
    Student(int r, string n, int a) : rollNumber(r) {
        name = n;
        age = a;
    }

    void display() const {   
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void changeAge(int newAge) {
        age = newAge;   
    }

};

int main() {
    Student s1(101, "Ali", 20);

    s1.display();

    s1.changeAge(21);   
    cout << "\nAfter updating age:\n";
    s1.display();

    return 0;
}