#include "../include/Admin.h"

#include <iostream>

//==================================
// Default Constructor
//==================================

Admin::Admin()
    : User()
{
    username = "admin";
    password = "1234";
}

//==================================
// Parameterized Constructor
//==================================

Admin::Admin(std::string name,
             int age,
             std::string gender,
             std::string phone,
             std::string email,
             std::string address,
             std::string username,
             std::string password)
    : User(name, age, gender, phone, email, address)
{
    this->username = username;
    this->password = password;
}

//==================================
// Login
//==================================

bool Admin::login()
{
    std::string user;
    std::string pass;

    std::cout << "\n==================================\n";
    std::cout << "          ADMIN LOGIN\n";
    std::cout << "==================================\n";

    std::cout << "Username : ";
    std::cin >> user;

    std::cout << "Password : ";
    std::cin >> pass;

    if (user == username && pass == password)
    {
        std::cout << "\nLogin Successful!\n";
        return true;
    }

    std::cout << "\nInvalid Username or Password!\n";
    return false;
}

//==================================
// Logout
//==================================

void Admin::logout()
{
    std::cout << "\nLogged out successfully.\n";
}

//==================================
// Change Password
//==================================

void Admin::changePassword()
{
    std::string oldPassword;
    std::string newPassword;

    std::cout << "\nCurrent Password : ";
    std::cin >> oldPassword;

    if (oldPassword != password)
    {
        std::cout << "Incorrect Password!\n";
        return;
    }

    std::cout << "New Password : ";
    std::cin >> newPassword;

    password = newPassword;

    std::cout << "Password changed successfully!\n";
}

//==================================
// Display
//==================================

void Admin::display() const
{
    std::cout << "\n==================================\n";
    std::cout << "         ADMIN DETAILS\n";
    std::cout << "==================================\n";

    std::cout << "Name      : " << name << '\n';
    std::cout << "Age       : " << age << '\n';
    std::cout << "Gender    : " << gender << '\n';
    std::cout << "Phone     : " << phone << '\n';
    std::cout << "Email     : " << email << '\n';
    std::cout << "Username  : " << username << '\n';
}

//==================================
// Getters
//==================================

std::string Admin::getUsername() const
{
    return username;
}

std::string Admin::getPassword() const
{
    return password;
}

//==================================
// Setters
//==================================

void Admin::setUsername(std::string username)
{
    this->username = username;
}

void Admin::setPassword(std::string password)
{
    this->password = password;
}

//==================================
// Destructor
//==================================

Admin::~Admin()
{
}