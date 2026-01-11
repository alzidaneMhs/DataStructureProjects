#include <iostream>
#include "restaurant.h"

using namespace std;

int main() {
    int choice;

    addRestaurant("Pizza Hut");
    addRestaurant("Burger King");
    addRestaurant("KFC");

    addDriver("John");
    addDriver("Mike");

    do {
        cout << "\n=== FOOD DELIVERY SYSTEM ===\n";
        cout << "1. Create Order\n";
        cout << "2. Assign Driver\n";
        cout << "3. Complete Order\n";
        cout << "4. Cancel Order\n";
        cout << "5. Show Orders\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: createOrder(); break;
            case 2: assignDriver(); break;
            case 3: completeOrder(); break;
            case 4: cancelOrder(); break;
            case 5: showOrders(); break;
            case 0: cout << "Bye.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
