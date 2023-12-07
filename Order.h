// Class Order (incomplete)

#pragma once

#include <queue>
#include "Deliveryman.h"
#include "Map.h"
using namespace std;

class Order {
    private:
        bool bType; // 0 for simple, 1 for optimazed
        int iOrderNumber;
        int iItems;
        int iQuantity;
        int iOrigin;
        int iDestination;
        int iPrice;
        DeliveryMan iDeliveryMan;

    public:
        Order(int iItems, int iQuantity, int iDestination, int iPrice, DeliveryMan iDeliveryMan, int iOrderNumber, int iOrigin, bool bType);

        void setType(bool bType);
        bool getType(){
            return bType;
        }

        void setOrderNumber(int iOrderNumber);
        int getOrderNumber(){
            return iOrderNumber;
        }

        void setItems(int iItems);
        int getItems(){
            return iItems;
        }

        void setQuantity(int iQuantity);
        int getQuantity(){
            return iQuantity;
        }

        void setOrigin(int iOrigin);
        int getOrigin(){
            return iOrigin; 
        }

        void setDestination(int iDestination);
        int getDestination(){
            return iDestination;
        }

        void setPrice(int iPrice);
        int getPrice(){
            return iPrice;
        }

        void setDeliveryMan(DeliveryMan iDeliveryMan);
        DeliveryMan getDeliveryMan(){
            return iDeliveryMan;
        }

        ReturnDijkstra FindRoute(Map map);
};