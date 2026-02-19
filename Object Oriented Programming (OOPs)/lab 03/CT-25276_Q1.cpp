#include <iostream>
using namespace std;

class Complex {
    private:
    int* real;
    int* imag;

    public:
        Complex(int r, int i) {
            real = new int;
            imag = new int;

            *real = r;
            *imag = i;
        }

        Complex(const Complex& obj) {
            real = new int;
            imag = new int;

            *real = *(obj.real);
            *imag = *(obj.imag);

        
        }

        void display() {
            cout << "real: " << *real << " imag: " << *imag << endl;
         }

         ~Complex() {
            delete real;
            delete imag;
         }
};

int main() {

    Complex c1(10, 20);
    Complex c2 = c1;

    c1.display();
    c2.display();
}