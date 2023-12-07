#include "Deliveryman.h"

#include <iostream>

using namespace std;

// Constructor for the DeliveryMan class
DeliveryMan::DeliveryMan(int iDeliveryManID, int iDeliveryManLocation, int iCapacity, int iQuantity, DeliveryMan* next):
iDeliveryManID(iDeliveryManID), 
iDeliveryManLocation(iDeliveryManLocation), 
iCapacity(iCapacity), 
iQuantity(0),
iPrice(0),
next(next),
oOrders(nullptr){}

// Destructor for the DeliveryMan class
DeliveryMan::~DeliveryMan() {
    Order* currentOrder = oOrders;
    // Free the dynamically allocated memory for the orders
    while (currentOrder != nullptr) {
        Order* nextOrder = currentOrder->getNext();
        delete currentOrder;
        currentOrder = nextOrder;
    }
}

// Method to add an order to the delivery man's list
void DeliveryMan::addOrder(Order* newOrder){

    // Check if adding the order exceeds the delivery man's capacity
    if(iCapacity-iQuantity<newOrder->getWeight()){
        cout << "Capacidade máxima atingida" <<endl;

    }

    // Update quantity and price
    iQuantity += newOrder->getWeight();
    iPrice += newOrder->getPrice();

    // Add the order to the list
    if(!oOrders){
        oOrders = newOrder;      
    }
    else{
        newOrder->setNext(oOrders);
        oOrders = newOrder;
    }
}

// Method to mark an order as delivered and remove it from the list
void DeliveryMan::orderDelivered(int iOrderNumber) {
    Order* currentOrder = oOrders;
    Order* previousOrder = nullptr;

    // Search for the order in the list
    while (currentOrder != nullptr) {
        if (currentOrder->getOrderNumber() == iOrderNumber) {

            // Remove the order from the list
            if (previousOrder != nullptr) {
                previousOrder->setNext(currentOrder->getNext());
            } else {
                oOrders = currentOrder->getNext();
            }

            // Free the memory for the order
            delete currentOrder;

            // Update quantity
            iQuantity -= currentOrder->getWeight();

            cout << "Pedido removido com sucesso." << endl;
            return;
        }

        previousOrder = currentOrder;
        currentOrder = currentOrder->getNext();
    }

    cout << "Pedido não encontrado." << endl;
}