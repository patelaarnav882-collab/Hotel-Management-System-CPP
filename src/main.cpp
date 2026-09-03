#include <iostream>

#include "include/Hotel.h"
#include "include/Admin.h"

using namespace std;

int main()
{
    Hotel hotel("Grand Palace Hotel");

    // Load previous data
    hotel.loadData();

    int choice;

    do
    {
        cout << "\n=========================================\n";
        cout << "      HOTEL MANAGEMENT SYSTEM\n";
        cout << "=========================================\n";
        cout << "1. Hotel Information\n";
        cout << "2. Show All Rooms\n";
        cout << "3. Show Available Rooms\n";
        cout << "4. Book Room\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Search Customer\n";
        cout << "7. Generate Bill\n";
        cout << "8. Print Receipt\n";
        cout << "9. Hotel Statistics\n";
        cout << "10. Save Data\n";
        cout << "11. Load Data\n";
        cout << "12. Clear All Data\n";
        cout << "13. Exit\n";
        cout << "=========================================\n";
        cout << "Enter Choice : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            hotel.displayHotelInfo();
            break;

        case 2:
            hotel.showAllRooms();
            break;

        case 3:
            hotel.showAvailableRooms();
            break;

        case 4:
            hotel.bookRoom();
            break;

        case 5:
            hotel.cancelBooking();
            break;

        case 6:
        {
            int searchChoice;

            cout << "\nSearch Customer By\n";
            cout << "1. Booking ID\n";
            cout << "2. Name\n";
            cout << "3. Phone\n";
            cout << "Enter Choice : ";

            cin >> searchChoice;

            switch (searchChoice)
            {
            case 1:
                hotel.searchCustomerByBookingID();
                break;

            case 2:
                hotel.searchCustomerByName();
                break;

            case 3:
                hotel.searchCustomerByPhone();
                break;

            default:
                cout << "Invalid Choice!\n";
            }

            break;
        }

        case 7:
        {
            string bookingID;

            cout << "Enter Booking ID : ";
            cin >> bookingID;

            hotel.generateBill(bookingID);

            break;
        }

        case 8:
        {
            string bookingID;

            cout << "Enter Booking ID : ";
            cin >> bookingID;

            hotel.printReceipt(bookingID);

            break;
        }

        case 9:
            hotel.showStatistics();
            break;

        case 10:
            hotel.saveData();
            break;

        case 11:
            hotel.loadData();
            break;

        case 12:
            hotel.clearAllData();
            break;

        case 13:
            hotel.saveData();

            cout << "\n=========================================\n";
            cout << "Thank you for using the Hotel Management";
            cout << "\nSystem.\n";
            cout << "=========================================\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 13);

    return 0;
}