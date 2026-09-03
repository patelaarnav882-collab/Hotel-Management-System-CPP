#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include <memory>

#include "Admin.h"
#include "Room.h"
#include "Customer.h"
#include "Billing.h"
#include "Validator.h"
#include "FileManager.h"

class Hotel
{
private:
    std::string hotelName;

    std::vector<Room> rooms;
    std::vector<std::unique_ptr<Customer>> customers;

    FileManager fileManager;
    Billing billing;

    int bookingCounter;

public:

    //==================================
    // Constructors
    //==================================

    Hotel();

    explicit Hotel(const std::string& hotelName);

    //==================================
    // Hotel Information
    //==================================

    void displayHotelInfo() const;

    std::string getHotelName() const;

    void setHotelName(const std::string& hotelName);

    //==================================
    // Room Management
    //==================================

    void initializeRooms();

    void addRoom(
        int roomNumber,
        int floor,
        RoomType roomType,
        double price
    );

    bool isRoomAvailable(
        int roomNumber
    ) const;

    Room* findRoom(
        int roomNumber
    );

    void showAllRooms() const;

    void showAvailableRooms() const;

    //==================================
    // Customer Management
    //==================================

    void bookRoom();

    void cancelBooking();

    void showAllCustomers() const;

    Customer* findCustomerByBookingID(
        const std::string& bookingID
    );

    Customer* findCustomerByName(
        const std::string& name
    );

    Customer* findCustomerByPhone(
        const std::string& phone
    );

    void searchCustomerByBookingID() const;

    void searchCustomerByName() const;

    void searchCustomerByPhone() const;

    //==================================
    // Billing
    //==================================

    void generateBill(
        const std::string& bookingID
    );

    void printReceipt(
        const std::string& bookingID
    );

    //==================================
    // Statistics
    //==================================

    int getTotalRooms() const;

    int getAvailableRooms() const;

    int getOccupiedRooms() const;

    int getTotalCustomers() const;

    double getTotalRevenue() const;

    void showStatistics() const;

    //==================================
    // File Operations
    //==================================

    bool saveData();

    bool loadData();

    //==================================
    // Utility Functions
    //==================================

    std::string generateBookingID();

    void clearAllData();

    //==================================
    // Destructor
    //==================================

    ~Hotel();
};

#endif