#include <iostream>
#include <fstream>
#include <string>

using namespace std;









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
        
        
        
        
        
        
        
              
			  
			  
			   void displayDate() {
            cout << "Report Date: 19/06/2026" << endl;
        }
    }
    
    namespace Reports {
     
        void generateReport(Student* students[], int studentCount, Book books[], int bookCount) {
            
            cout << "             CAMPUS CONSOLIDATED REPORT" << endl;
            
            Utils::displayDate();








cout << "\n[STUDENTS SORTED BY GPA]" << endl;
            for (int i = 0; i < studentCount; i++) {
                cout << i + 1 << ". Name: " << Utils::toUpperCase(students[i]->getName())
                     << " | GPA: " << students[i]->getGPA() << endl;
            }
            
           
            auto isProbation = [](Student* s) {
                return s->getGPA() < 2.0;
            };
            
            
            
            
            
            auto isOverdue = [](Book b) {
                return b.getIsOverdue();
            };
            
            
            
            
            
            
            
            
                        if (!foundOverdue) {
                cout << " None." << endl;
            }
          
        }
    }
}
int main() {
    int studentCount = 4;
    Student* campusStudents[4];
    
    
    
    
    
    
    
    
    
    
        int bookCount = 3;
    Book libraryCatalog[3];
    libraryCatalog[0] = Book("C++ Programming", false);
    libraryCatalog[1] = Book("Data Structures Guide", true);
    libraryCatalog[2] = Book("Database Systems Guide", true);
    
    
    
    
    
    
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
    
    
    for (int i = 0; i < studentCount; i++) {
        delete campusStudents[i];
    }
    
    return 0;
}
