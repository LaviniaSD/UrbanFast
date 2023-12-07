#include "Warehouse.h"

Warehouse::Warehouse(int iWarehouseID, int iLocation, Warehouse* next):
iWarehouseID(iWarehouseID),
iLocation(iLocation),next(next){
    for(int i=0; i<100;i++){
        iItems[i]=0;
    }
}

void Warehouse::removeItem(int removeItem){
    if(iItems[removeItem]==0){
        return;
    }
    else{
        iItems[removeItem]--;
    }
}