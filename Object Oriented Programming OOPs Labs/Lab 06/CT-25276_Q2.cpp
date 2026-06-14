#include <iostream>
using namespace std;

class Calculator{
    private: 
        double num1, num2, num3;

    public:
        Calculator(int a, int b, int c) : num1(a), num2(b), num3(c){
           
        }
        double add(double a, double b){
            return a + b;
        } 
        
        double add(double a, double b, double c){
            return a + b + c;
        } 
        double subtract(double a, double b){
            return a - b;
        } 
        
        double subtract(double a, double b, double c){
            return a - b - c;
        } 

        double multiply(double a, double b){
            return a * b;
        } 
        double multiply(double a, double b, double c){
            return a * b * c;
        } 
        double divide(double a, double b){
            if(b == 0){
                cout << "Division not possible" << endl; return 0;
            }
            return a / b;
        } 
        double divide(double a, double b, double c){
             if(b == 0 || c == 0){
                cout << "Division not possible" << endl; return 0;
            }
            return a / b / c;
        } 
        
};

int main() {
    Calculator calc(0, 0, 0);
    double n1, n2, n3;
    cout << "===========This is a basic arithmic calculator=========" << endl;
    cout << "Enter 3 Numbers: " ;
    cin >> n1 >> n2 >> n3;

    
    
    cout << "Addition (2 Numbers): " << calc.add(n1, n2) << endl;
    cout << "Addition (3 Numbers): " << calc.add(n1, n2, n3) << endl;
    cout << "Subtraction (2 Numbers): " << calc.subtract(n1, n2) << endl;
    cout << "Subtraction (3 Numbers): " << calc.subtract(n1, n2, n3) << endl;
    cout << "Multiplicattion (2 Numbers): " << calc.multiply(n1, n2) << endl;
    cout << "Multiplicattion (3 Numbers): " << calc.multiply(n1, n2, n3) << endl;
    cout << "Division (2 Numbers): " << calc.divide(n1, n2) << endl;
    cout << "Division (3 Numbers): " << calc.divide(n1, n2, n3) << endl;
    return 0;
}