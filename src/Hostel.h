#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class hostelStudent 
{
private:
    string name;
    string rollNo;
public:
    hostelStudent() 
	{
        name = "";
        rollNo = "";
    }
    hostelStudent(string n, string r) 
	{
        name = n;
        rollNo = r;
    }
    string getName()
	 { return name;
	  
	  }
    string getRollNo() 
	{ return rollNo;
	
	 }
};



class Room {
private:
    int roomNumber;
    string type; 
    int floor;
    hostelStudent* occupants[3]; 
public:
    Room() {
        roomNumber = 0;
        type = "Single";
        floor = 0;
        occupants[0] = NULL;
        occupants[1] = NULL;
        occupants[2] = NULL;
    }
    Room(int num, string t, int f) {
        roomNumber = num;
        type = t;
        floor = f;
        occupants[0] = NULL;
        occupants[1] = NULL;
        occupants[2] = NULL;
    }
    
    int getRoomNumber()
	 { return roomNumber; 
	
	 }
    string getType() 
	{ return type; 
	
	}
    int getFloor()
	 { return floor; 
	 
	 }
    
    int getCapacity() 
	{
        if (type == "Single" || type == "single")
		 {
            return 1;
        }
        if (type == "Double" || type == "double")
		 {
            return 2;
        }
        return 3; 
    }
    
    
    
        bool addOccupant(hostelStudent* s) {
        int cap = getCapacity();
        for (int i = 0; i < cap; i++) {
            if (occupants[i] == NULL) {
                occupants[i] = s;
                return true;
            }
        }
        return false;
    }
    
    
    bool removeOccupant(string rollNo) {
        int cap = getCapacity();
        for (int i = 0; i < cap; i++) {
            if (occupants[i] != NULL && occupants[i]->getRollNo() == rollNo) {
                occupants[i] = NULL;
                return true;
            }
        }
        return false;
    }
  
  void displayRoom() 
	{
        cout << "Room: " << roomNumber << " | Type: " << type << " | Floor: " << floor << endl;
        cout << "Occupants:" << endl;
        bool empty = true;
        int cap = getCapacity();
        for (int i = 0; i < cap; i++)
		 {
            if (occupants[i] != NULL) 
			{
                cout << "  - " << occupants[i]->getName() << " (Roll: " << occupants[i]->getRollNo() << ")" << endl;
                empty = false;
            }
        }
        if (empty) 
		{
            cout << "  - Empty" << endl;
        }
    } 

};


class HostelBlock {
private:
    string blockName;
    Room rooms[5]; 
    int roomCount;
public:
    HostelBlock() {
        blockName = "Default Block";
        roomCount = 0;
    }
    HostelBlock(string name) {
        blockName = name;
        roomCount = 0;
    }
    
    string getBlockName() { return blockName; }
    int getRoomCount() { return roomCount; }
    
    void addRoom(Room r) {
        if (roomCount < 5) {
            rooms[roomCount] = r;
            roomCount++;
        } else {
            cout << "Block is full!" << endl;
        }
    }
    
    Room* getRoomAtIndex(int index) {
        if (index >= 0 && index < roomCount) {
            return &rooms[index];
        }
        return NULL;
    }
    
    void displayRooms() {
        cout << "\nBlock Name: " << blockName << endl;
        for (int i = 0; i < roomCount; i++) {
            rooms[i].displayRoom();
           
        }
    }
};


class HostelComponent {
protected:
    string hostelName;
public:
    HostelComponent(string hName) {
        hostelName = hName;
    }
    virtual ~HostelComponent() {}
};


class Accommodation : virtual public HostelComponent
 {
    public:
    Accommodation(string hName) : HostelComponent(hName) 
	{
	}
    virtual void allocateRoom(hostelStudent* s, int roomNum) = 0;
    virtual void vacateRoom(int roomNum) = 0;
};


class Reportable : virtual public HostelComponent 
{
    public:
    Reportable(string hName) : HostelComponent(hName) 
	{
	}
    virtual void generateReport()  = 0;
};


class HostelManager : public Accommodation, public Reportable {
private:
    HostelBlock block; 
public:
    HostelManager(string hName, string bName)
        : HostelComponent(hName), Accommodation(hName), Reportable(hName), block(bName) {}
        
    void addRoom(Room r) {
        block.addRoom(r);
    }
    
    void allocateRoom(hostelStudent* s, int roomNum) {
        int count = block.getRoomCount();
        for (int i = 0; i < count; i++) {
            Room* r = block.getRoomAtIndex(i);
            if (r != NULL && r->getRoomNumber() == roomNum) {
                if (r->addOccupant(s)) {
                    cout << "Student allocated successfully!" << endl;
                } else {
                    cout << "Room is full!" << endl;
                }
                return;
            }
        }
        cout << "Room not found!" << endl;
    }
    
    
    void vacateRoom(int roomNum) 
		{
        int count = block.getRoomCount();
        for (int i = 0; i < count; i++) 
		{
            Room* r = block.getRoomAtIndex(i);
            if (r != NULL && r->getRoomNumber() == roomNum) 
			{
                string roll;
                cout << "Enter Roll No to remove: ";
                cin >> roll;
                if (r->removeOccupant(roll)) 
				{
                    cout << "Student removed successfully!" << endl;
                } else 
				{
                    cout << "Student not found in room!" << endl;
                }
                return;
            }
        }
        cout << "Room not found!" << endl;
    }
    
        void generateReport() {
      
        cout << "HOSTEL REPORT: " << hostelName << endl;
        
        block.displayRooms();
    }
};


