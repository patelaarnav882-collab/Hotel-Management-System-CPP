#ifndef USER_H
#define USER_H

#include <string>

class User
{
protected:
    std::string name;
    int age;
    std::string gender;
    std::string phone;
    std::string email;
    std::string address;

public:

    User();

    User(std::string,
         int,
         std::string,
         std::string,
         std::string,
         std::string);

    virtual void display() const;

    virtual ~User();

    //==============================
    // Setters
    //==============================

    void setName(std::string name);

    void setAge(int age);

    void setGender(std::string gender);

    void setPhone(std::string phone);

    void setEmail(std::string email);

    void setAddress(std::string address);

    //==============================
    // Getters
    //==============================
        
    std::string getName() const;
        
    int getAge() const;
        
    std::string getGender() const;
        
    std::string getPhone() const;
        
    std::string getEmail() const;
        
    std::string getAddress() const;
};

#endif