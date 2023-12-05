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
        bool getType();

        void setOrderNumber(int iOrderNumber);
        int getOrderNumber();

        void setItems(int iItems);
        int getItems();

        void setQuantity(int iQuantity);
        int getQuantity();

        void setOrigin(int iOrigin);
        int getOrigin();

        void setDestination(int iDestination);
        int getDestination();

        void setPrice(int iPrice);
        int getPrice();

        void setDeliveryMan(int iDeliveryMan);
        int getDeliveryMan();

        queue<int> FindRoute();


};

#endif
