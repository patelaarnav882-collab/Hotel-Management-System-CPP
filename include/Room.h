#ifndef ROOM_H
#define ROOM_H

#include <string>

//==============================
// Room Type
//==============================
enum class RoomType
{
    AC,
    NON_AC
};

//==============================
// Room Status
//==============================
enum class RoomStatus
{
    AVAILABLE,
    OCCUPIED
};

//==============================
// Room Class
//==============================
class Room
{
private:
    int roomNumber;
    int floor;

    RoomType roomType;
    RoomStatus status;

    double pricePerDay;

public:

    //==============================
    // Constructors
    //==============================

    Room();

    Room(
        int roomNumber,
        int floor,
        RoomType roomType,
        double pricePerDay
    );

    //==============================
    // Getters
    //==============================

    int getRoomNumber() const;

    int getFloor() const;

    RoomType getRoomType() const;

    RoomStatus getStatus() const;

    double getPrice() const;

    //==============================
    // Setters
    //==============================

    void setRoomNumber(int roomNumber);

    void setFloor(int floor);

    void setRoomType(RoomType roomType);

    void setStatus(RoomStatus status);

    void setPrice(double price);

    //==============================
    // Utility Functions
    //==============================

    bool isAvailable() const;

    void bookRoom();

    void vacateRoom();

    std::string getRoomTypeString() const;

    std::string getStatusString() const;

    //==============================
    // Display
    //==============================

    void display() const;

    //==============================
    // Destructor
    //==============================

    ~Room();
};

#endif