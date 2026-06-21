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
    {    cout<<"enter item id: ";
    	cin>>itemID;
		cout<<"enter title: ";
		cin>>title;
		cout<<"enter author: ";
		cin>>author;
		cout<<"enter publication year: ";
		cin>>publicationYear;
	}
    virtual void display()
    {
        cout << "\nItem ID: " << itemID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nPublication Year: " << publicationYear;
}

    virtual void save(ofstream &out) = 0;

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
    	cout<<"enter ISBN: ";
    	cin>>ISBN;
		cout<<"enter genre: ";
		cin>>genre;
		cout<<"enter available copies: ";
		cin>>copiesAvailable;
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
    void save(ofstream &out)
    {
        out << "Book "
            << itemID << " "
            << title << " "
            << author << " "
            << publicationYear << " "
            << ISBN << " "
            << genre << " "
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
    	cout<<"enter ISSN: ";
    	cin>>ISSN;
		cout<<"enter volume: ";
		cin>>volume;
		cout<<"enter issue number: ";
		cin>>issueNumber;
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
    void save(ofstream &out)
    {
        out << "Journal "
            << itemID << " "
            << title << " "
            << author << " "
            << publicationYear << " "
            << ISSN << " "
            << volume << " "
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
    void saveToFile()
    {
        ofstream out("library.txt");

        for(int i=0;i<count;i++)
        {
            catalog[i]->save(out);
        }

        out.close();

        cout << "Catalog Saved.";
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

