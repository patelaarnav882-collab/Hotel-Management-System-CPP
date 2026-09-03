#ifndef BILLING_H
#define BILLING_H

#include <string>

class Billing
{
private:
    double roomCharge;
    double gstPercentage;
    double gstAmount;
    double discountPercentage;
    double discountAmount;
    double totalBill;

public:

    //==============================
    // Constructors
    //==============================

    Billing();

    //==============================
    // Bill Calculation
    //==============================

    double calculateRoomCharge(
        double pricePerDay,
        int totalDays
    );

    double calculateGST();

    double applyDiscount(double discountPercentage);

    double calculateTotalBill();

    //==============================
    // Display
    //==============================

    void displayBill() const;

    void printReceipt(
        const std::string& bookingID,
        const std::string& customerName,
        int roomNumber,
        const std::string& roomType,
        int totalDays
    ) const;

    //==============================
    // Getters
    //==============================

    double getRoomCharge() const;

    double getGSTAmount() const;

    double getDiscountAmount() const;

    double getTotalBill() const;

    double getGSTPercentage() const;

    double getDiscountPercentage() const;

    //==============================
    // Setters
    //==============================

    void setRoomCharge(double roomCharge);

    void setGSTPercentage(double gstPercentage);

    void setDiscountPercentage(double discountPercentage);

    //==============================
    // Utility
    //==============================

    void reset();

    //==============================
    // Destructor
    //==============================

    ~Billing();
};

#endif