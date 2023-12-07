// Class WareHouse

#pragma once

class Warehouse {
    private:
        int iWarehouseID;
        int iItems[100];
        int iLocation; 
        Warehouse* next;

    public:
        Warehouse(int iWarehouseID, int iLocation, Warehouse* next);

        void setWarehouseID(int newID) {
            iWarehouseID = newID;
        }
        int getWarehouseID(){
            return iWarehouseID;
        }

        void setItems(int newItems){
            iItems[newItems]++;
        }
        int* getItems(){
            return iItems;
        }

        void setLocation(int newLocation){
            iLocation = newLocation;
        }
        int getLocation(){
            return iLocation;
        }
        void removeItem(int removeItem);

        void setNext(Warehouse* newNext){
            next = newNext;
        }
        Warehouse* getNext(){
            return next;
        }
};
