#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char *firstName;
    string lastName;
    int salary;

public:
    Employee() : firstName(nullptr), lastName(""), salary(0) {}

    void setInfo(const char *first, string last, int amt)
    {
        firstName = new char[strlen(first) + 1];
        strcpy(firstName, first);
        lastName = last;
        if (amt > 0)
            salary = amt;
        else
            salary = 0;
    }

    char* getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    int getSalary() {
        return salary;
    }

    int getYearlySalary() {
        return salary * 12;
    }

    void raise(float perc) {
        salary += salary*perc/100.0;
    }
    ~Employee() {
        delete[] firstName;
    }
};

int main()
{
    Employee emp1, emp2;
    emp1.setInfo("Faarid", "Amir", -500000);
    emp2.setInfo("Rayyan", "Ahmed", 500000);
    cout << "====Employee Info====" << endl;
    cout << endl << "Employee 1:" << endl << "Name: " << emp1.getFirstName() << " " << emp1.getLastName() << endl << "Yearly Salary: " << emp1.getYearlySalary() << endl;
    cout << endl << "Employee 2:" << endl << "Name: " << emp2.getFirstName() << " " << emp2.getLastName() << endl << "Yearly Salary: " << emp2.getYearlySalary() << endl;

    emp1.raise(10);
    emp2.raise(10);

    cout<<endl<< "After getting a raise:" << endl;
    cout << "====Employee Info====" << endl;
    cout << endl << "Employee 1:" << endl << "Name: " << emp1.getFirstName() << " " << emp1.getLastName() << endl << "Yearly Salary: " << emp1.getYearlySalary() << endl;
    cout << endl << "Employee 2:" << endl << "Name: " << emp2.getFirstName() << " " << emp2.getLastName() << endl << "Yearly Salary: " << emp2.getYearlySalary() << endl;
    return 0;
}
