/**
 * @file Order.h
 * @brief Defines the Order class and the ProductQuantity struct.
 * 
 * The Order class represents an order in the UrbanFast system. It contains information such as the order number, origin, destination, price, weight, and a linked list of product quantities.
 * The ProductQuantity struct represents the quantity of a product in an order. It contains information about the product, the quantity, and a pointer to the next product quantity node.
 */

#pragma once

#include "Product.h"

#include <queue>
#include <vector>

using namespace std;

/**
 * @struct ProductQuantity
 * @brief Represents the quantity of a product in an order.
 * 
 * The ProductQuantity struct contains information about the product, the quantity, and a pointer to the next product quantity node.
 */
struct ProductQuantity{
    Product pProduct; // Product information
    int iQuantity; // Quantity of the product
    ProductQuantity* next; // Pointer to the next product quantity node

    /**
     * @brief Constructor for ProductQuantity.
     * @param pProduct The product information.
     * @param iQuantity The quantity of the product.
     */
    ProductQuantity(Product pProduct, int iQuantity): pProduct(pProduct), iQuantity(iQuantity), next(nullptr){}

    /**
     * @brief Destructor for ProductQuantity.
     */
    ~ProductQuantity() {
        // Free the dynamically allocated memory for the next nodes
        while (next != nullptr) {
            ProductQuantity* temp = next;
            next = next->getNext();
            delete temp;
        }
    }

    /**
     * @brief Get the product information.
     * @return The product information.
     */
    Product getProduct() const {
        return pProduct;
    }

    /**
     * @brief Get the quantity of the product.
     * @return The quantity of the product.
     */
    int getQuantity() const {
        return iQuantity;
    }

    /**
     * @brief Get the pointer to the next product quantity node.
     * @return The pointer to the next product quantity node.
     */
    ProductQuantity* getNext() const {
        return next;
    }

    /**
     * @brief Set the product information.
     * @param product The product information to set.
     */
    void setProduct(Product& product) {
        pProduct = product;
    }

    /**
     * @brief Set the quantity of the product.
     * @param quantity The quantity of the product to set.
     */
    void setQuantity(int quantity) {
        iQuantity = quantity;
    }

    /**
     * @brief Set the pointer to the next product quantity node.
     * @param nextNode The pointer to the next product quantity node to set.
     */
    void setNext(ProductQuantity* nextNode) {
        next = nextNode;
    }

};

/**
 * @class Order
 * @brief Represents an order in the UrbanFast system.
 * 
 * The Order class represents an order in the UrbanFast system. It contains information such as the order number, origin, destination, price, weight, and a linked list of product quantities.
 */
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

        /**
         * @brief Constructor for the Order class.
         * @param OrderNumber The order number.
         * @param iDestination The destination of the order.
         * @param iOrigin The origin of the order.
         * @param bType The type of the order (0 for simple, 1 for optimized).
         */
        Order(int OrderNumber, int iDestination, int iOrigin, bool bType);

        /**
         * @brief Destructor for the Order class.
         */
        ~Order();

        /**
         * @brief Set the type of the order.
         * @param bType The type of the order to set (0 for simple, 1 for optimized).
         */
        void setType(bool bType){
            bType = bType;
        }

        /**
         * @brief Get the type of the order.
         * @return The type of the order (0 for simple, 1 for optimized).
         */
        bool getType(){
            return bType;
        }

        /**
         * @brief Set the order number.
         * @param iOrderNumber The order number to set.
         */
        void setOrderNumber(int iOrderNumber){
            iOrderNumber = iOrderNumber; 
        }

        /**
         * @brief Get the order number.
         * @return The order number.
         */
        int getOrderNumber(){
            return iOrderNumber;
        }

        /**
         * @brief Set the origin of the order.
         * @param iOrigin The origin of the order to set.
         */
        void setOrigin(int iOrigin){
            iOrigin = iOrigin;
        }

        /**
         * @brief Get the origin of the order.
         * @return The origin of the order.
         */
        int getOrigin(){
            return iOrigin; 
        }

        /**
         * @brief Set the destination of the order.
         * @param iDestination The destination of the order to set.
         */
        void setDestination(int iDestination){
            iDestination = iDestination;
        }

        /**
         * @brief Get the destination of the order.
         * @return The destination of the order.
         */
        int getDestination(){
            return iDestination;
        }

        /**
         * @brief Get the total price of the order.
         * @return The total price of the order.
         */
        int getPrice(){
            return iPrice;
        }

        /**
         * @brief Get the total weight of the order.
         * @return The total weight of the order.
         */
        int getWeight(){
            return iWeight;
        }

        /**
         * @brief Set the pointer to the next order.
         * @param newNext The pointer to the next order to set.
         */
        void setNext(Order* newNext){
            next = newNext;
        }

        /**
         * @brief Get the pointer to the next order.
         * @return The pointer to the next order.
         */
        Order* getNext(){
            return next;
        }

        /**
         * @brief Add products to the order.
         * @param iProductID The ID of the product.
         * @param iPrice The price of the product.
         * @param iQuantity The quantity of the product.
         * @param iWeight The weight of the product.
         */
        void addProducts(int iProductID, int iPrice, int iQuantity, int iWeight);

};