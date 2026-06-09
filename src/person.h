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
    Person(string n, string c, int a, string con)
    {
        name = n;
        CNIC = c;
        age = a;
        contact = con;
    }

    virtual void displayInfo() = 0;

    virtual void getdata()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter CNIC: ";
        cin >> CNIC;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Contact Number: ";
        cin >> contact;
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
    Student() : Person("", "", 0, "")
    {
        rollNo = "";
        semester = 0;
        GPA = 0.0;
    }

    void getdata() override
    {
        Person::getdata();

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Semester: ";
        cin >> semester;

        cout << "Enter GPA: ";
        cin >> GPA;

        cout << "Enter 3 Enrolled Courses:\n";

        for (int i = 0; i < 3; i++)
        {
            cout << "Course " << i + 1 << ": ";
            cin >> enrolledCourses[i];
        }
    }

    char calculateGrade()
    {
        if (GPA >= 3.7)
            return 'A';
        else if (GPA >= 3.0)
            return 'B';
        else if (GPA >= 2.0)
            return 'C';
        else
            return 'F';
    }

    void displayInfo() override
    {
        cout << "\n===== STUDENT INFORMATION =====\n";

        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Semester: " << semester << endl;
        cout << "GPA: " << GPA << endl;

        cout << "Courses: ";
        for (int i = 0; i < 3; i++)
        {
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
    Faculty() : Person("", "", 0, "")
    {
        employeeID = "";
        department = "";
        designation = "";
    }

    void getdata() override
    {
        Person::getdata();

        cout << "Enter Employee ID: ";
        cin >> employeeID;

        cout << "Enter Department: ";
        cin >> department;

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter 3 Assigned Courses:\n";

        for (int i = 0; i < 3; i++)
        {
            cout << "Course " << i + 1 << ": ";
            cin >> assignedCourses[i];
        }
    }

    void displayInfo() override
    {
        cout << "\n===== FACULTY INFORMATION =====\n";

        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;

        cout << "Assigned Courses: ";

        for (int i = 0; i < 3; i++)
        {
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
    Staff() : Person("", "", 0, "")
    {
        staffID = "";
        role = "";
        salary = 0;
    }

    void getdata() override
    {
        Person::getdata();

        cout << "Enter Staff ID: ";
        cin >> staffID;

        cout << "Enter Role: ";
        cin >> role;

        cout << "Enter Salary: ";
        cin >> salary;
    }
   double salarybonus()
{
    return salary + 1000;
}

    void displayInfo() override
    {
        cout << "\n===== STAFF INFORMATION =====\n";

        cout << "Name: " << name << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Staff ID: " << staffID << endl;
        cout << "Role: " << role << endl;
        cout << "Salary: " << salary << endl;
        cout << "Salary with Bonus: " << salarybonus() << endl;
    }
};

int main()
{
    Person* p = NULL;
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Student\n";
        cout << "2. Faculty\n";
        cout << "3. Staff\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input!\n";
            continue;
        }

        switch (choice)
        {
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
            cout << "\nProgram Ended Successfully.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}
