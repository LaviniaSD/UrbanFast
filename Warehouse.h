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
        int getWareHouseID(){
            return iWareHouseID;
        }

        void setItems(int iItems);
        int getItems(){
            return iItems;
        }

        void setQuantity(int iQuantity);
        int getQuantity(){
            return iQuantity;
        }

        void setLocation(int iLocation);
        int getLocation(){
            return iLocation;
        }


};

#endif
