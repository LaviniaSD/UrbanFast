/**
 * @file DeliveryMan.h
 * @brief Defines the DeliveryMan class and its member functions.
 */

#pragma once

#include "Order.h"
#include <queue>

using namespace std;

/**
 * @class DeliveryMan
 * @brief Represents a delivery man with their ID, location, capacity, and list of orders.
 */
class DeliveryMan {
    private:
        int iDeliveryManID; // ID of the delivery man
        int iDeliveryManLocation; // Current location of the delivery man
        int iCapacity; // Capacity of the delivery man's vehicle
        int iQuantity; // Quantity of orders in the delivery man's list
        int iPrice; // Price of the delivery man's service
        DeliveryMan* next; // Pointer to the next delivery man in the list
    public:
        Order* oOrders; // Pointer to the first order in the delivery man's list
        
        /**
         * @brief Constructor for the DeliveryMan class
         * 
         * @param iDeliveryManID The ID of the delivery man
         * @param iDeliveryManLocation The current location of the delivery man
         * @param iCapacity The capacity of the delivery man's vehicle
         * @param next Pointer to the next delivery man in the list
         */
        DeliveryMan(int iDeliveryManID, int iDeliveryManLocation, int iCapacity, DeliveryMan* next);

        /**
         * @brief Destructor for the DeliveryMan class
         */
        ~DeliveryMan();
        
        /**
         * @brief Setter method for the DeliveryManID
         * 
         * @param newID The new ID of the delivery man
         */
        void setDeliveryManID(int newID){
            iDeliveryManID = iDeliveryManID;
        }

        /**
         * @brief Getter method for the DeliveryManID
         * 
         * @return The ID of the delivery man
         */
        int getDeliveryManID(){
            return iDeliveryManID;
        }

        /**
         * @brief Setter method for the DeliveryMan's location
         * 
         * @param newLocation The new location of the delivery man
         */
        void setLocation(int newLocation){
            iDeliveryManLocation = newLocation;
        }

        /**
         * @brief Getter method for the DeliveryMan's location
         * 
         * @return The current location of the delivery man
         */
        int getLocation(){
            return iDeliveryManLocation;
        }

        /**
         * @brief Setter method for the DeliveryMan's capacity
         * 
         * @param newCapacity The new capacity of the delivery man's vehicle
         */
        void setCapacity(int newCapacity){
            iCapacity = newCapacity;
        }

        /**
         * @brief Getter method for the DeliveryMan's capacity
         * 
         * @return The capacity of the delivery man's vehicle
         */
        int getCapacity(){
            return iCapacity;
        }

        /**
         * @brief Getter method for the DeliveryMan's quantity
         * 
         * @return The quantity of orders in the delivery man's list
         */
        int getQuantity(){
            return iQuantity;
        }
        
        /**
         * @brief Getter method for the DeliveryMan's price
         * 
         * @return The price of the delivery man's service
         */
        int getPrice(){
            return iPrice;
        }
        
        /**
         * @brief Setter method for the next DeliveryMan in the list
         * 
         * @param newNext Pointer to the next delivery man in the list
         */
        void setNext(DeliveryMan* newNext){
            next = newNext;
        }
        DeliveryMan* getNext(){
            return next;
        }

        /**
         * @brief Getter method for the next DeliveryMan in the list
         * 
         * @return Pointer to the next delivery man in the list
         */
        DeliveryMan* getNext();

        /**
         * @brief Method to add an order to the DeliveryMan's list
         * 
         * @param oOrder Pointer to the order to be added
         */
        void addOrder(Order* oOrder);

        /**
         * @brief Method to remove a order
         * 
         * @param iOrderNumber The order number to be marked as delivered
         */
        void orderDelivered(int iOrderNumber);
};
