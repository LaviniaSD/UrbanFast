/**
 * @file Seller.h
 * @brief Header file for the Seller class.
 * 
 * This file contains the definition of the Seller class, its attributes, and its methods.
 * The Seller class represents a seller and contains information about the seller's ID, location, and products.
 * It also provides methods to add and remove products from the seller's product list.
 */

#pragma once

#include "Product.h"

/**
 * @brief Class representing a seller.
 * 
 * This class represents a seller and contains information about the seller's ID, location, and products.
 * It also provides methods to add and remove products from the seller's product list.
 */
class Seller {
    private:
        int iSellerID; // Seller ID
        int iSellerLocation; // Location of the seller
        Seller* next; // Pointer to the next seller

    public:
        Product* pProductsList; // Pointer to the list of products
        
        /**
         * @brief Constructor for the Seller class.
         * 
         * @param iSellerID The ID of the seller.
         * @param iSellerLocation The location of the seller.
         * @param next Pointer to the next seller.
         */
        Seller(int iSellerID, int iSellerLocation, Seller* next);

        /**
         * @brief Destructor for the Seller class.
         */
        ~Seller();

        /**
         * @brief Setter method for Seller ID.
         * 
         * @param iSellerID The ID of the seller.
         */
        void setSellerID(int iSellerID){
            iSellerID = iSellerID;
        }

        /**
         * @brief Getter method for Seller ID.
         * 
         * @return The ID of the seller.
         */
        int getSellerID(){
            return iSellerID;
        }

        /**
         * @brief Setter method for Seller location.
         * 
         * @param SellerLocation The location of the seller.
         */
        void setSellerLocation(int SellerLocation){
            SellerLocation = SellerLocation;
        }

        /**
         * @brief Getter method for Seller location.
         * 
         * @return The location of the seller.
         */
        int getSellerLocation(){
            return iSellerLocation;
        }

        /**
         * @brief Setter method for the next seller.
         * 
         * @param newNext Pointer to the next seller.
         */
        void setNext(Seller* newNext){
            next = newNext;
        }

        /**
         * @brief Getter method for the next seller.
         * 
         * @return Pointer to the next seller.
         */
        Seller* getNext(){
            return next;
        }

        /**
         * @brief Method to add products to the seller's product list.
         * 
         * @param iProductNumber The product number.
         * @param iPrice The price of the product.
         * @param iQuantity The quantity of the product.
         * @param iWeight The weight of the product.
         */
        void addProducts(int iProductNumber, int iPrice, int iQuantity, int iWeight);

        /**
         * @brief Method to add products to the seller's product list.
         * 
         * @param iProductNumber The product number.
         * @param iPrice The price of the product.
         * @param iQuantity The quantity of the product.
         * @param iWeight The weight of the product.
         */
        void addProducts(Product* newProduct);

        /**
         * @brief Method to remove products from the seller's product list.
         * 
         * @param iProductID The ID of the product to be removed.
         * @param iQuantity The quantity of the product to be removed.
         */
        void removeProducts(int iProductID, int iQuantity);

        /**
         * @brief Method to check if the seller has a specific product in a certain quantity.
         * 
         * @param pProduct The product to be checked.
         * @param iQuantity The quantity of the product to be checked.
         * @return True if the seller has the product in the specified quantity, false otherwise.
         */
        bool hasProduct(Product pProduct, int iQuantity);

};
