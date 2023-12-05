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
        DeliveryMan(int iLocation, int iCapacity, int iItems, int iQuantity);

        void setDeliveryManID(int iDeliveryManID);
        int getDeliveryManID();

        void setLocation(int iLocation);
        int getLocation();

        void setCapacity(int iCapacity);
        int getCapacity();

        void setItems(int iItems);
        int getItems();

        void setQuantity(int iQuantity);
        int getQuantity();

        queue<int> SeeRoute(Order order);


};

#endif
