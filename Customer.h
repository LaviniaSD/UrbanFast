/**
 * @file Customer.h
 * @brief Header file for the Customer class.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

/**
 * @class Customer
 * @brief Class representing a customer.
 * 
 * This class stores information about a customer, including their unique identifier and location.
 */
class Customer {
    private:
        int iCustomerID;  // Unique identifier for the customer
        int iLocation; // Location of the customer

    public:
        /**
         * @brief Constructor to initialize the customer with an ID and location.
         * 
         * @param iCustomerID The unique identifier for the customer.
         * @param iLocation The location of the customer.
         */
        Customer(int iCustomerID, int iLocation):iCustomerID(iCustomerID),iLocation(iLocation){}

        /**
         * @brief Setter method to set the customer ID.
         * 
         * @param iCustomerID The customer ID to be set.
         */
        void setCustomerID(int iCustomerID){
            iCustomerID = iCustomerID;
        }

        /**
         * @brief Getter method to retrieve the customer ID.
         * 
         * @return int The customer ID.
         */
        int getCustomerID(){
            return iCustomerID;
        }

        /**
         * @brief Setter method to set the location of the customer.
         * 
         * @param iLocation The location to be set.
         */
        void setLocation(int iLocation){
            iLocation = iLocation;
        }
        
        /**
         * @brief Getter method to retrieve the location of the customer.
         * 
         * @return int The location of the customer.
         */
        int getLocation(){
            return iLocation;
        }
};

#endif
