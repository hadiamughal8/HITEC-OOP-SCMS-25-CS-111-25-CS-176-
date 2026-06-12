#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class OverdueException
{
    float fine;
public:
    OverdueException(float f)
    {
        fine = f;
    }

    float getFine()
    {
        return fine;
    }
};
class LibraryItem
{
protected:
    int itemID;
    string title;
    string author;
    int publicationYear;
public:
    LibraryItem(int id=0, string t="", string a="", int year=0)
    {
        itemID = id;
        title = t;
        author = a;
        publicationYear = year;
    }
     string getTitle()
    {
        return title;
    }

    virtual void checkout() = 0;
    virtual void getdata()
    {
        cout<<"enter itemid :"<<endl;
    	cin>>itemID;
        cout<<"enter title :"<<endl;
       cin >>title;
       cout<<"enter author :"<<endl;
       cin>>author;
       cout<<"enter publicationyear :"<<endl;
       cin>>publicationYear;
	}
    virtual void display()
    {
        cout << "Item ID: " << itemID;
        cout << "Title: " << title;
        cout << "Author: " << author;
        cout << "Publication Year: " << publicationYear;
}
    virtual ~LibraryItem(){}
};

class Book : public LibraryItem
{
    string ISBN;
    string genre;
    int copiesAvailable;

public:
    Book(int id=0,string t="",string a="",int year=0,
         string isbn="",string g="",int copies=0)
         : LibraryItem(id,t,a,year)
    {
        ISBN = isbn;
        genre = g;
        copiesAvailable = copies;
    }
    void getdata()
    {
    	LibraryItem::getdata();
    	cin>>ISBN>>genre>>copiesAvailable;
	}
    void checkout()
    {
        if(copiesAvailable > 0)
        {
            copiesAvailable--;
            cout << "Book Issued Successfully.";
        }
        else
        {
            cout << "No Copies Available.";
        }
    }
    void display()
    {
        LibraryItem::display();

        cout << "ISBN: " << ISBN;
        cout << "Genre: " << genre;
        cout << "Copies Available: "
             << copiesAvailable << endl;
    }

};
class Journal : public LibraryItem
{
    string ISSN;
    int volume;
    int issueNumber;
public:
    Journal(int id=0,string t="",string a="",int year=0,
            string issn="",int vol=0,int issue=0)
            : LibraryItem(id,t,a,year)
    {
        ISSN = issn;
        volume = vol;
        issueNumber = issue;
    }
    void getdata()
    {
    	LibraryItem::getdata();
    	cin>>ISSN>>volume>>issueNumber;
	}
    void checkout()
    {
        cout << "Journal Checked Out.";
    }
    void display()
    {
        LibraryItem::display();

        cout << "ISSN: " << ISSN;
        cout << "Volume: " << volume;
        cout << "Issue Number: "
             << issueNumber << endl;
    }

};

struct IssueRecord
{
    string rollNo;
    int itemID;
};

class Library
{
    LibraryItem* catalog[100];
    int count;

    IssueRecord records[100];
    int issueCount;

public:
    Library()
    {
        count = 0;
        issueCount = 0;
    }

    void addItem(LibraryItem* item)
    {
        catalog[count++] = item;
    }

    void displayCatalog()
    {
        for(int i=0;i<count;i++)
        {
            catalog[i]->display();
            cout << endl;
        }
    }

    void searchByTitle(string t)
    {
      bool found=false;

        for(int i=0;i<count;i++)
        {
            if(catalog[i]->getTitle() == t)
            {
                catalog[i]->display();
                found = true;
            }
        }
        if(!found)
        {
            cout << "Item Not Found.";
        }
    }
    void issueItem(string rollNo,int itemID)
    {
        records[issueCount].rollNo = rollNo;
        records[issueCount].itemID = itemID;

        issueCount++;

        cout << "Item Issued.";
    }
    void returnItem(int lateDays)
    {
        if(lateDays > 0)
        {
            throw OverdueException(lateDays * 50);
        }

        cout << "Returned Successfully.";
    }
};

int main()
{
    Library lib;

    LibraryItem* ptr;
int opt;
cin>>opt;
switch(opt)
{
    case 1:
    {
    ptr = new Book();
ptr->getdata();
    lib.addItem(ptr);
    }
    break;
    case 2:
    {
    ptr = new Journal();
    ptr->getdata();
    lib.addItem(ptr);
    }
    break;
    default:
    {
        cout<<"not varified"<<endl;
    }
}
    cout << "Catalog:";
    lib.displayCatalog();

    cout << "Searching OOP:";
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
    return 0;
}
  