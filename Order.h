// Class Order

#ifndef ORDER_H
#define ORDER_H

#include <queue>
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
        int iDeliveryMan;

    public:
        Order(int iItems, int iQuantity, int iDestination);

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

        void setDeliveryMan(int iDeliveryMan);
        int getDeliveryMan(){
            return iDeliveryMan;
        }

        queue<int> FindRoute();


};

#endif
