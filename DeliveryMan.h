// Class DeliveryMan

#pragma once

#include "Order.h"
#include <queue>

using namespace std;

// Class representing a DeliveryMan
class DeliveryMan {
    private:
        int iDeliveryManID;
        int iDeliveryManLocation;
        int iCapacity;
        int iQuantity;
        int iPrice;
        DeliveryMan* next;
    public:
        Order* oOrders;
        
        // Constructor for the DeliveryMan class
        DeliveryMan(int iDeliveryManID, int iDeliveryManLocation, int iCapacity, int iQuantity, DeliveryMan* next);

        // Destructor for the DeliveryMan class
        ~DeliveryMan();
        
        // Setter and getter methods for the DeliveryManID
        void setDeliveryManID(int newID){
            iDeliveryManID = iDeliveryManID;
        }
        int getDeliveryManID(){
            return iDeliveryManID;
        }

        // Setter and getter methods for the DeliveryMan's location
        void setLocation(int newLocation){
            iDeliveryManLocation = newLocation;
        }
        int getLocation(){
            return iDeliveryManLocation;
        }

        // Setter and getter methods for the DeliveryMan's capacity
        void setCapacity(int newCapacity){
            iCapacity = newCapacity;
        }
        int getCapacity(){
            return iCapacity;
        }

        // Getter methods for the DeliveryMan's quantity and price
        int getQuantity(){
            return iQuantity;
        }
        
        int getPrice(){
            return iPrice;
        }
        
        // Setter and getter methods for the next DeliveryMan in the list
        void setNext(DeliveryMan* newNext){
            next = newNext;
        }
        DeliveryMan* getNext(){
            return next;
        }

        // Method to add an order to the DeliveryMan's list
        void addOrder(Order* oOrder);

        void orderDelivered(int iOrderNumber);

        // Method to see the route of an order (commented out as it is not implemented)
        //queue<int> SeeRoute(Order order);
};
