// Class Seller

#pragma once

class Seller {
    private:
        int iSellerID;
        int iItems[100];
        int SellerLocation;
        Seller* next;

    public:
        Seller(int iSellerID, int SellerLocation);

        void setSellerID(int iSellerID){
            iSellerID = iSellerID;
        }
        int getSellerID(){
            return iSellerID;
        }

        void setItems(int newItem){
            iItems[newItem]++;
        }
        int* getItems(){
            return iItems;
        }

        void setSellerLocation(int SellerLocation){
            SellerLocation = SellerLocation;
        }
        int getSellerLocation(){
            return SellerLocation;
        }

        void setNext(Seller* newNext){
            next = newNext;
        }

        Seller* getNext(){
            return next;
        }

        void removeItem(int removeItem);

};
