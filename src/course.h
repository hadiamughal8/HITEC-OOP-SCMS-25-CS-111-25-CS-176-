#include <iostream>
#include <string>
using namespace std;

class CapacityExceededException
{
public:
    class error1
    {
    };
};

class Course
{
private:
    string courseCode;
    string courseName;
    int creditHours;
    int maxCapacity;
    int enrolledCount;

public:
    Course()
    {
        courseCode = "";
        courseName = "";
        creditHours = 0;
        maxCapacity = 0;
        enrolledCount = 0;
    }

    Course(string code, string name, int credits, int capacity)
    {
        courseCode = code;
        courseName = name;
        creditHours = credits;
        maxCapacity = capacity;
        enrolledCount = 0;
    }

    string getCourseCode() const
    {
        return courseCode;
    }

    string getCourseName() const
    {
        return courseName;
    }

    int getCreditHours() const
    {
        return creditHours;
    }

    int getMaxCapacity() const
    {
        return maxCapacity;
    }

    int getEnrolledCount() const
    {
        return enrolledCount;
    }

    void setCourseName(string name)
    {
        courseName = name;
    }

    void enrollStudent()
    {
        if(enrolledCount >= maxCapacity)
        {
            throw CapacityExceededException::error1();
        }

        enrolledCount++;
    }

    bool operator==(Course c)
    {
        return courseCode == c.courseCode;
    }

    friend ostream& operator<<(ostream& out, Course c)
    {
        out << "Course Code: " << c.courseCode << endl;
        out << "Course Name: " << c.courseName << endl;
        out << "Credit Hours: " << c.creditHours << endl;
        out << "Capacity: "
            << c.enrolledCount << "/"
            << c.maxCapacity << endl;

        return out;
    }
};

class Enrollment
{
private:
    string studentName;
    Course* course;
    string enrollmentDate;
    string grade;

public:
    Enrollment()
    {
        course = NULL;
    }

    Enrollment(string s, Course* c,
               string date, string g)
    {
        studentName = s;
        course = c;
        enrollmentDate = date;
        grade = g;
    }

    void display()
    {
        cout << "\nStudent: "
             << studentName << endl;

        cout << "Course: "
             << course->getCourseName() << endl;

        cout << "Date: "
             << enrollmentDate << endl;

        cout << "Grade: "
             << grade << endl;
    }
};

class WaitingList
{
private:
    string students[20];
    int count;

public:
    WaitingList()
    {
        count = 0;
    }

    void addStudent(string name)
    {
        if(count < 20)
        {
            students[count++] = name;
        }
    }

    WaitingList operator+(WaitingList w)
    {
        WaitingList temp;

        for(int i = 0; i < count; i++)
        {
            temp.students[temp.count++] = students[i];
        }

        for(int i = 0; i < w.count; i++)
        {
            temp.students[temp.count++] = w.students[i];
        }

        return temp;
    }

    void display()
    {
        for(int i = 0; i < count; i++)
        {
            cout << students[i] << endl;
        }
    }
};

int main()
{
    Course c1("CS101",
              "OOP",
              3,
              2);

    try
    {
        c1.enrollStudent();
        c1.enrollStudent();
        c1.enrollStudent();
    }
    catch(CapacityExceededException::error1)
    {
        cout << "Capacity Exceeded" << endl;
    }
cout<<"course information :"<<endl;
    cout << c1 << endl;
  Enrollment e1("Ali", &c1, "18-06-2026", "A");
   cout<<"enrollment information :"<<endl;
    e1.display();
    WaitingList w1;
    w1.addStudent("Ahmed");
    w1.addStudent("Sara");
 cout<<"waiting list of students :"<<endl;
    w1.display();
    Course c2("CS101",
              "Programming",
              3,
              50);

    if(c1 == c2)
    {
        cout << "Same Course Code" << endl;
    }

    return 0;
}
