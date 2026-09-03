#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>

class Admin : public User
{
private:
    std::string username;
    std::string password;

public:

    // Constructors
    Admin();

    Admin(std::string name,
          int age,
          std::string gender,
          std::string phone,
          std::string email,
          std::string address,
          std::string username,
          std::string password);

    // Authentication
    bool login();

    void logout();

    void changePassword();

    // Display
    void display() const override;

    // Getters
    std::string getUsername() const;

    std::string getPassword() const;

    // Setters
    void setUsername(std::string username);

    void setPassword(std::string password);

    // Destructor
    ~Admin() override;
};

#endif