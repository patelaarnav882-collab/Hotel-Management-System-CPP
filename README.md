# 🏨 Hotel Management System (C++)

A professional **Hotel Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts. This project provides an efficient way to manage hotel room bookings, customer records, billing, and file-based data storage.

---

## 📌 Features

### 🛏️ Room Management
- Add and initialize hotel rooms
- View all rooms
- View available rooms
- Check room availability
- Book rooms
- Cancel bookings

### 👤 Customer Management
- Register customer details
- Search customer by:
  - Booking ID
  - Name
  - Phone Number
- Display customer information

### 💳 Billing System
- Automatic room charge calculation
- GST calculation
- Discount support
- Bill generation
- Receipt printing

### 📊 Hotel Statistics
- Total rooms
- Available rooms
- Occupied rooms
- Total customers
- Total revenue
- Occupancy percentage

### 💾 File Management
- Save customer data
- Load saved data
- Clear stored data
- Automatic data persistence

### ✅ Validation
- Name validation
- Age validation
- Phone validation
- Email validation
- ID Proof validation
- Date validation
- Booking ID validation

---

# 🚀 Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (Vector)
- Smart Pointers (`std::unique_ptr`)
- File Handling
- Exception Handling
- Modular Programming

---

# 🏗️ Project Structure

```
Hotel-Management-System/
│
├── include/
│   ├── User.h
│   ├── Admin.h
│   ├── Customer.h
│   ├── Room.h
│   ├── Billing.h
│   ├── Validator.h
│   ├── FileManager.h
│   └── Hotel.h
│
├── src/
│   ├── User.cpp
│   ├── Admin.cpp
│   ├── Customer.cpp
│   ├── Room.cpp
│   ├── Billing.cpp
│   ├── Validator.cpp
│   ├── FileManager.cpp
│   ├── Hotel.cpp
│   └── main.cpp
│
├── data/
│   └── hotel_data.txt
│
└── README.md
```

---

# 📚 OOP Concepts Implemented

- Classes & Objects
- Encapsulation
- Inheritance
- Polymorphism
- Constructors & Destructors
- Abstraction
- Composition
- Smart Pointers
- Modular Programming

---

# 📂 Modules

### User
Stores common user details such as name, age, phone, email, and address.

### Admin
Provides administrator functionalities.

### Customer
Handles customer information, bookings, and billing.

### Room
Manages room details, room types, prices, and availability.

### Billing
Calculates:
- Room Charges
- GST
- Discounts
- Total Bill

### Validator
Validates customer and booking information.

### FileManager
Handles saving and loading customer data using file handling.

### Hotel
Main controller class responsible for:
- Room management
- Booking management
- Customer management
- Billing
- Statistics
- File operations

---

# ⚙️ How to Run

### Clone the repository

```bash
git clone https://github.com/your-username/Hotel-Management-System.git
```

### Open the project

Using:

- Visual Studio Code
- CodeBlocks
- Dev C++
- Visual Studio

### Compile

```bash
g++ src/*.cpp -o HotelManagementSystem
```

### Run

```bash
./HotelManagementSystem
```

---

# 📸 Sample Features

✔ Book Room

✔ Cancel Booking

✔ Generate Bill

✔ Print Receipt

✔ Search Customer

✔ View Available Rooms

✔ Hotel Statistics

✔ Save & Load Data

---

# 🎯 Future Improvements

- MySQL Database Integration
- GUI using Qt
- REST API Backend
- Full Stack Web Version
- Online Room Booking
- Payment Gateway Integration
- Admin Authentication
- Customer Login System
- Room Categories
- PDF Bill Generation
- Email Notifications

---

# 👨‍💻 Author

**Aarnav Patel**

Computer Engineering Student

Passionate about C++, Full Stack Development, AI, and Software Engineering.

---

# ⭐ If you like this project

Give this repository a ⭐ on GitHub.