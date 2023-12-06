// Class DeliveryMan

#ifndef DELIVERYMAN_H
#define DELIVERYMAN_H

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

    public:
        DeliveryMan(int iDeliveryManID, int iLocation, int iCapacity, int iItems, int iQuantity):iDeliveryManID(iDeliveryManID),iLocation()iLocation{}

        void setDeliveryManID(int iDeliveryManID){}
        int getDeliveryManID(){
            return iDeliveryManID;
        }

        void setLocation(int iLocation){}
        int getLocation(){
            return iLocation;
        }

        void setCapacity(int iCapacity){}
        int getCapacity(){
            return iCapacity;
        }

        void setItems(int iItems){}
        int getItems(){
            return iItems;
        }

        void setQuantity(int iQuantity){}
        int getQuantity(){
            return iQuantity;
        }

        queue<int> SeeRoute(Order order){}


};

#endif
