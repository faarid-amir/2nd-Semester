#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
    char *EmployeeName;
    const int EmployeeId;

public:
    Employee(int id, const char *name = "N/A") : EmployeeId(id)
    {
        EmployeeName = new char[strlen(name) + 1]();
        strcpy(EmployeeName, name);
    }
    char *getName() { return EmployeeName; }
    void changeName(const char *name)
    {
        delete[] EmployeeName;
        EmployeeName = new char[strlen(name) + 1]();
        strcpy(EmployeeName, name);
    }
    int getID() const { return EmployeeId; }
    ~Employee() { delete[] EmployeeName; }
};

int main()
{
    Employee Employee1(1001, "Jhon"), Employee2(1002, "Jhonathan"), Employee3(1003, "Jhonny");
    cout << "IDs\tNames" << endl;
    cout << Employee1.getID() << "\t" << Employee1.getName() << endl;
    cout << Employee2.getID() << "\t" << Employee2.getName() << endl;
    cout << Employee3.getID() << "\t" << Employee3.getName() << endl;

    Employee2.changeName("Jhonny");

    cout << "\033[1;33m====After changing Employee2 name====\033[0m" << endl;
    cout << "IDs\tNames" << endl;
    cout << Employee1.getID() << "\t" << Employee1.getName() << endl;
    cout << Employee2.getID() << "\t" << Employee2.getName() << endl;
    cout << Employee3.getID() << "\t" << Employee3.getName() << endl;
    return 0;
}