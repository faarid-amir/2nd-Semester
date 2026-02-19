#include <iostream>
using namespace std;

class Teacher {
protected:
    string Name;
    int Age;
    string Institute;

public:
    // Setters
    void setName(string name) {
        Name = name;
    }

    void setAge(int age) {
        Age = age;
    }

    void setInstitute(string institute) {
        Institute = institute;
    }

    // Getters
    string getName() {
        return Name;
    }

    int getAge() {
        return Age;
    }

    string getInstitute() {
        return Institute;
    }
};



class HumanitiesTeacher : public Teacher {
private:
    string Department = "Humanities";
    string CourseName;
    string Designation;

public:
    void setCourseName(string course) {
        CourseName = course;
    }

    void setDesignation(string designation) {
        Designation = designation;
    }

    void display() {
        cout << "\n--- Humanities Teacher ---\n";
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Institute: " << Institute << endl;
        cout << "Department: " << Department << endl;
        cout << "Course Name: " << CourseName << endl;
        cout << "Designation: " << Designation << endl;
    }
};



class ScienceTeacher : public Teacher {
private:
    string Department = "Science";
    string CourseName;
    string Designation;

public:
    void setCourseName(string course) {
        CourseName = course;
    }

    void setDesignation(string designation) {
        Designation = designation;
    }

    void display() {
        cout << "\n--- Science Teacher ---\n";
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Institute: " << Institute << endl;
        cout << "Department: " << Department << endl;
        cout << "Course Name: " << CourseName << endl;
        cout << "Designation: " << Designation << endl;
    }
};



class MathsTeacher : public Teacher {
private:
    string Department = "Maths";
    string CourseName;
    string Designation;

public:
    void setCourseName(string course) {
        CourseName = course;
    }

    void setDesignation(string designation) {
        Designation = designation;
    }

    void display() {
        cout << "\n--- Maths Teacher ---\n";
        cout << "Name: " << Name << endl;
        cout << "Age: " << Age << endl;
        cout << "Institute: " << Institute << endl;
        cout << "Department: " << Department << endl;
        cout << "Course Name: " << CourseName << endl;
        cout << "Designation: " << Designation << endl;
    }
};


int main() {

    HumanitiesTeacher h;
    ScienceTeacher s;
    MathsTeacher m;

    string name, institute, course, designation;
    int age;

    
    cout << "Enter Humanities Teacher Details:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Institute: ";
    cin >> institute;
    cout << "Course Name: ";
    cin >> course;
    cout << "Designation: ";
    cin >> designation;

    h.setName(name);
    h.setAge(age);
    h.setInstitute(institute);
    h.setCourseName(course);
    h.setDesignation(designation);

    cout << "\nEnter Science Teacher Details:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Institute: ";
    cin >> institute;
    cout << "Course Name: ";
    cin >> course;
    cout << "Designation: ";
    cin >> designation;

    s.setName(name);
    s.setAge(age);
    s.setInstitute(institute);
    s.setCourseName(course);
    s.setDesignation(designation);

    
    cout << "\nEnter Maths Teacher Details:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Institute: ";
    cin >> institute;
    cout << "Course Name: ";
    cin >> course;
    cout << "Designation: ";
    cin >> designation;

    m.setName(name);
    m.setAge(age);
    m.setInstitute(institute);
    m.setCourseName(course);
    m.setDesignation(designation);

    
    h.display();
    cout << "------------------------------" << endl;
    s.display();
    cout << "------------------------------" << endl;
    m.display();

    return 0;
}
