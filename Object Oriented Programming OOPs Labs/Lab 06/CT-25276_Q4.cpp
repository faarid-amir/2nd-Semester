#include <iostream>
using namespace std;
// Base class Person
class Person {
protected:
    string name;
    string occupation;

public:
    Person(string occ) {
        occupation = occ;
    }

    virtual void Draw() {
        cout << "A person can draw in many ways" << endl;
    }
};

// Derived class Artist
class Artist : public Person {
public:
    Artist() : Person("artist") {
        
    }

    void Draw() override {
        cout << "An artist can draw with a paint brush" << endl;
    }
};

// Derived class Gunman
class Gunman : public Person {
public:
    Gunman() : Person("gunman") {
        
    }

    void Draw() override {
        cout << "A gunman draws a gun to shoot" << endl;
    }
};

int main() {
    // Array of Person pointers of size 3 (Person, Artist, Gunman)
    Person* arr[3];

    // Dynamically create objects 
    arr[0] = new Person("person");
    arr[1] = new Artist();
    arr[2] = new Gunman();

    
    for (int i = 0; i < 3; i++) {
        arr[i]->Draw();
    }

    
    delete arr[0];
    delete arr[1];
    delete arr[2];

    return 0;
}