#include <iostream>
#include <cmath>   // for sqrt() in magnitude
using namespace std;

class Vector {
private:
    double x, y;

public:
    // ─────────────────────────────────────────
    // Constructor
    // ─────────────────────────────────────────
    Vector(double x = 0, double y = 0) : x(x), y(y) {}

    // ─────────────────────────────────────────
    // Operator Overloading
    // ─────────────────────────────────────────

    // + operator: adds two Vectors
    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    // - operator: subtracts two Vectors
    Vector operator-(const Vector& other) {
        return Vector(x - other.x, y - other.y);
    }

    // * operator: multiplies Vector by a scalar
    Vector operator*(double scalar) {
        return Vector(x * scalar, y * scalar);
    }

    // / operator: divides Vector by a scalar
    Vector operator/(double scalar) {
        if (scalar == 0) {
            cout << "Error: Division by zero!" << endl;
            return Vector(0, 0);
        }
        return Vector(x / scalar, y / scalar);
    }

    // ─────────────────────────────────────────
    // Magnitude: √(x² + y²)
    // ─────────────────────────────────────────
    double magnitude() {
        return sqrt(x * x + y * y);
    }

    // ─────────────────────────────────────────
    // Display the vector nicely
    // ─────────────────────────────────────────
    void display(const string& label = "") {
        if (!label.empty()) cout << label << ": ";
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() {
    Vector v1(4, 3);
    Vector v2(1, 2);

    v1.display("v1");
    v2.display("v2");

    cout << "\n--- Operator Demonstrations ---" << endl;

    // Addition
    Vector sum = v1 + v2;
    sum.display("v1 + v2");

    // Subtraction
    Vector diff = v1 - v2;
    diff.display("v1 - v2");

    // Multiplication by scalar
    Vector scaled = v1 * 3;
    scaled.display("v1 * 3");

    // Division by scalar
    Vector divided = v1 / 2;
    divided.display("v1 / 2");

    // Magnitude
    cout << "\nMagnitude of v1: " << v1.magnitude() << endl;  // √(16+9) = 5
    cout << "Magnitude of v2: " << v2.magnitude() << endl;  // √(1+4)  = 2.236

    return 0;
}