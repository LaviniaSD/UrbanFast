// Class Customer

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
    private:
        int iCustomerID;
        int iLocation;

    public:
        Customer(int iCustomerID, int iLocation);

        void setCustomerID(int iCustomerID);
        int getCustomerID();

        void setLocation(int iLocation);
        int getLocation();


};

#endif
