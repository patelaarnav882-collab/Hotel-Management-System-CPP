#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// ========== TEMPLATE ==========
template <typename T>
void show(T msg) {
    cout << msg << endl;
}

// ========== BASE CLASS ==========
class User {
protected:
    string name;
public:
    User(string n = "") : name(n) {}
    virtual void display() {
        cout << "Name: " << name << endl;
    }
    virtual ~User() {}
};

// ========== DERIVED CLASS ==========
class Customer : public User {
    int roomNo, days;
    string type;
    float bill;

public:
    Customer(string n, int r, string t, int d) : User(n) {
        roomNo = r;
        type = t;
        days = d;
        calculate();
    }

    void calculate() {
        bill = (type == "AC") ? days * 2000 : days * 1000;
    }

    int getRoomNo() { return roomNo; }
    string getName() { return name; }

    void display() override {
        cout << "\n--- Booking ---\n";
        cout << "Name: " << name << endl;
        cout << "Room No: " << roomNo << endl;
        cout << "Type: " << type << endl;
        cout << "Days: " << days << endl;
        cout << "Bill: " << bill << endl;
    }

    string fileData() {
        return name + " " + to_string(roomNo) + " " + type + " " +
               to_string(days) + " " + to_string(bill);
    }
};

// ========== HOTEL ==========
class Hotel {
    vector<Customer*> list;
    int totalRooms = 20;  // TOTAL ROOMS

public:
    // CHECK SINGLE ROOM
    bool isAvailable(int room) {
        for (auto c : list) {
            if (c->getRoomNo() == room)
                return false;
        }
        return true;
    }

    void checkRoomAvailability() {
        int room;
        cout << "Enter Room No: ";
        cin >> room;

        if (room <= 0) {
            cout << "Invalid Room!\n";
            return;
        }

        if (isAvailable(room))
            cout << "Room " << room << " is AVAILABLE\n";
        else
            cout << "Room " << room << " is NOT AVAILABLE\n";
    }

    //SHOW ALL AVAILABLE ROOMS
    void showAvailableRooms() {
        cout << "\n--- Available Rooms ---\n";
        bool found = false;

        for (int i = 1; i <= totalRooms; i++) {
            if (isAvailable(i)) {
                cout << "Room " << i << " is Available\n";
                found = true;
            }
        }

        if (!found)
            cout << "No rooms available!\n";
    }

    // BOOK ROOM
    void bookRoom() {
        string name, type;
        int room, days;

        try {
            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Room No: ";
            cin >> room;

            if (room <= 0 || room > totalRooms)
                throw "Invalid Room Number!";

            if (!isAvailable(room))
                throw "Room already booked!";

            cout << "Type (AC/Non-AC): ";
            cin >> type;

            if (type != "AC" && type != "Non-AC")
                throw "Invalid Type!";

            cout << "Days: ";
            cin >> days;

            if (days <= 0)
                throw "Invalid Days!";

            list.push_back(new Customer(name, room, type, days));
            show("Booking Successful!");

        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }
    }

    // SEARCH CUSTOMER
    void searchCustomer() {
        string searchName;
        cout << "Enter name: ";
        cin >> searchName;

        bool found = false;

        for (auto c : list) {
            if (c->getName() == searchName) {
                c->display();
                found = true;
            }
        }

        if (!found)
            cout << "Customer not found!\n";
    }

    // ADMIN CANCEL
    void cancelBooking() {
        int room;
        cout << "Enter Room No: ";
        cin >> room;

        for (auto it = list.begin(); it != list.end(); ++it) {
            if ((*it)->getRoomNo() == room) {
                delete *it;
                list.erase(it);
                cout << "Booking Cancelled!\n";
                return;
            }
        }

        cout << "Booking not found!\n";
    }

    // CUSTOMER CANCEL
    void cancelByCustomer() {
        string name;
        int room;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Room No: ";
        cin >> room;

        for (auto it = list.begin(); it != list.end(); ++it) {
            if ((*it)->getName() == name && (*it)->getRoomNo() == room) {
                delete *it;
                list.erase(it);
                cout << "Your booking cancelled!\n";
                return;
            }
        }

        cout << "No matching booking found!\n";
    }

    // SHOW ALL BOOKINGS
    void showAll() {
        if (list.empty()) {
            cout << "No bookings!\n";
            return;
        }

        for (auto c : list)
            c->display();
    }

    // SAVE
    void save() {
        ofstream file("hotel.txt");

        for (auto c : list)
            file << c->fileData() << endl;

        file.close();
        show("Saved to file!");
    }

    // LOAD
    void load() {
        ifstream file("hotel.txt");

        if (!file) {
            cout << "File not found!\n";
            return;
        }

        string name, type;
        int room, days;
        float bill;

        while (file >> name >> room >> type >> days >> bill) {
            list.push_back(new Customer(name, room, type, days));
        }

        file.close();
        show("Data Loaded!");
    }

    ~Hotel() {
        for (auto c : list)
            delete c;
    }
};

// ========== LOGIN ==========
bool login() {
    string u, p;
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;
    return (u == "admin" && p == "1234");
}

// ========== ADMIN PANEL ==========
void adminPanel(Hotel &h) {
    if (!login()) {
        cout << "Access Denied!\n";
        return;
    }

    int ch;
    do {
        cout << "\n--- ADMIN PANEL ---\n";
        cout << "1. Show All\n";
        cout << "2. Search Customer\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Check Room Availability\n";
        cout << "5. Show Available Rooms\n";
        cout << "6. Save\n";
        cout << "7. Load\n";
        cout << "8. Back\n";
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
        case 1: h.showAll(); break;
        case 2: h.searchCustomer(); break;
        case 3: h.cancelBooking(); break;
        case 4: h.checkRoomAvailability(); break;
        case 5: h.showAvailableRooms(); break;
        case 6: h.save(); break;
        case 7: h.load(); break;
        case 8: break;
        default: cout << "Invalid!\n";
        }

    } while (ch != 8);
}

// ========== MAIN ==========
int main() {
    Hotel h;
    int choice;

    do {
        cout << "\n===== HOTEL SYSTEM =====\n";
        cout << "1. Admin Login\n";
        cout << "2. Book Room\n";
        cout << "3. Cancel Booking (Customer)\n";
        cout << "4. Check Room Availability\n";
        cout << "5. Show Available Rooms\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: adminPanel(h); break;
        case 2: h.bookRoom(); break;
        case 3: h.cancelByCustomer(); break;
        case 4: h.checkRoomAvailability(); break;
        case 5: h.showAvailableRooms(); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid!\n";
        }

    } while (choice != 6);

    return 0;
}