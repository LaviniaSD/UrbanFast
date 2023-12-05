// Class Product

#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
    private:
        int iProductNumber;
        int iPrice;
        bool bInWarehouse;
        int iSallerID;
        int iLocation;
        int iQuantity;

    public:
        Product(int iProductNumber, int iPrice, bool bInWarehouse, int iSallerID, int iLocation, int iQuantity);

        void setProductNumber(int iProductNumber);
        int getProductNumber();

        void setPrice(int iPrice);
        int getPrice();

        void setInWarehouse(bool bInWarehouse);
        bool getInWarehouse();

        void setSallerID(int iSallerID);
        int getSallerID();

        void setLocation(int iLocation);
        int getLocation();

        void setQuantity(int iQuantity);
        int getQuantity();
};

#endif
