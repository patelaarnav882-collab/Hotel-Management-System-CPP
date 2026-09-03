#include "../include/User.h"

#include <iostream>

//==================================
// Default Constructor
//==================================

User::User()
{
    name = "";
    age = 0;
    gender = "";
    phone = "";
    email = "";
    address = "";
}

//==================================
// Parameterized Constructor
//==================================

User::User(std::string name,
           int age,
           std::string gender,
           std::string phone,
           std::string email,
           std::string address)
{
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->phone = phone;
    this->email = email;
    this->address = address;
}

//==================================
// Setters
//==================================

void User::setName(std::string name)
{
    this->name = name;
}

void User::setAge(int age)
{
    this->age = age;
}

void User::setGender(std::string gender)
{
    this->gender = gender;
}

void User::setPhone(std::string phone)
{
    this->phone = phone;
}

void User::setEmail(std::string email)
{
    this->email = email;
}

void User::setAddress(std::string address)
{
    this->address = address;
}

//==================================
// Getters
//==================================

std::string User::getName() const
{
    return name;
}

int User::getAge() const
{
    return age;
}

std::string User::getGender() const
{
    return gender;
}

std::string User::getPhone() const
{
    return phone;
}

std::string User::getEmail() const
{
    return email;
}

std::string User::getAddress() const
{
    return address;
}

//==================================
// Display Function
//==================================

void User::display() const
{
    std::cout << "\n==================================\n";
    std::cout << "          USER DETAILS\n";
    std::cout << "==================================\n";

    std::cout << "Name    : " << name << '\n';
    std::cout << "Age     : " << age << '\n';
    std::cout << "Gender  : " << gender << '\n';
    std::cout << "Phone   : " << phone << '\n';
    std::cout << "Email   : " << email << '\n';
    std::cout << "Address : " << address << '\n';
}

//==================================
// Destructor
//==================================

User::~User()
{
}