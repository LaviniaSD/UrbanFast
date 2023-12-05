// Class WareHouse

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class WareHouse {
    private:
        int iWareHouseID;
        int iItems;
        int iQuantity;
        int iLocation; 

    public:
        WareHouse(int iWareHouseID, int iItems, int iQuantity, int iLocation);

        void setWareHouseID(int iWareHouseID);
        int getWareHouseID();

        void setItems(int iItems);
        int getItems();

        void setQuantity(int iQuantity);
        int getQuantity();

        void setLocation(int iLocation);
        int getLocation();


};

#endif
