#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class EncryptionTechnique {
protected:
    string message;

public:
    EncryptionTechnique(string msg) {
        message = msg;
    }

    virtual void encrypt() = 0; // Pure virtual function
};

// Derived Class: EncryptionTechnique1
// Converts each alphabet to its ASCII code
class EncryptionTechnique1 : public EncryptionTechnique {
public:
    EncryptionTechnique1(string msg) : EncryptionTechnique(msg) {}

    void encrypt() override {
        cout << "Technique 1 Encrypted Message: ";
        for (int i = 0; i < message.length(); i++) {
            cout << (int)message[i];
        }
        cout << endl;
    }
};

// Derived Class: EncryptionTechnique2
// Converts each alphabet to its ASCII code and adds 2
class EncryptionTechnique2 : public EncryptionTechnique {
public:
    EncryptionTechnique2(string msg) : EncryptionTechnique(msg) {}

    void encrypt() override {
        cout << "Technique 2 Encrypted Message: ";
        for (int i = 0; i < message.length(); i++) {
            cout << (int)message[i] + 2;
        }
        cout << endl;
    }
};

int main() {
    string input;
    cout << "Enter message to encrypt: ";
    cin >> input;

    EncryptionTechnique* e1 = new EncryptionTechnique1(input);
    EncryptionTechnique* e2 = new EncryptionTechnique2(input);

    e1->encrypt();
    e2->encrypt();

    delete e1;
    delete e2;

    return 0;
}