#include "../include/Billing.h"

#include <iostream>
#include <iomanip>

//==================================
// Default Constructor
//==================================

Billing::Billing()
{
    roomCharge = 0.0;
    gstPercentage = 18.0;
    gstAmount = 0.0;
    discountPercentage = 0.0;
    discountAmount = 0.0;
    totalBill = 0.0;
}

//==================================
// Calculate Room Charge
//==================================

double Billing::calculateRoomCharge(
    double pricePerDay,
    int totalDays
)
{
    roomCharge = pricePerDay * totalDays;
    return roomCharge;
}

//==================================
// Calculate GST
//==================================

double Billing::calculateGST()
{
    gstAmount = (roomCharge * gstPercentage) / 100.0;
    return gstAmount;
}

//==================================
// Apply Discount
//==================================

double Billing::applyDiscount(
    double discountPercentage
)
{
    this->discountPercentage = discountPercentage;

    discountAmount =
        (roomCharge * discountPercentage) / 100.0;

    return discountAmount;
}

//==================================
// Calculate Total Bill
//==================================

double Billing::calculateTotalBill()
{
    totalBill =
        roomCharge +
        gstAmount -
        discountAmount;

    return totalBill;
}

//==================================
// Display Bill
//==================================

void Billing::displayBill() const
{
    std::cout << "\n========================================\n";
    std::cout << "              BILL DETAILS\n";
    std::cout << "========================================\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Room Charge      : Rs. "
              << roomCharge << '\n';

    std::cout << "GST ("
              << gstPercentage
              << "%)         : Rs. "
              << gstAmount << '\n';

    std::cout << "Discount ("
              << discountPercentage
              << "%)    : Rs. "
              << discountAmount << '\n';

    std::cout << "----------------------------------------\n";

    std::cout << "TOTAL BILL       : Rs. "
              << totalBill << '\n';

    std::cout << "========================================\n";
}

//==================================
// Print Receipt
//==================================

void Billing::printReceipt(
    const std::string& bookingID,
    const std::string& customerName,
    int roomNumber,
    const std::string& roomType,
    int totalDays
) const
{
    std::cout << "\n========================================\n";
    std::cout << "          HOTEL RECEIPT\n";
    std::cout << "========================================\n";

    std::cout << "Booking ID   : "
              << bookingID << '\n';

    std::cout << "Customer     : "
              << customerName << '\n';

    std::cout << "Room Number  : "
              << roomNumber << '\n';

    std::cout << "Room Type    : "
              << roomType << '\n';

    std::cout << "Total Days   : "
              << totalDays << '\n';

    std::cout << "----------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Room Charge  : Rs. "
              << roomCharge << '\n';

    std::cout << "GST          : Rs. "
              << gstAmount << '\n';

    std::cout << "Discount     : Rs. "
              << discountAmount << '\n';

    std::cout << "----------------------------------------\n";

    std::cout << "TOTAL BILL   : Rs. "
              << totalBill << '\n';

    std::cout << "========================================\n";
}

//==================================
// Getters
//==================================

double Billing::getRoomCharge() const
{
    return roomCharge;
}

double Billing::getGSTAmount() const
{
    return gstAmount;
}

double Billing::getDiscountAmount() const
{
    return discountAmount;
}

double Billing::getTotalBill() const
{
    return totalBill;
}

double Billing::getGSTPercentage() const
{
    return gstPercentage;
}

double Billing::getDiscountPercentage() const
{
    return discountPercentage;
}

//==================================
// Setters
//==================================

void Billing::setRoomCharge(double roomCharge)
{
    this->roomCharge = roomCharge;
}

void Billing::setGSTPercentage(
    double gstPercentage
)
{
    this->gstPercentage = gstPercentage;
}

void Billing::setDiscountPercentage(
    double discountPercentage
)
{
    this->discountPercentage = discountPercentage;
}

//==================================
// Reset
//==================================

void Billing::reset()
{
    roomCharge = 0.0;
    gstAmount = 0.0;
    discountAmount = 0.0;
    totalBill = 0.0;
}

//==================================
// Destructor
//==================================

Billing::~Billing()
{
}