#include "Map.h"
#include "Order.h"

#include<iostream>
using namespace::std;
int main(){
    Map* map = generateMapQ2();
    Map mapClass = *map;

    Order pedido(0,15,0,true);
    pedido.addProducts(0,1,2,1);
    pedido.addProducts(1,1,2,1);
    cout<< "Id do produto add: "<< pedido.pProducts[0].getProductID()<< endl;

    cout<< "AAAAAAAH"<<endl;
    ReturnFindRoutOpt* result =  mapClass.FindRouteOpt(&pedido);
    cout << "OLA" << endl;
    int current = result->nearestDMan->getLocation();
    cout << current << endl;
    while (result->parents[current] != current){
        cout << current << "<- ";
        current = result->parents[current];
    }
    cout << current << endl;



    return 0;
}