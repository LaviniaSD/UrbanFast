// Class WareHouse

#pragma once

#include "Product.h"

// Class representing a warehouse
class Warehouse {
    private:
        int iWarehouseID; // Warehouse identifier
        int iWarehouseLocation; // Warehouse location
        Warehouse* next; // Pointer to the next warehouse

    public:
        Product* pProductsList; // Pointer to the linked list of products in the warehouse

        // Constructor
        Warehouse(int iWarehouseID, int iWarehouseLocation, Warehouse* next);

        // Destructor
        ~Warehouse();

        // Setter and Getter for Warehouse ID
        void setWarehouseID(int iWarehouseID){
            iWarehouseID = iWarehouseID;
        }
        int getWarehouseID(){
            return iWarehouseID;
        }

        // Setter and Getter for Warehouse Location
        void setWarehouseLocation(int WarehouseLocation){
            WarehouseLocation = WarehouseLocation;
        }
        int getWarehouseLocation(){
            return iWarehouseLocation;
        }

        // Setter and Getter for the next warehouse in the list
        void setNext(Warehouse* newNext){
            next = newNext;
        }

        Warehouse* getNext(){
            return next;
        }

        // Method to add products to the warehouse's product list
        void addProducts(int iProductNumber, int iPrice, int iQuantity, int iWeight);

        // Method to remove products from the warehouse's product list
        void removeProducts(int iProductID, int iQuantity);

};
