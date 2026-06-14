#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int id;
    string designation;
    double salary;

public:
    Employee(string n, int i, string d, double s)
        : name(n), id(i), designation(d), salary(s) {}

    void display() const
    {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Role: " << designation
             << " | Salary: " << salary << "\n";
    }

    friend void giveRaise(Employee &emp, double amount);
    friend void givePercentRaise(Employee &emp, double percent);
    friend void promote(Employee &emp, string newDesignation, double newSalary);
};

void giveRaise(Employee &emp, double amount)
{
    emp.salary += amount;
    cout << emp.name << "'s salary updated by +" << amount << "\n";
}

void givePercentRaise(Employee &emp, double percent)
{
    double increase = emp.salary * (percent / 100.0);
    emp.salary += increase;
    cout << emp.name << "'s salary updated by " << percent << "%\n";
}

void promote(Employee &emp, string newDesignation, double newSalary)
{
    emp.designation = newDesignation;
    emp.salary = newSalary;
    cout << emp.name << " promoted to " << newDesignation
         << " with salary " << newSalary << "\n";
}

int main()
{

    Employee e1("Usman Waqas", 101, "Junior Dev", 50000);
    Employee e2("Iman Khan", 102, "Designer", 45000);
    Employee e3("Faarid Amir", 103, "Manager", 80000);

    cout << "===== Before Update =====\n";
    e1.display();
    e2.display();
    e3.display();

    giveRaise(e1, 5000);
    givePercentRaise(e2, 10);
    promote(e3, "Senior Manager", 95000);

    cout << "\n===== After Update =====\n";
    e1.display();
    e2.display();
    e3.display();

    return 0;
}