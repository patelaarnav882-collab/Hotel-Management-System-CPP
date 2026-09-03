#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <string>
#include "Billing.h"
#include "Room.h"

class Customer : public User
{
private:
    std::string bookingID;
    std::string idProof;

    int roomNumber;
    RoomType roomType;

    std::string checkInDate;
    std::string checkOutDate;

    int totalDays;

    Billing billing;

public:

    //==============================
    // Constructors
    //==============================

    Customer();

    Customer(
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
    );
    

    //==============================
    // Bill Calculation
    //==============================

    void calculateBill();

    //==============================
    // Getters
    //==============================

    std::string getBookingID() const;

    std::string getIDProof() const;

    int getRoomNumber() const;

    RoomType getRoomType() const;

    std::string getCheckInDate() const;

    std::string getCheckOutDate() const;

    int getTotalDays() const;

   Billing& getBilling();

const Billing& getBilling() const;

    //==============================
    // Setters
    //==============================

    void setBookingID(std::string bookingID);

    void setIDProof(std::string idProof);

    void setRoomNumber(int roomNumber);

     void setRoomType(RoomType roomType);

    void setCheckInDate(std::string checkInDate);

    void setCheckOutDate(std::string checkOutDate);

    void setTotalDays(int totalDays);

    //==============================
    // Display
    //==============================

    void display() const override;

    //==============================
    // Destructor
    //==============================

    ~Customer() override;
};

#endif