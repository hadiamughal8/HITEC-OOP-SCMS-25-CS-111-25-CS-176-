#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string CNIC;
    int age;
    string contact;

public:
    Person(string n, string cnic, int a, string con) {
        name = n;
        CNIC = cnic;
        age = a;
        contact = con;
    }

    virtual void displayInfo() = 0;

    virtual void getdata() {
        cin >> name >> CNIC >> age >> contact;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string rollNo;
    int semester;
    float GPA;
    string enrolledCourses[3];

public:
    Student() : Person("", "", 0, "") {
        rollNo = "";
        semester = 0;
        GPA = 0.0;

        for (int i = 0; i < 3; i++) {
            enrolledCourses[i] = "";
        }
    }

    Student(string n, string cnic, int a, string con,
            string r, int sem, float gpa, string courses[])
        : Person(n, cnic, a, con) {

        rollNo = r;
        semester = sem;
        GPA = gpa;

        for (int i = 0; i < 3; i++)
            enrolledCourses[i] = courses[i];
    }

    void getdata() override {
        Person::getdata();

        cin >> rollNo >> semester >> GPA;

        for (int i = 0; i < 3; i++) {
            cin >> enrolledCourses[i];
        }
    }

    char calculateGrade() {
        if (GPA >= 3.7)
            return 'A';
        else if (GPA >= 3.0)
            return 'B';
        else if (GPA >= 2.0)
            return 'C';
        else
            return 'F';
    }

    void displayInfo() override {
        cout << "\n----- Student Information -----" << endl;
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Semester: " << semester << endl;
        cout << "GPA: " << GPA << endl;

        cout << "Enrolled Courses: ";
        for (int i = 0; i < 3; i++) {
            cout << enrolledCourses[i] << " ";
        }

        cout << "\nGrade: " << calculateGrade() << endl;
    }
};

class Faculty : public Person {
private:
    string employeeID;
    string department;
    string designation;
    string assignedCourses[3];

public:
    Faculty() : Person("", "", 0, "") {
        employeeID = "";
        department = "";
        designation = "";

        for (int i = 0; i < 3; i++) {
            assignedCourses[i] = "";
        }
    }

    Faculty(string n, string cnic, int a, string con,
            string empID, string dept,
            string desig, string courses[])
        : Person(n, cnic, a, con) {

        employeeID = empID;
        department = dept;
        designation = desig;

        for (int i = 0; i < 3; i++)
            assignedCourses[i] = courses[i];
    }

    void getdata() override {
        Person::getdata();

        cin >> employeeID >> department >> designation;

        for (int i = 0; i < 3; i++) {
            cin >> assignedCourses[i];
        }
    }

    void displayInfo() override {
        cout << "\n----- Faculty Information -----" << endl;
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;

        cout << "Assigned Courses: ";
        for (int i = 0; i < 3; i++) {
            cout << assignedCourses[i] << " ";
        }
        cout << endl;
    }
};

class Staff : public Person {
private:
    string staffID;
    string role;
    double salary;

public:
    Staff() : Person("", "", 0, "") {
        staffID = "";
        role = "";
        salary = 0;
    }

    Staff(string n, string cnic, int a, string con,
          string id, string r, double s)
        : Person(n, cnic, a, con) {

        staffID = id;
        role = r;
        salary = s;
    }

    void getdata() override {
        Person::getdata();
        cin >> staffID >> role >> salary;
    }

    void displayInfo() override {
        cout << "\n----- Staff Information -----" << endl;
        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Staff ID: " << staffID << endl;
        cout << "Role: " << role << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Person *p;
    int choice;

    do {
        cout << "\n1. Student";
        cout << "\n2. Faculty";
        cout << "\n3. Staff";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            p = new Student();
            p->getdata();
            p->displayInfo();
            delete p;
            break;

        case 2:
            p = new Faculty();
            p->getdata();
            p->displayInfo();
            delete p;
            break;

        case 3:
            p = new Staff();
            p->getdata();
            p->displayInfo();
            delete p;
            break;

        case 4:
            cout << "Program Ended" << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
        }

    } while (choice != 4);

    return 0;
}