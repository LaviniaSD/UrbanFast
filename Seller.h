// Class Seller

#pragma once

#include "Product.h"

// Class representing a seller
class Seller {
    private:
        int iSellerID; // Seller ID
        int iSellerLocation; // Location of the seller
        Seller* next; // Pointer to the next seller

    public:
        Product* pProductsList; // Pointer to the list of products
        
        // Constructor for the Seller class
        Seller(int iSellerID, int iSellerLocation, Seller* next);

        // Destructor for the Seller class
        ~Seller();

        // Setter and getter methods for Seller ID
        void setSellerID(int iSellerID){
            iSellerID = iSellerID;
        }
        int getSellerID(){
            return iSellerID;
        }

        // Setter and getter methods for Seller location
        void setSellerLocation(int SellerLocation){
            SellerLocation = SellerLocation;
        }
        int getSellerLocation(){
            return iSellerLocation;
        }

        // Setter and getter methods for the next seller
        void setNext(Seller* newNext){
            next = newNext;
        }

        Seller* getNext(){
            return next;
        }

        // Method to add products to the seller's product list
        void addProducts(int iProductNumber, int iPrice, int iQuantity, int iWeight);

        // Method to remove products from the seller's product list
        void removeProducts(int iProductID, int iQuantity);

};
