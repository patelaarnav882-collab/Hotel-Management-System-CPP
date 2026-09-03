#include "../include/Room.h"

#include <iostream>

//==================================
// Default Constructor
//==================================

Room::Room()
{
    roomNumber = 0;
    floor = 0;
    roomType = RoomType::NON_AC;
    status = RoomStatus::AVAILABLE;
    pricePerDay = 0.0;
}

//==================================
// Parameterized Constructor
//==================================

Room::Room(int roomNumber,
           int floor,
           RoomType roomType,
           double pricePerDay)
{
    this->roomNumber = roomNumber;
    this->floor = floor;
    this->roomType = roomType;
    this->status = RoomStatus::AVAILABLE;
    this->pricePerDay = pricePerDay;
}

//==================================
// Getters
//==================================

int Room::getRoomNumber() const
{
    return roomNumber;
}

int Room::getFloor() const
{
    return floor;
}

RoomType Room::getRoomType() const
{
    return roomType;
}

RoomStatus Room::getStatus() const
{
    return status;
}

double Room::getPrice() const
{
    return pricePerDay;
}

//==================================
// Setters
//==================================

void Room::setRoomNumber(int roomNumber)
{
    this->roomNumber = roomNumber;
}

void Room::setFloor(int floor)
{
    this->floor = floor;
}

void Room::setRoomType(RoomType roomType)
{
    this->roomType = roomType;
}

void Room::setStatus(RoomStatus status)
{
    this->status = status;
}

void Room::setPrice(double price)
{
    this->pricePerDay = price;
}

//==================================
// Utility Functions
//==================================

bool Room::isAvailable() const
{
    return status == RoomStatus::AVAILABLE;
}

void Room::bookRoom()
{
    status = RoomStatus::OCCUPIED;
}

void Room::vacateRoom()
{
    status = RoomStatus::AVAILABLE;
}

std::string Room::getRoomTypeString() const
{
    if (roomType == RoomType::AC)
        return "AC";

    return "Non-AC";
}

std::string Room::getStatusString() const
{
    if (status == RoomStatus::AVAILABLE)
        return "Available";

    return "Occupied";
}

//==================================
// Display
//==================================

void Room::display() const
{
    std::cout << "\n==================================\n";
    std::cout << "          ROOM DETAILS\n";
    std::cout << "==================================\n";

    std::cout << "Room Number : " << roomNumber << '\n';
    std::cout << "Floor       : " << floor << '\n';
    std::cout << "Room Type   : " << getRoomTypeString() << '\n';
    std::cout << "Status      : " << getStatusString() << '\n';
    std::cout << "Price/Day   : Rs. " << pricePerDay << '\n';
}

//==================================
// Destructor
//==================================

Room::~Room()
{
}