#include "../include/Hotel.h"

#include <iostream>
#include <iomanip>

//==================================
// Default Constructor
//==================================

Hotel::Hotel()
    : hotelName("Grand Palace Hotel"),
      fileManager("hotel_data.txt"),
      bookingCounter(1000)
{
    initializeRooms();
}

//==================================
// Parameterized Constructor
//==================================

Hotel::Hotel(const std::string& hotelName)
    : hotelName(hotelName),
      fileManager("hotel_data.txt"),
      bookingCounter(1000)
{
    initializeRooms();
}

//==================================
// Display Hotel Information
//==================================

void Hotel::displayHotelInfo() const
{
    std::cout << "\n=====================================\n";
    std::cout << "        " << hotelName << '\n';
    std::cout << "=====================================\n";
    std::cout << "Total Rooms      : " << getTotalRooms() << '\n';
    std::cout << "Available Rooms  : " << getAvailableRooms() << '\n';
    std::cout << "Occupied Rooms   : " << getOccupiedRooms() << '\n';
    std::cout << "Total Customers  : " << getTotalCustomers() << '\n';
    std::cout << "=====================================\n";
}

//==================================
// Getter
//==================================

std::string Hotel::getHotelName() const
{
    return hotelName;
}

//==================================
// Setter
//==================================

void Hotel::setHotelName(const std::string& hotelName)
{
    this->hotelName = hotelName;
}

//==================================
// Initialize Rooms
//==================================

void Hotel::initializeRooms()
{
    rooms.clear();

    // Floor 1 (Rooms 101-105)
    addRoom(101, 1, RoomType::NON_AC, 1000);
    addRoom(102, 1, RoomType::NON_AC, 1000);
    addRoom(103, 1, RoomType::NON_AC, 1000);
    addRoom(104, 1, RoomType::NON_AC, 1000);
    addRoom(105, 1, RoomType::NON_AC, 1000);

    // Floor 2 (Rooms 201-205)
    addRoom(201, 2, RoomType::AC, 2000);
    addRoom(202, 2, RoomType::AC, 2000);
    addRoom(203, 2, RoomType::AC, 2000);
    addRoom(204, 2, RoomType::AC, 2000);
    addRoom(205, 2, RoomType::AC, 2000);

    // Floor 3 (Rooms 301-305)
    addRoom(301, 3, RoomType::AC, 2500);
    addRoom(302, 3, RoomType::AC, 2500);
    addRoom(303, 3, RoomType::AC, 2500);
    addRoom(304, 3, RoomType::AC, 2500);
    addRoom(305, 3, RoomType::AC, 2500);

    // Floor 4 (Rooms 401-405)
    addRoom(401, 4, RoomType::AC, 3000);
    addRoom(402, 4, RoomType::AC, 3000);
    addRoom(403, 4, RoomType::AC, 3000);
    addRoom(404, 4, RoomType::AC, 3000);
    addRoom(405, 4, RoomType::AC, 3000);
}

//==================================
// Add Room
//==================================

void Hotel::addRoom(
    int roomNumber,
    int floor,
    RoomType roomType,
    double price
)
{
    rooms.emplace_back(
        roomNumber,
        floor,
        roomType,
        price
    );
}
//==================================
// Find Room
//==================================

Room* Hotel::findRoom(int roomNumber)
{
    for (auto& room : rooms)
    {
        if (room.getRoomNumber() == roomNumber)
        {
            return &room;
        }
    }

    return nullptr;
}

//==================================
// Check Room Availability
//==================================

bool Hotel::isRoomAvailable(int roomNumber) const
{
    for (const auto& room : rooms)
    {
        if (room.getRoomNumber() == roomNumber)
        {
            return room.isAvailable();
        }
    }

    return false;
}

//==================================
// Show All Rooms
//==================================

void Hotel::showAllRooms() const
{
    if (rooms.empty())
    {
        std::cout << "\nNo rooms available.\n";
        return;
    }

    std::cout << "\n========================================\n";
    std::cout << "            ALL ROOMS\n";
    std::cout << "========================================\n";

    for (const auto& room : rooms)
    {
        room.display();
        std::cout << "----------------------------------------\n";
    }
}

//==================================
// Show Available Rooms
//==================================

void Hotel::showAvailableRooms() const
{
    bool found = false;

    std::cout << "\n========================================\n";
    std::cout << "         AVAILABLE ROOMS\n";
    std::cout << "========================================\n";

    for (const auto& room : rooms)
    {
        if (room.isAvailable())
        {
            room.display();
            std::cout << "----------------------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No rooms are available.\n";
    }
}
//==================================
// Generate Booking ID
//==================================

std::string Hotel::generateBookingID()
{
    bookingCounter++;

    return "BK" + std::to_string(bookingCounter);
}

//==================================
// Book Room (Part A)
//==================================

void Hotel::bookRoom()
{
    std::string name;
    std::string gender;
    std::string phone;
    std::string email;
    std::string address;
    std::string idProof;
    std::string checkInDate;
    std::string checkOutDate;

    int age;
    int roomNumber;
    int totalDays;

    std::cout << "\n========== ROOM BOOKING ==========\n";

    //==============================
    // Customer Details
    //==============================

    std::cout << "Enter Name : ";
    std::getline(std::cin >> std::ws, name);

    if (!Validator::isValidName(name))
    {
        std::cout << "Invalid Name!\n";
        return;
    }

    std::cout << "Enter Age : ";
    std::cin >> age;

    if (!Validator::isValidAge(age))
    {
        std::cout << "Invalid Age!\n";
        return;
    }

    std::cout << "Enter Gender : ";
    std::cin >> gender;

    if (!Validator::isValidGender(gender))
    {
        std::cout << "Invalid Gender!\n";
        return;
    }

    std::cout << "Enter Phone : ";
    std::cin >> phone;

    if (!Validator::isValidPhone(phone))
    {
        std::cout << "Invalid Phone Number!\n";
        return;
    }

    std::cout << "Enter Email : ";
    std::cin >> email;

    if (!Validator::isValidEmail(email))
    {
        std::cout << "Invalid Email!\n";
        return;
    }

    std::cout << "Enter Address : ";
    std::getline(std::cin >> std::ws, address);

    if (!Validator::isNonEmpty(address))
    {
        std::cout << "Invalid Address!\n";
        return;
    }

    std::cout << "Enter ID Proof : ";
    std::getline(std::cin >> std::ws, idProof);

    if (!Validator::isValidIDProof(idProof))
    {
        std::cout << "Invalid ID Proof!\n";
        return;
    }

    //==============================
    // Room Details
    //==============================

    showAvailableRooms();

    std::cout << "\nEnter Room Number : ";
    std::cin >> roomNumber;

    Room* room = findRoom(roomNumber);

    if (room == nullptr)
    {
        std::cout << "Room does not exist!\n";
        return;
    }

    if (!room->isAvailable())
    {
        std::cout << "Room is already occupied!\n";
        return;
    }

    //==============================
    // Booking Details
    //==============================

    std::cout << "Enter Check-In Date (DD/MM/YYYY) : ";
    std::cin >> checkInDate;

    if (!Validator::isValidDate(checkInDate))
    {
        std::cout << "Invalid Check-In Date!\n";
        return;
    }

    std::cout << "Enter Check-Out Date (DD/MM/YYYY) : ";
    std::cin >> checkOutDate;

    if (!Validator::isValidDate(checkOutDate))
    {
        std::cout << "Invalid Check-Out Date!\n";
        return;
    }

    std::cout << "Enter Total Days : ";
    std::cin >> totalDays;

    if (!Validator::isValidDays(totalDays))
    {
        std::cout << "Invalid Number of Days!\n";
        return;
    }

    //==============================
    // Generate Booking ID
    //==============================

    std::string bookingID = generateBookingID();

    //==============================
    // Create Customer
    //==============================

    auto customer = std::make_unique<Customer>(
        name,
        age,
        gender,
        phone,
        email,
        address,
        bookingID,
        idProof,
        roomNumber,
        checkInDate,
        checkOutDate,
        totalDays,
        room->getRoomType()
    );

    //==============================
    // Calculate Bill
    //==============================

    customer->calculateBill();

    // Optional discount example
    // customer->getBilling().applyDiscount(10);
    // customer->getBilling().calculateTotalBill();

    //==============================
    // Book Room
    //==============================

    room->bookRoom();

    //==============================
    // Store Customer
    //==============================

    customers.push_back(std::move(customer));

    //==============================
    // Success Message
    //==============================

    std::cout << "\n=====================================\n";
    std::cout << "     BOOKING SUCCESSFUL\n";
    std::cout << "=====================================\n";
    std::cout << "Booking ID : " << bookingID << '\n';
    std::cout << "Room Number: " << roomNumber << '\n';
    std::cout << "=====================================\n";

    //==============================
    // Display Bill
    //==============================

    customers.back()->getBilling().displayBill();

    std::cout << "\nThank you for choosing "
              << hotelName
              << "!\n";
}
//==================================
// Find Customer By Booking ID
//==================================

Customer* Hotel::findCustomerByBookingID(
    const std::string& bookingID
)
{
    for (auto& customer : customers)
    {
        if (customer->getBookingID() == bookingID)
        {
            return customer.get();
        }
    }

    return nullptr;
}

//==================================
// Find Customer By Name
//==================================

Customer* Hotel::findCustomerByName(
    const std::string& name
)
{
    for (auto& customer : customers)
    {
        if (customer->getName() == name)
        {
            return customer.get();
        }
    }

    return nullptr;
}

//==================================
// Find Customer By Phone
//==================================

Customer* Hotel::findCustomerByPhone(
    const std::string& phone
)
{
    for (auto& customer : customers)
    {
        if (customer->getPhone() == phone)
        {
            return customer.get();
        }
    }

    return nullptr;
}
//==================================
// Search Customer By Booking ID
//==================================

void Hotel::searchCustomerByBookingID() const
{
    std::string bookingID;

    std::cout << "\nEnter Booking ID : ";
    std::cin >> bookingID;

    for (const auto& customer : customers)
    {
        if (customer->getBookingID() == bookingID)
        {
            customer->display();
            return;
        }
    }

    std::cout << "Customer not found.\n";
}

//==================================
// Search Customer By Name
//==================================

void Hotel::searchCustomerByName() const
{
    std::string name;

    std::cout << "\nEnter Customer Name : ";
    std::getline(std::cin >> std::ws, name);

    bool found = false;

    for (const auto& customer : customers)
    {
        if (customer->getName() == name)
        {
            customer->display();
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Customer not found.\n";
    }
}

//==================================
// Search Customer By Phone
//==================================

void Hotel::searchCustomerByPhone() const
{
    std::string phone;

    std::cout << "\nEnter Phone Number : ";
    std::cin >> phone;

    for (const auto& customer : customers)
    {
        if (customer->getPhone() == phone)
        {
            customer->display();
            return;
        }
    }

    std::cout << "Customer not found.\n";
}

//==================================
// Cancel Booking
//==================================

void Hotel::cancelBooking()
{
    std::string bookingID;

    std::cout << "\nEnter Booking ID : ";
    std::cin >> bookingID;

    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if ((*it)->getBookingID() == bookingID)
        {
            Room* room = findRoom((*it)->getRoomNumber());

            if (room != nullptr)
            {
                room->vacateRoom();
            }
            char choice;

            std::cout << "Are you sure you want to cancel? (Y/N): ";
            std::cin >> choice;

            if(choice != 'Y' && choice != 'y')
            {
                std::cout << "Cancellation aborted.\n";
                return;
            }

            customers.erase(it);

            std::cout << "\n=====================================\n";
            std::cout << " Booking Cancelled Successfully\n";
            std::cout << "=====================================\n";

            return;
        }
    }

    std::cout << "Booking ID not found.\n";
}
//==================================
// Generate Bill
//==================================

void Hotel::generateBill(
    const std::string& bookingID
)
{
    Customer* customer =
        findCustomerByBookingID(bookingID);

    if (customer == nullptr)
    {
        std::cout << "Booking ID not found.\n";
        return;
    }

    customer->calculateBill();

    std::cout << "\n==================================\n";
    std::cout << "         CUSTOMER BILL\n";
    std::cout << "==================================\n";

    customer->display();
}

//==================================
// Print Receipt
//==================================

void Hotel::printReceipt(
    const std::string& bookingID
)
{
    Customer* customer =
        findCustomerByBookingID(bookingID);

    if (customer == nullptr)
    {
        std::cout << "Booking ID not found.\n";
        return;
    }

    std::string roomType;

    if (customer->getRoomType() == RoomType::AC)
        roomType = "AC";
    else
        roomType = "NON_AC";

    customer->getBilling().printReceipt(
        customer->getBookingID(),
        customer->getName(),
        customer->getRoomNumber(),
        roomType,
        customer->getTotalDays()
    );
}
//==================================
// Get Total Rooms
//==================================

int Hotel::getTotalRooms() const
{
    return static_cast<int>(rooms.size());
}

//==================================
// Get Available Rooms
//==================================

int Hotel::getAvailableRooms() const
{
    int count = 0;

    for (const auto& room : rooms)
    {
        if (room.isAvailable())
        {
            count++;
        }
    }

    return count;
}

//==================================
// Get Occupied Rooms
//==================================

int Hotel::getOccupiedRooms() const
{
    return getTotalRooms() - getAvailableRooms();
}

//==================================
// Get Total Customers
//==================================

int Hotel::getTotalCustomers() const
{
    return static_cast<int>(customers.size());
}

//==================================
// Get Total Revenue
//==================================

double Hotel::getTotalRevenue() const
{
    double revenue = 0.0;

    for (const auto& customer : customers)
    {
        revenue += customer->getBilling().getTotalBill();
    }

    return revenue;
}

//==================================
// Show Statistics
//==================================

void Hotel::showStatistics() const
{
    std::cout << "\n=========================================\n";
    std::cout << "          HOTEL STATISTICS\n";
    std::cout << "=========================================\n";

    std::cout << "Hotel Name          : "
              << hotelName << '\n';

    std::cout << "Total Rooms         : "
              << getTotalRooms() << '\n';

    std::cout << "Available Rooms     : "
              << getAvailableRooms() << '\n';

    std::cout << "Occupied Rooms      : "
              << getOccupiedRooms() << '\n';

    std::cout << "Total Customers     : "
              << getTotalCustomers() << '\n';

    std::cout << "Occupancy Rate      : ";

    if (getTotalRooms() == 0)
    {
        std::cout << "0.00 %\n";
    }
    else
    {
        double occupancy =
            (static_cast<double>(getOccupiedRooms()) /
             getTotalRooms()) * 100.0;

        std::cout << std::fixed
                  << std::setprecision(2)
                  << occupancy
                  << " %\n";
    }

    std::cout << "Total Revenue       : Rs. "
              << std::fixed
              << std::setprecision(2)
              << getTotalRevenue()
              << '\n';

    std::cout << "=========================================\n";
}
//==================================
// Save Data
//==================================

bool Hotel::saveData()
{
    bool success = fileManager.saveCustomers(customers);

    if (success)
    {
        std::cout << "\nData saved successfully.\n";
    }
    else
    {
        std::cout << "\nFailed to save data.\n";
    }

    return success;
}

//==================================
// Load Data
//==================================

bool Hotel::loadData()
{
    if (!fileManager.fileExists())
    {
        std::cout << "\nNo saved data found.\n";
        return false;
    }

    customers = fileManager.loadCustomers();

    // Reset all rooms to AVAILABLE
    for (auto& room : rooms)
    {
        room.vacateRoom();
    }

    // Mark booked rooms as OCCUPIED
    for (const auto& customer : customers)
    {
        Room* room = findRoom(
            customer->getRoomNumber()
        );

        if (room != nullptr)
        {
            room->bookRoom();
        }
    }

    // Update booking counter
    bookingCounter = 1000;

    for (const auto& customer : customers)
    {
        std::string id = customer->getBookingID();

        if (id.size() > 2)
        {
            try
            {
                int number = std::stoi(id.substr(2));

                if (number > bookingCounter)
                {
                    bookingCounter = number;
                }
            }
            catch (...)
            {
                // Ignore invalid booking IDs
            }
        }
    }

    std::cout << "\nData loaded successfully.\n";

    return true;
}

//==================================
// Clear All Data
//==================================

void Hotel::clearAllData()
{
    customers.clear();

    for (auto& room : rooms)
    {
        room.vacateRoom();
    }

    bookingCounter = 1000;

    if (fileManager.clearFile())
    {
        std::cout << "\nAll hotel data has been cleared.\n";
    }
    else
    {
        std::cout << "\nFailed to clear hotel data file.\n";
    }
}
//==================================
// Destructor
//==================================

Hotel::~Hotel()
{
    try
    {
        // Automatically save data before exiting
        saveData();
    }
    catch (...)
    {
        std::cout << "Warning: Unable to save hotel data during shutdown.\n";
    }

    // std::vector and std::unique_ptr automatically
    // release all allocated memory.
}
