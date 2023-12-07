// Class Order (incomplete)

#pragma once

#include "Product.h"


#include <queue>
#include <vector>

using namespace std;

// Structure representing the quantity of a product in an order
struct ProductQuantity{
    Product pProduct; // Product information
    int iQuantity; // Quantity of the product
    ProductQuantity* next; // Pointer to the next product quantity node

    // Constructor for ProductQuantity
    ProductQuantity(Product pProduct, int iQuantity): pProduct(pProduct), iQuantity(iQuantity), next(nullptr){}

    // Destructor for ProductQuantity
    ~ProductQuantity() {
        // Free the dynamically allocated memory for the next nodes
        while (next != nullptr) {
            ProductQuantity* temp = next;
            next = next->getNext();
            delete temp;
        }
    }

    // Getter methods
    Product getProduct() const {
        return pProduct;
    }

    int getQuantity() const {
        return iQuantity;
    }

    ProductQuantity* getNext() const {
        return next;
    }

    // Setter methods
    void setProduct(Product& product) {
        pProduct = product;
    }

    void setQuantity(int quantity) {
        iQuantity = quantity;
    }

    void setNext(ProductQuantity* nextNode) {
        next = nextNode;
    }

};

class Order {
    private:
        bool bType; // Type of the order (0 for simple, 1 for optimized)
        int iOrderNumber; // Order number
        int iOrigin; // Origin of the order
        int iDestination; // Destination of the order
        int iPrice; // Total price of the order
        int iWeight; // Total weight of the order
        Order* next; // Pointer to the next order
 
    public:
        ProductQuantity* pProducts; // Pointer to the linked list of product quantities in the order

        // Constructor for the Order class
        Order(int OrderNumber, int iDestination, int iOrigin, bool bType);

        // Destructor for the Order class
        ~Order();

        // Getter and setter methods for private members
        void setType(bool bType){
            bType = bType;
        }
        bool getType(){
            return bType;
        }

        void setOrderNumber(int iOrderNumber){
            iOrderNumber = iOrderNumber; 
        }
        int getOrderNumber(){
            return iOrderNumber;
        }

        void setOrigin(int iOrigin){
            iOrigin = iOrigin;
        }
        int getOrigin(){
            return iOrigin; 
        }

        void setDestination(int iDestination){
            iDestination = iDestination;
        }
        int getDestination(){
            return iDestination;
        }

        int getPrice(){
            return iPrice;
        }

        int getWeight(){
            return iWeight;
        }

        void setNext(Order* newNext){
            next = newNext;
        }
        Order* getNext(){
            return next;
        }

        // Method to add products to the order
        void addProducts(int iProductID, int iPrice, int iQuantity, int iWeight);

};