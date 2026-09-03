#include "../include/FileManager.h"

#include <fstream>
#include <iostream>

//==================================
// Default Constructor
//==================================

FileManager::FileManager()
{
    fileName = "hotel_data.txt";
}

//==================================
// Parameterized Constructor
//==================================

FileManager::FileManager(const std::string& fileName)
{
    this->fileName = fileName;
}

//==================================
// Save Customers
//==================================

bool FileManager::saveCustomers(
    const std::vector<std::unique_ptr<Customer>>& customers
) const
{
    std::ofstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file for writing.\n";
        return false;
    }

    for (const auto& customer : customers)
    {
        file
            << customer->getBookingID() << '|'
            << customer->getName() << '|'
            << customer->getAge() << '|'
            << customer->getGender() << '|'
            << customer->getPhone() << '|'
            << customer->getEmail() << '|'
            << customer->getAddress() << '|'
            << customer->getIDProof() << '|'
            << customer->getRoomNumber() << '|';

        if (customer->getRoomType() == RoomType::AC)
            file << "AC";
        else
            file << "NON_AC";

        file << '|'
             << customer->getCheckInDate() << '|'
             << customer->getCheckOutDate() << '|'
             << customer->getTotalDays()
             << '\n';
    }

    file.close();

    return true;
}
#include <sstream>

//==================================
// Load Customers
//==================================

std::vector<std::unique_ptr<Customer>>
FileManager::loadCustomers() const
{
    std::vector<std::unique_ptr<Customer>> customers;

    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "Error: Unable to open file for reading.\n";
        return customers;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);

        std::string bookingID;
        std::string name;
        std::string ageString;
        std::string gender;
        std::string phone;
        std::string email;
        std::string address;
        std::string idProof;
        std::string roomNumberString;
        std::string roomTypeString;
        std::string checkInDate;
        std::string checkOutDate;
        std::string totalDaysString;

        std::getline(ss, bookingID, '|');
        std::getline(ss, name, '|');
        std::getline(ss, ageString, '|');
        std::getline(ss, gender, '|');
        std::getline(ss, phone, '|');
        std::getline(ss, email, '|');
        std::getline(ss, address, '|');
        std::getline(ss, idProof, '|');
        std::getline(ss, roomNumberString, '|');
        std::getline(ss, roomTypeString, '|');
        std::getline(ss, checkInDate, '|');
        std::getline(ss, checkOutDate, '|');
        std::getline(ss, totalDaysString);

        int age = std::stoi(ageString);
        int roomNumber = std::stoi(roomNumberString);
        int totalDays = std::stoi(totalDaysString);

        RoomType roomType =
            (roomTypeString == "AC")
                ? RoomType::AC
                : RoomType::NON_AC;

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
            roomType
        );

        customer->calculateBill();

        customers.push_back(std::move(customer));
    }

    file.close();

    return customers;
}

//==================================
// Clear File
//==================================

bool FileManager::clearFile() const
{
    std::ofstream file(fileName, std::ios::trunc);

    if (!file.is_open())
    {
        std::cout << "Error: Unable to clear file.\n";
        return false;
    }

    file.close();

    return true;
}
//==================================
// Check File Exists
//==================================

bool FileManager::fileExists() const
{
    std::ifstream file(fileName);
    return file.good();
}

//==================================
// Get File Size
//==================================

long long FileManager::getFileSize() const
{
    std::ifstream file(fileName, std::ios::binary | std::ios::ate);

    if (!file.is_open())
        return 0;

    return static_cast<long long>(file.tellg());
}

//==================================
// Getter
//==================================

std::string FileManager::getFileName() const
{
    return fileName;
}

//==================================
// Setter
//==================================

void FileManager::setFileName(
    const std::string& fileName
)
{
    this->fileName = fileName;
}

//==================================
// Destructor
//==================================

FileManager::~FileManager()
{
}