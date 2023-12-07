// Class WareHouse

#pragma once

class Warehouse {
    private:
        int iWarehouseID;
        int iItems;
        int iQuantity;
        int iLocation; 

    public:
        Warehouse(int iWarehouseID, int iItems, int iQuantity, int iLocation);

        void setWarehouseID(int newID) {
            iWarehouseID = newID;
        }
        int getWarehouseID(){
            return iWarehouseID;
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

        void setLocation(int newLocation){
            iLocation = newLocation;
        }
        int getLocation(){
            return iLocation;
        }
};
