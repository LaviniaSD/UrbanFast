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
        int getSellerID(){
            return iSellerID;
        }

        void setItems(int iItems);
        int getItems(){
            return iItems;
        }

        void setQuantity(int iQuantity);
        int getQuantity(){
            return iQuantity;
        }

        void setSellerLocation(int SellerLocation);
        int getSellerLocation(){
            return SellerLocation;
        }

};


#endif
