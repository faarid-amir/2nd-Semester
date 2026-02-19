#include <iostream>
using namespace std;

class BaseClass {
    private:
        int privateInt;
    protected:
        int protectedInt;
    public:
        int publicInt;

    void setPrivateInt(int value) {
        privateInt = value;
    } 
    
    void setProtectedInt(int value) {
        protectedInt = value;
    }

    void setPublicInt(int value) {
        publicInt = value;
    }

    int getPrivateInt() {
        return privateInt;
    }
    
    int getProtectedInt() {
        return protectedInt;
    }

    int getPublicInt() {
        return publicInt;
    }

 };   

class PublicClass : public BaseClass {
    public:
        void display() {
            protectedInt = 20; // Accessible
            publicInt = 30;    // Accessbile
             // privateInt = 40; // Not Accessible

        cout << "ProtectedInt = " << protectedInt << endl;
        cout << "PublicInt = " << publicInt << endl;
        }
};

class ProtectedClass : protected BaseClass {
    public:
        void display() {
            protectedInt = 40; // Accessible
            publicInt  = 50; // Accessible
            // protectedInt = 60; // Not Accessible

            cout << "ProtectedInt = " << protectedInt << endl;
            cout << "PublicInt = " << publicInt << endl;
        }
};

class PrivateClass : private BaseClass {
    public: 
        void display() {
            protectedInt = 60; // Accessible
            publicInt = 70;     // Accessible
            // protectedInt = 80; // Not Accessible

            cout << "ProtectedInt = " << protectedInt << endl;
            cout << "PublicInt = " << publicInt << endl;
        }
};



int main() {
    PublicClass obj1;

    obj1.setPrivateInt(10);
    obj1.setProtectedInt(20);
    obj1.setPublicInt(30);

    cout << "Accessing PrivateInt using getter: " << obj1.getPrivateInt() << endl; // Accessible using getters

    obj1.display();

    cout << "------------------------------" << endl;

    ProtectedClass obj2;
    obj2.display(); // obj2 setPublicInt is not accessible outside the class as it is protected.

    cout << "------------------------------" << endl;

    PrivateClass obj3;
    obj3.display(); // obj3 setPublicInt is not accessible as it is now private.






    return 0;
}