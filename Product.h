// Class Product

#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
    private:
        int iProductNumber;
        int iPrice;
        bool bInWarehouse;
        int iSellerID;
        int iLocation;
        int iQuantity;

    public:
        Product(int iProductNumber, int iPrice, bool bInWarehouse, int iSellerID, int iLocation, int iQuantity);

        void setProductNumber(int iProductNumber);
        int getProductNumber(){
            return iProductNumber;
        }

        void setPrice(int iPrice);
        int getPrice(){
            return iPrice;
        }

        void setInWarehouse(bool bInWarehouse);
        bool getInWarehouse(){
            return bInWarehouse;
        }

        void setSellerID(int iSellerID);
        int getSellerID(){
            return iSellerID;
        }

        void setLocation(int iLocation);
        int getLocation(){
            return iLocation;
        }

        void setQuantity(int iQuantity);
        int getQuantity(){
            return iQuantity; 
        }
};

#endif
