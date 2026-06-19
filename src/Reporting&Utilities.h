#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student{
private:
    string name;
    string rollNo;
    float GPA;
public:
    Student() {
        name = "";
        rollNo = "";
        GPA = 0.0;
    }
    Student(string n, string r, float g) {
        name = n;
        rollNo = r;
        GPA = g;
    }
    string getName() { return name; }
    string getRollNo() { return rollNo; }
    float getGPA() { return GPA; }
};

class Book {
private:
    string title;
    bool isOverdue;
public:
    Book() {
        title = "";
        isOverdue = false;
    }
    Book(string t, bool overdue) {
        title = t;
        isOverdue = overdue;
    }
    string getTitle() { return title; }
    bool getIsOverdue() { return isOverdue; }
};


namespace SCMS {
    namespace Utils {
        
        bool isValidCNIC(const string& cnic) {
            return cnic.length() == 13;
        }
        
        
        string toUpperCase(string str) {
            for (size_t i = 0; i < str.length(); i++) {
                str[i] = toupper(str[i]);
            }
            return str;
        }
        
        /
        void displayDate() {
            cout << "Report Date: 19/06/2026" << endl;
        }
    }
    
    namespace Reports {
     
        void generateReport(Student* students[], int studentCount, Book books[], int bookCount) {
            
            cout << "             CAMPUS CONSOLIDATED REPORT" << endl;
            
            Utils::displayDate();

            
           
            for (int i = 0; i < studentCount - 1; i++) {
                for (int j = 0; j < studentCount - i - 1; j++) {
                    auto compare = [](Student* a, Student* b) {
                        return a->getGPA() < b->getGPA();
                    };
                    if (compare(students[j], students[j + 1])) {
                        Student* temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            
            cout << "\n[STUDENTS SORTED BY GPA]" << endl;
            for (int i = 0; i < studentCount; i++) {
                cout << i + 1 << ". Name: " << Utils::toUpperCase(students[i]->getName())
                     << " | GPA: " << students[i]->getGPA() << endl;
            }
            
           
            auto isProbation = [](Student* s) {
                return s->getGPA() < 2.0;
            };
            
            cout << "\n[STUDENTS ON PROBATION]" << endl;
            bool foundProbation = false;
            for (int i = 0; i < studentCount; i++) {
                if (isProbation(students[i])) {
                    cout << " - " << students[i]->getName() << " (GPA: " << students[i]->getGPA() << ")" << endl;
                    foundProbation = true;
                }
            }
            if (!foundProbation) {
                cout << " None." << endl;
            }
            
        
            auto isOverdue = [](Book b) {
                return b.getIsOverdue();
            };
            
            cout << "\n[OVERDUE LIBRARY BOOKS]" << endl;
            bool foundOverdue = false;
            for (int i = 0; i < bookCount; i++) {
                if (isOverdue(books[i])) {
                    cout << " - Title: \"" << books[i].getTitle() << "\"" << endl;
                    foundOverdue = true;
                }
            }
            if (!foundOverdue) {
                cout << " None." << endl;
            }
          
        }
    }
}


int main() {
    int studentCount = 4;
    Student* campusStudents[4];
    
    campusStudents[0] = new Student("Omama", "25-CS-176", 3.85);
    campusStudents[1] = new Student("Hadia", "25-CS-111", 1.80);
    campusStudents[2] = new Student("Syed", "25-CS-012", 3.40);
    campusStudents[3] = new Student("Kashif", "25-CS-13", 1.50);
    
    int bookCount = 3;
    Book libraryCatalog[3];
    libraryCatalog[0] = Book("C++ Programming", false);
    libraryCatalog[1] = Book("Data Structures Guide", true);
    libraryCatalog[2] = Book("Database Systems Guide", true);
    
    int choice = 0;
    while (choice != 3) {
        cout << "\n===== REPORT MENU =====" << endl;
        cout << "1. Generate Consolidated Report" << endl;
        cout << "2. Validate CNIC" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        if (choice == 1) {
            SCMS::Reports::generateReport(campusStudents, studentCount, libraryCatalog, bookCount);
        } 
        else if (choice == 2) {
            string cnic;
            cout << "Enter 13-digit CNIC: ";
            cin >> cnic;
            if (SCMS::Utils::isValidCNIC(cnic)) {
                cout << "CNIC is Valid." << endl;
            } else {
                cout << "CNIC is Invalid." << endl;
            }
        }
    }
    
    // Clean up memory
    for (int i = 0; i < studentCount; i++) {
        delete campusStudents[i];
    }
    
    return 0;
}
