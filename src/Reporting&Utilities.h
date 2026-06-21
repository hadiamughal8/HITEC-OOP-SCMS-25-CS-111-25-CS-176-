#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Student {
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
