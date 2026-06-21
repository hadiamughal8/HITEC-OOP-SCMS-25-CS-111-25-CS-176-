#include<iostream>
using namespace std;
#include "src/person.h"
#include "src/course.h"
#include "src/library.h"
#include "src/finance.h"
#include "src/hostel.h"
#include "src/Reporting&Utilities.h"
int main()
{
int moduleChoice;
do
{
    cout << "\n===== SCMS MAIN MENU =====" << endl;
    cout << "1. Person Module" << endl;
    cout << "2. Course Module" << endl;
    cout << "3. Library Module" << endl;
    cout << "4. Finance Module" << endl;
    cout << "5. Hostel Module" << endl;
    cout << "6. Reports Module" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter Choice: ";
    cin >> moduleChoice;

    switch(moduleChoice)
    {
    case 1:
    {
        Person* p =      NULL;
        int choice;

        do
        {
            cout << endl << "========== MENU ==========" << endl;
            cout << "1. Student" << endl;
            cout << "2. Faculty" << endl;
            cout << "3. Staff" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;

            switch(choice)
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
            }
        }
        while(choice != 4);

        break;
    }

    case 2:
    {
        Course c1("CS101","OOP",3,2);

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

        cout << c1 << endl;

        Enrollment e1("Ali",&c1,"18-06-2026","A");
        e1.display();

        WaitingList w1;
        w1.addStudent("Ahmed");
        w1.addStudent("Sara");
        w1.display();

        Course c2("CS101","Programming",3,50);

        if(c1 == c2)
            cout << "Same Course Code" << endl;

        break;
    }

    case 3:
    {
        Library lib;
        LibraryItem* ptr;
        int opt;

        cout << "1: Add Book" << endl;
        cout << "2: Add Journal" << endl;
        cin >> opt;

        if(opt == 1)
        {
            ptr = new Book();
            ptr->getdata();
            lib.addItem(ptr);
        }
        else if(opt == 2)
        {
            ptr = new Journal();
            ptr->getdata();
            lib.addItem(ptr);
        }

        lib.displayCatalog();
        lib.searchByTitle("OOP");

        lib.issueItem("25-cs-176",123);

        lib.saveToFile();

        try
        {
            lib.returnItem(3);
        }
        catch(OverdueException e)
        {
            cout << "Overdue Fine = Rs."
                 << e.getFine() << endl;
        }

        break;
    }

    case 4:
    {
        FeeRecord f1("ST101",50000,10000,2000,30000);
        f1.display();

        f1 -= 5000;
        f1.display();

        FeeRecord f2 = f1;
        f2.display();

        FeeRecord f3;
        f3 = f1;
        f3.display();

        Invoice i1("11-06-2026",3,62000);

        i1.setItem(0,"Semester Fee");
        i1.setItem(1,"Hostel Fee");
        i1.setItem(2,"Library Fine");

        i1.display();

        break;
    }

    case 5:
    {
        HostelManager manager("HITEC Hostel","Ayesha Block");

        manager.addRoom(Room(101,"Single",1));
        manager.addRoom(Room(102,"Double",1));

        hostelStudent s1("Omama","25-CS-176");
        hostelStudent s2("Hadia","25-CS-111");

        int choice = 0;

        while(choice != 4)
        {
            cout << "\n1. Allocate Room" << endl;
            cout << "2. Vacate Room" << endl;
            cout << "3. Show Report" << endl;
            cout << "4. Exit" << endl;

            cin >> choice;

            if(choice == 1)
            {
                int rNum, sNum;
                cin >> rNum >> sNum;

                if(sNum == 1)
                    manager.allocateRoom(&s1,rNum);
                else
                    manager.allocateRoom(&s2,rNum);
            }
            else if(choice == 2)
            {
                int rNum;
                cin >> rNum;
                manager.vacateRoom(rNum);
            }
            else if(choice == 3)
            {
                manager.generateReport();
            }
        }

        break;
    }

    case 6:
    {
        int studentCount = 4;

        reportStudent* campusStudents[4];

        campusStudents[0] = new reportStudent("Omama","25-CS-176",3.85);
        campusStudents[1] = new reportStudent("Hadia","25-CS-111",1.80);
        campusStudents[2] = new reportStudent("Syed","25-CS-012",3.40);
        campusStudents[3] = new reportStudent("Kashif","25-CS-13",1.50);

        int bookCount = 3;

        reportBook libraryCatalog[3];

        libraryCatalog[0] = reportBook("C++ Programming",false);
        libraryCatalog[1] = reportBook("Data Structures Guide",true);
        libraryCatalog[2] = reportBook("Database Systems Guide",true);

        int choice = 0;

        while(choice != 3)
        {
            cout << "\n===== REPORT MENU =====" << endl;
            cout << "1. Generate Consolidated Report" << endl;
            cout << "2. Validate CNIC" << endl;
            cout << "3. Exit" << endl;

            cin >> choice;

            if(choice == 1)
            {
                SCMS::Reports::generateReport(
                    campusStudents,
                    studentCount,
                    libraryCatalog,
                    bookCount
                );
            }
            else if(choice == 2)
            {
                string cnic;
                cin >> cnic;

                if(SCMS::Utils::isValidCNIC(cnic))
                    cout << "CNIC is Valid." << endl;
                else
                    cout << "CNIC is Invalid." << endl;
            }
        }

        for(int i = 0; i < studentCount; i++)
            delete campusStudents[i];

        break;
    }

    case 7:
        cout << "Program Ended Successfully." << endl;
        break;

    default:
        cout << "Invalid Choice." << endl;
    }

} while(moduleChoice != 7);

return 0;
}
