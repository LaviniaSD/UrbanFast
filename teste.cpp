#include "Map.h"
#include "Order.h"

#include<iostream>
using namespace::std;
int main(){
    Map* map = generateMapQ1();
    Map mapClass = *map;

    Order pedido(0,15,0,true);

    cout<< "OI"<< endl;
    cout<< "AAAAAAAH"<<endl;
    ReturnFindRoutOpt* result =  mapClass.FindRouteOpt(pedido);
    cout << "OLA" << endl;


    return 0;
}