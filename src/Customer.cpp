#include "../include/Customer.h"

#include <iostream>

//==================================
// Default Constructor
//==================================

Customer::Customer()
    : User()
{
    bookingID = "";
    idProof = "";
    roomNumber = 0;
    roomType = RoomType{};
    checkInDate = "";
    checkOutDate = "";
    totalDays = 0;
}

//==================================
// Parameterized Constructor
//==================================

Customer::Customer(
    std::string name,
    int age,
    std::string gender,
    std::string phone,
    std::string email,
    std::string address,
    std::string bookingID,
    std::string idProof,
    int roomNumber,
    std::string checkInDate,
    std::string checkOutDate,
    int totalDays,
    RoomType roomType
)
: User(
    name,
    age,
    gender,
    phone,
    email,
    address
)
{
    this->bookingID = bookingID;
    this->idProof = idProof;
    this->roomNumber = roomNumber;
    this->checkInDate = checkInDate;
    this->checkOutDate = checkOutDate;
    this->totalDays = totalDays;
    this->roomType = roomType;
}
//==================================
// Bill Calculation
//==================================

void Customer::calculateBill()
{
    double pricePerDay = 0.0;

    if (roomType == RoomType::AC)
        pricePerDay = 2000.0;
    else
        pricePerDay = 1000.0;

    billing.calculateRoomCharge(
        pricePerDay,
        totalDays
    );

    billing.calculateGST();

    billing.calculateTotalBill();
}

//==================================
// Getters
//==================================

std::string Customer::getBookingID() const
{
    return bookingID;
}

std::string Customer::getIDProof() const
{
    return idProof;
}

int Customer::getRoomNumber() const
{
    return roomNumber;
}

RoomType Customer::getRoomType() const
{
    return roomType;
}

std::string Customer::getCheckInDate() const
{
    return checkInDate;
}

std::string Customer::getCheckOutDate() const
{
    return checkOutDate;
}

int Customer::getTotalDays() const
{
    return totalDays;
}

Billing& Customer::getBilling()
{
    return billing;
}

const Billing& Customer::getBilling() const
{
    return billing;
}

//==================================
// Setters
//==================================

void Customer::setBookingID(std::string bookingID)
{
    this->bookingID = bookingID;
}

void Customer::setIDProof(std::string idProof)
{
    this->idProof = idProof;
}

void Customer::setRoomNumber(int roomNumber)
{
    this->roomNumber = roomNumber;
}

void Customer::setRoomType(RoomType roomType)
{
    this->roomType = roomType;
}

void Customer::setCheckInDate(std::string checkInDate)
{
    this->checkInDate = checkInDate;
}

void Customer::setCheckOutDate(std::string checkOutDate)
{
    this->checkOutDate = checkOutDate;
}

void Customer::setTotalDays(int totalDays)
{
    this->totalDays = totalDays;
}

//==================================
// Display
//==================================

void Customer::display() const
{
    std::cout << "\n=========================================\n";
    std::cout << "          CUSTOMER DETAILS\n";
    std::cout << "=========================================\n";

    std::cout << "Booking ID   : "
              << bookingID << '\n';

    std::cout << "Name         : "
              << name << '\n';

    std::cout << "Age          : "
              << age << '\n';

    std::cout << "Gender       : "
              << gender << '\n';

    std::cout << "Phone        : "
              << phone << '\n';

    std::cout << "Email        : "
              << email << '\n';

    std::cout << "Address      : "
              << address << '\n';

    std::cout << "ID Proof     : "
              << idProof << '\n';

    std::cout << "Room Number  : "
              << roomNumber << '\n';

    std::cout << "Room Type    : "
              << (roomType == RoomType::AC ? "AC" : "Non-AC") << '\n';

    std::cout << "Check In     : "
              << checkInDate << '\n';

    std::cout << "Check Out    : "
              << checkOutDate << '\n';

    std::cout << "Total Days   : "
              << totalDays << '\n';

    std::cout << "\n----------- BILL -----------\n";

    billing.displayBill();
}

//==================================
// Destructor
//==================================

Customer::~Customer()
{
}