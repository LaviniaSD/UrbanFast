/**
 * @file Warehouse.h
 * @brief Header file for the Warehouse class.
 *
 * This file contains the definitions of the attributes and methods of the Warehouse class,
 * as well as its constructor and destructor.
 */

#pragma once

#include "Product.h"

/**
 * @brief Class representing a warehouse.
 * 
 * This class represents a warehouse, which stores products.
 * It contains information about the warehouse ID, location, and a linked list of products.
 */
class Warehouse {
    private:
        int iWarehouseID; // Warehouse identifier
        int iWarehouseLocation; // Warehouse location
        Warehouse* next; // Pointer to the next warehouse

    public:
        Product* pProductsList; // Pointer to the linked list of products in the warehouse

        /**
         * @brief Constructor for the Warehouse class.
         * 
         * @param iWarehouseID The ID of the warehouse.
         * @param iWarehouseLocation The location of the warehouse.
         * @param next Pointer to the next warehouse in the list.
         */
        Warehouse(int iWarehouseID, int iWarehouseLocation, Warehouse* next);

        /**
         * @brief Destructor for the Warehouse class.
         */
        ~Warehouse();

        /**
         * @brief Setter for the warehouse ID.
         * 
         * @param iWarehouseID The ID of the warehouse.
         */
        void setWarehouseID(int iWarehouseID){
            iWarehouseID = iWarehouseID;
        }

        /**
         * @brief Getter for the warehouse ID.
         * 
         * @return The ID of the warehouse.
         */
        int getWarehouseID(){
            return iWarehouseID;
        }

        /**
         * @brief Setter for the warehouse location.
         * 
         * @param WarehouseLocation The location of the warehouse.
         */
        void setWarehouseLocation(int WarehouseLocation){
            WarehouseLocation = WarehouseLocation;
        }

        /**
         * @brief Getter for the warehouse location.
         * 
         * @return The location of the warehouse.
         */
        int getWarehouseLocation(){
            return iWarehouseLocation;
        }

        /**
         * @brief Setter for the next warehouse in the list.
         * 
         * @param newNext Pointer to the next warehouse in the list.
         */
        void setNext(Warehouse* newNext){
            next = newNext;
        }

        /**
         * @brief Getter for the next warehouse in the list.
         * 
         * @return Pointer to the next warehouse in the list.
         */
        Warehouse* getNext(){
            return next;
        }

        /**
         * @brief Method to add products to the warehouse's product list.
         * 
         * @param iProductNumber The number of the product.
         * @param iPrice The price of the product.
         * @param iQuantity The quantity of the product.
         * @param iWeight The weight of the product.
         */
        void addProducts(int iProductNumber, int iPrice, int iQuantity, int iWeight);

        /**
         * @brief Method to remove products from the warehouse's product list.
         * 
         * @param iProductID The ID of the product.
         * @param iQuantity The quantity of the product to remove.
         */
        void removeProducts(int iProductID, int iQuantity);

        /**
         * @brief Method to check if the warehouse has a certain product in a certain quantity.
         * 
         * @param pProduct The product to check.
         * @param iQuantity The quantity of the product to check.
         * @return True if the warehouse has the product in the specified quantity, false otherwise.
         */
        bool hasProduct(Product pProduct, int iQuantity);
};
