// Class Product

#pragma once

class Product {
    private:
        int iProductID; // Product ID
        int iPrice; // Price of the product
        int iQuantity; // Quantity of the product
        int iWeight; // Weight of the product
        Product* next; // Pointer to the next product
    public:
        // Constructor for the Product class
        Product(int iProductID, int iPrice, int iQuantity, int iWeight, Product* next):iProductID(iProductID),iPrice(iPrice),iQuantity(iQuantity),iWeight(iWeight){}

        // Getter and setter methods for private members
        void setProductID(int iProductID){
            iProductID = iProductID;             
        }
        int getProductID(){
            return iProductID;
        }

        void setPrice(int iPrice){
            iPrice = iPrice;
        }
        int getPrice(){
            return iPrice;
        }

        void setQuantity(int iQuantity){
            iQuantity = iQuantity;
        }
        int getQuantity(){
            return iQuantity; 
        }

        void setWeight(int iWeight){
            iWeight = iWeight;
        }
        int getWeight(){
            return iWeight; 
        }

        Product* getNext() const {
            return next;
        }

        void setNext(Product* newNext){
            next = newNext;
        }

};

