// Class Customer

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer {
    private:
        int iCustomerID;
        int iLocation;

    public:
        Customer(int iCustomerID, int iLocation):iCustomerID(iCustomerID),iLocation(iLocation){}

        void setCustomerID(int iCustomerID){}
        int getCustomerID(){
            return iCustomerID;
        }

        void setLocation(int iLocation){}
        int getLocation(){
            return iLocation;
        }


};

#endif
