// Class Seller

#ifndef SELLER_H
#define SELLER_H

class Seller {
    private:
        int iSellerID;
        int iItems;
        int iQuantity;
        int SellerLocation;

    public:
        Seller(int iSellerID, int iItems, int SellerLocation);

        void setSellerID(int iSellerID);
        int getSellerID();

        void setItems(int iItems);
        int getItems();

        void setQuantity(int iQuantity);
        int getQuantity();

        void setSellerLocation(int SellerLocation);
        int getSellerLocation();

};


#endif
