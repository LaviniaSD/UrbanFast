#include "Seller.h"

Seller::Seller(int iSellerID, int SellerLocation, Seller* next):
iSellerID(iSellerID),
SellerLocation(SellerLocation){
    for(int i=0; i<100;i++){
        iItems[i]=0;
    }
}

void Seller::removeItem(int removeItem){
    if(iItems[removeItem]==0){
        return;
    }
    else{
        iItems[removeItem]--;
    }
}