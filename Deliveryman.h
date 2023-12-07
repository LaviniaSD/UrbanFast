// Class DeliveryMan

#pragma once

#include "Order.h"
#include <queue>

using namespace std;

class DeliveryMan {
    private:
        int iDeliveryManID;
        int iLocation;
        int iCapacity;
        int iItems;
        int iQuantity;
        DeliveryMan* next;

    public:
        DeliveryMan(int iDeliveryManID, int iLocation, int iCapacity, int iItems, int iQuantity);

        void setDeliveryManID(int newID){
            iDeliveryManID = iDeliveryManID;
        }
        int getDeliveryManID(){
            return iDeliveryManID;
        }

        void setLocation(int newLocation){
            iLocation = newLocation;
        }
        int getLocation(){
            return iLocation;
        }

        void setCapacity(int newCapacity){
            iCapacity = newCapacity;
        }
        int getCapacity(){
            return iCapacity;
        }

        void setItems(int newItems){
            iItems = newItems;
        }
        int getItems(){
            return iItems;
        }

        void setQuantity(int newQuantity){
            iQuantity = newQuantity;
        }
        int getQuantity(){
            return iQuantity;
        }

        void setNext(DeliveryMan* newNext){
            next = newNext;
        }
        DeliveryMan* getNext(){
            return next;
        }

        queue<int> SeeRoute(Order order);
};
