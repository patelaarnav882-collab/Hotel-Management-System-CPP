#include "../include/Validator.h"

#include <algorithm>
#include <cctype>

//==================================
// Name Validation
//==================================

bool Validator::isValidName(const std::string& name)
{
    if (name.empty())
        return false;

    for (char ch : name)
    {
        if (!std::isalpha(static_cast<unsigned char>(ch)) &&
            ch != ' ')
        {
            return false;
        }
    }

    return true;
}

//==================================
// Age Validation
//==================================

bool Validator::isValidAge(int age)
{
    return age >= 18 && age <= 100;
}

//==================================
// Gender Validation
//==================================

bool Validator::isValidGender(const std::string& gender)
{
    return (gender == "Male" ||
            gender == "Female" ||
            gender == "Other");
}

//==================================
// Phone Validation
//==================================

bool Validator::isValidPhone(const std::string& phone)
{
    if (phone.length() != 10)
        return false;

    return std::all_of(phone.begin(),
                       phone.end(),
                       [](char ch)
                       {
                           return std::isdigit(
                               static_cast<unsigned char>(ch));
                       });
}

//==================================
// Email Validation
//==================================

bool Validator::isValidEmail(const std::string& email)
{
    std::size_t atPos = email.find('@');

    if (atPos == std::string::npos)
        return false;

    std::size_t dotPos = email.find('.', atPos);

    if (dotPos == std::string::npos)
        return false;

    if (atPos == 0)
        return false;

    if (dotPos == atPos + 1)
        return false;

    if (dotPos == email.length() - 1)
        return false;

    return true;
}

//==================================
// ID Proof Validation
//==================================

bool Validator::isValidIDProof(const std::string& idProof)
{
    return !idProof.empty();
}

//==================================
// Room Number Validation
//==================================

bool Validator::isValidRoomNumber(int roomNumber,
                                  int totalRooms)
{
    return roomNumber >= 1 &&
           roomNumber <= totalRooms;
}

//==================================
// Room Type Validation
//==================================

bool Validator::isValidRoomType(const std::string& roomType)
{
    return roomType == "AC" ||
           roomType == "Non-AC";
}

//==================================
// Total Days Validation
//==================================

bool Validator::isValidDays(int totalDays)
{
    return totalDays > 0;
}

//==================================
// Booking ID Validation
//==================================

bool Validator::isValidBookingID(
    const std::string& bookingID)
{
    if (bookingID.length() < 6)
        return false;

    if (bookingID.substr(0, 2) != "BK")
        return false;

    return std::all_of(
        bookingID.begin() + 2,
        bookingID.end(),
        [](char ch)
        {
            return std::isdigit(
                static_cast<unsigned char>(ch));
        });
}

//==================================
// Date Validation
// Format : DD/MM/YYYY
//==================================

bool Validator::isValidDate(
    const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[2] != '/' ||
        date[5] != '/')
        return false;

    for (std::size_t i = 0; i < date.length(); i++)
    {
        if (i == 2 || i == 5)
            continue;

        if (!std::isdigit(
                static_cast<unsigned char>(date[i])))
        {
            return false;
        }
    }

    return true;
}

//==================================
// Positive Number Validation
//==================================

bool Validator::isPositiveNumber(double value)
{
    return value > 0.0;
}

//==================================
// Non Empty Validation
//==================================

bool Validator::isNonEmpty(
    const std::string& text)
{
    return !text.empty();
}