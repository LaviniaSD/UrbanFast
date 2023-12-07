// Class Customer

#ifndef CUSTOMER_H
#define CUSTOMER_H

// Class representing a customer
class Customer {
    private:
        int iCustomerID;  // Unique identifier for the customer
        int iLocation; // Location of the customer

    public:
        // Constructor to initialize the customer with an ID and location
        Customer(int iCustomerID, int iLocation):iCustomerID(iCustomerID),iLocation(iLocation){}

        // Setter method to set the customer ID
        void setCustomerID(int iCustomerID){
            iCustomerID = iCustomerID;
        }

        // Getter method to retrieve the customer ID
        int getCustomerID(){
            return iCustomerID;
        }

        // Setter method to set the location of the customer
        void setLocation(int iLocation){
            iLocation = iLocation;
        }
        
        // Getter method to retrieve the location of the customer
        int getLocation(){
            return iLocation;
        }
};

#endif
