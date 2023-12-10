/**
 * @file Product.h
 * @brief This file contains the declaration of the Product class
 * 
 * This file contains the declaration of the Product class
 * which is used to store the details of the product
 * 
 */

#pragma once

class Product {
    private:
        int iProductID; // Product ID
        int iPrice; // Price of the product
        int iQuantity; // Quantity of the product
        int iWeight; // Weight of the product
        Product* next; // Pointer to the next product
    public:
        /**
         * @brief Constructor for the Product class
         * 
         * @param iProductID The ID of the product
         * @param iPrice The price of the product
         * @param iQuantity The quantity of the product
         * @param iWeight The weight of the product
         * @param next Pointer to the next product
         */
        Product(int iProductID, int iPrice, int iQuantity, int iWeight, Product* next):
        iProductID(iProductID),
        iPrice(iPrice),
        iQuantity(iQuantity),
        iWeight(iWeight),
        next(next) {}

        ~Product() {}

        /**
         * @brief Set the product ID
         * 
         * @param iProductID The ID of the product
         */
        void setProductID(int newiProductID){
            iProductID = newiProductID;             
        }

        /**
         * @brief Get the product ID
         * 
         * @return int The ID of the product
         */
        int getProductID(){
            return iProductID;
        }

        /**
         * @brief Set the price of the product
         * 
         * @param iPrice The price of the product
         */
        void setPrice(int newiPrice){
            iPrice = newiPrice;
        }

        /**
         * @brief Get the price of the product
         * 
         * @return int The price of the product
         */
        int getPrice(){
            return iPrice;
        }

        /**
         * @brief Set the quantity of the product
         * 
         * @param iQuantity The quantity of the product
         */
        void setQuantity(int newiQuantity){
            iQuantity = newiQuantity;
        }

        /**
         * @brief Get the quantity of the product
         * 
         * @return int The quantity of the product
         */
        int getQuantity(){
            return iQuantity; 
        }

        /**
         * @brief Set the weight of the product
         * 
         * @param iWeight The weight of the product
         */
        void setWeight(int newiWeight){
            iWeight = newiWeight;
        }

        /**
         * @brief Get the weight of the product
         * 
         * @return int The weight of the product
         */
        int getWeight(){
            return iWeight; 
        }

        /**
         * @brief Get the pointer to the next product
         * 
         * @return Product* Pointer to the next product
         */
                Product* getNext() const {
            return next;
        }

        /**
         * @brief Set the pointer to the next product
         * 
         * @param newNext Pointer to the next product
         */
        void setNext(Product* newNext){
            next = newNext;
        }
};
