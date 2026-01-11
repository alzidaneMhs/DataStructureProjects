#include "restaurant.h"
#include <iostream>

Customer* customerHead = NULL;
Restaurant* restaurantHead = NULL;
Driver* driverHead = NULL;
Order* orderHead = NULL;

int autoOrderID = 1;

/* ===== area of helpers ===== */

Customer* findOrCreateCustomer(string name) {
    Customer* temp = customerHead;
    while (temp) {
        if (temp->name == name) return temp;
        temp = temp->next;
    }
    Customer* newC = new Customer{name, customerHead};
    customerHead = newC;
    return newC;
}

Restaurant* getRestaurantByIndex(int index) {
    Restaurant* temp = restaurantHead;
    int i = 1;
    while (temp) {
        if (i == index) return temp;
        temp = temp->next;
        i++;
    }
    return NULL;
}

Driver* findDriver(string name) {
    Driver* temp = driverHead;
    while (temp) {
        if (temp->name == name) return temp;
        temp = temp->next;
    }
    return NULL;
}

/* ===== for input/add data ===== */

void addRestaurant(string name) {
    restaurantHead = new Restaurant{name, restaurantHead};
}

void addDriver(string name) {
    driverHead = new Driver{name, driverHead};
}

/* ===== features core ===== */

void createOrder() {
    string cname, food;
    int restChoice, payChoice;

    cin.ignore();

    cout << "Your Name: ";
    getline(cin, cname);

    cout << "\nAvailable Restaurants:\n";
    Restaurant* rtemp = restaurantHead;
    int idx = 1;
    while (rtemp) {
        cout << idx++ << ". " << rtemp->name << endl;
        rtemp = rtemp->next;
    }

    cout << "Choose Restaurant (number): ";
    cin >> restChoice;

    Restaurant* r = getRestaurantByIndex(restChoice);
    if (!r) {
        cout << "Invalid restaurant choice.\n";
        return;
    }

    cin.ignore();
    cout << "Food Ordered: ";
    getline(cin, food);

    cout << "\nPayment Method:\n";
    cout << "1. OVO\n2. GOPAY\n3. BANK\nChoose: ";
    cin >> payChoice;

    string payment;
    if (payChoice == 1) payment = "OVO";
    else if (payChoice == 2) payment = "GOPAY";
    else if (payChoice == 3) payment = "BANK";
    else {
        cout << "Invalid payment method.\n";
        return;
    }

    Customer* c = findOrCreateCustomer(cname);

    Order* newOrder = new Order;
    newOrder->orderID = autoOrderID++;
    newOrder->customer = c;
    newOrder->restaurant = r;
    newOrder->driver = NULL;
    newOrder->food = food;
    newOrder->payment = payment;
    newOrder->status = "Preparing";
    newOrder->next = orderHead;

    orderHead = newOrder;

    cout << "\nOrder SUCCESS!\nYour Order ID: " << newOrder->orderID << endl;
}

void assignDriver() {
    int oid;
    string dname;

    cout << "Order ID: ";
    cin >> oid;
    cin.ignore();

    cout << "Driver Name: ";
    getline(cin, dname);

    Driver* d = findDriver(dname);
    if (!d) {
        cout << "Driver not found.\n";
        return;
    }

    Order* temp = orderHead;
    while (temp) {
        if (temp->orderID == oid) {
            temp->driver = d;
            temp->status = "On Delivery";
            cout << "Driver assigned.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Order not found.\n";
}

void completeOrder() {
    int oid;
    cout << "Order ID: ";
    cin >> oid;

    Order* temp = orderHead;
    while (temp) {
        if (temp->orderID == oid) {
            temp->status = "Delivered";
            cout << "Order completed.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Order not found.\n";
}

void cancelOrder() {
    int oid;
    cout << "Order ID to cancel: ";
    cin >> oid;

    Order* curr = orderHead;
    Order* prev = NULL;

    while (curr) {
        if (curr->orderID == oid) {
            if (prev) prev->next = curr->next;
            else orderHead = curr->next;
            delete curr;
            cout << "Order canceled.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Order not found.\n";
}

void showOrders() {
    if (!orderHead) {
        cout << "No orders available.\n";
        return;
    }

    Order* temp = orderHead;
    cout << "\n=== ORDERS ===\n";
    while (temp) {
        cout << "Order ID: " << temp->orderID << endl;
        cout << "Customer: " << temp->customer->name << endl;
        cout << "Restaurant: " << temp->restaurant->name << endl;
        cout << "Food: " << temp->food << endl;
        cout << "Payment: " << temp->payment << endl;

        if (temp->driver)
            cout << "Driver: " << temp->driver->name << endl;
        else
            cout << "Driver: Not Assigned\n";

        cout << "Status: " << temp->status << endl;
        cout << "----------------------\n";
        temp = temp->next;
    }
}
