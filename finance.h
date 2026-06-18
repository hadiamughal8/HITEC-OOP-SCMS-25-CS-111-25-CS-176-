#include <iostream>
#include <string>
using namespace std;

class FeeRecord
{
private:
    string studentRef;
    double semesterFee;
    double hostelFee;
    double libraryFine;
    double totalPaid;
    double balance;

public:

    FeeRecord()
    {
        studentRef = "";
        semesterFee = 0;
        hostelFee = 0;
        libraryFine = 0;
        totalPaid = 0;
        balance = 0;
    }

    FeeRecord(string ref, double semFee, double hostFee,double fine,double paid)
    {
        studentRef = ref;
        semesterFee = semFee;
        hostelFee = hostFee;
        libraryFine = fine;
        totalPaid = paid;
        balance = (semesterFee + hostelFee + libraryFine)- totalPaid;
    }

    FeeRecord(const FeeRecord& obj)
    {
        studentRef = obj.studentRef;
        semesterFee = obj.semesterFee;
        hostelFee = obj.hostelFee;
        libraryFine = obj.libraryFine;
        totalPaid = obj.totalPaid;
        balance = obj.balance;

        cout << "\nCopy Constructor Called\n";
    }

    FeeRecord& operator=(const FeeRecord& obj)
    {
        if(this != &obj)
        {
            studentRef = obj.studentRef;
            semesterFee = obj.semesterFee;
            hostelFee = obj.hostelFee;
            libraryFine = obj.libraryFine;
            totalPaid = obj.totalPaid;
            balance = obj.balance;
        }

        return *this;
    }

    void operator-=(double payment)
    {
        totalPaid += payment;
        balance -= payment;
    }

    void display()
    {
        cout << "Student Reference: "
             << studentRef << endl;

        cout << "Semester Fee: "
             << semesterFee << endl;

        cout << "Hostel Fee: "
             << hostelFee << endl;

        cout << "Library Fine: "
             << libraryFine << endl;

        cout << "Total Paid: "
             << totalPaid << endl;

        cout << "Balance: "
             << balance << endl;
    }
};

class Invoice
{
private:

    static int invoiceCounter;
    int invoiceID;
    string date;
    string* items;
    int itemCount;
    double totalAmount;

public:

    Invoice(string d, int count, double amount)
    {
        invoiceCounter++;
        invoiceID = invoiceCounter;
        date = d;
        itemCount = count;
        totalAmount = amount;
        items = new string[itemCount];
    }

    void setItem(int index, string item)
    {
        if(index >= 0 && index < itemCount)
        {
            items[index] = item;
        }
    }

    void display()
    {
        cout << "Invoice ID: "
             << invoiceID << endl;

        cout << "Date: "
             << date << endl;

        cout << "Items:" << endl;

        for(int i = 0; i < itemCount; i++)
        {
            cout << "- " << items[i] << endl;
        }

        cout << "Total Amount: "
             << totalAmount << endl;
    }

    ~Invoice()
    {
        delete[] items;

        cout << "Invoice Destroyed\n";
    }
};

int Invoice::invoiceCounter = 0;

int main()
{
    cout << "===== Fee Record =====\n";
    FeeRecord f1("ST101",50000,10000,2000,30000);
    f1.display();
    
    cout << "\nPayment of 5000 Recorded\n";
    f1 -= 5000;
    f1.display();

    cout << "\n===== Copy Constructor =====\n";
    FeeRecord f2 = f1;
    f2.display();

    cout << "\n===== Assignment Operator =====\n";
    FeeRecord f3;
    f3 = f1;
    f3.display();

    cout << "\n===== Invoice =====\n";

    Invoice i1( "11-06-2026", 3, 62000);

    i1.setItem(0,"Semester Fee");
    i1.setItem(1,"Hostel Fee");
    i1.setItem(2,"Library Fine");

    i1.display();

    return 0;
}
