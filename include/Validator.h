#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator
{
public:

    //==============================
    // Customer Validation
    //==============================

    static bool isValidName(
        const std::string& name
    );

    static bool isValidAge(
        int age
    );

    static bool isValidGender(
        const std::string& gender
    );

    static bool isValidPhone(
        const std::string& phone
    );

    static bool isValidEmail(
        const std::string& email
    );

    static bool isValidIDProof(
        const std::string& idProof
    );

    //==============================
    // Room Validation
    //==============================

    static bool isValidRoomNumber(
        int roomNumber,
        int totalRooms
    );

    static bool isValidRoomType(
        const std::string& roomType
    );

    //==============================
    // Booking Validation
    //==============================

    static bool isValidDays(
        int totalDays
    );

    static bool isValidBookingID(
        const std::string& bookingID
    );

    static bool isValidDate(
        const std::string& date
    );

    //==============================
    // Utility Validation
    //==============================

    static bool isPositiveNumber(
        double value
    );

    static bool isNonEmpty(
        const std::string& text
    );
};

#endif