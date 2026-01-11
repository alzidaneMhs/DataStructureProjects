#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>
using namespace std;

struct Customer {
    string name;
    Customer* next;
};

struct Restaurant {
    string name;
    Restaurant* next;
};

struct Driver {
    string name;
    Driver* next;
};

struct Order {
    int orderID;
    Customer* customer;
    Restaurant* restaurant;
    Driver* driver;

    string food;
    string payment;
    string status;

    Order* next;
};

void addRestaurant(string name);
void addDriver(string name);

void createOrder();
void assignDriver();
void completeOrder();
void cancelOrder();
void showOrders();

#endif
