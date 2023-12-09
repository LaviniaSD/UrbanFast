#include "Map.h"
#include "Order.h"
#include "DeliveryMan.h"

#include<iostream>
using namespace::std;
int main(){
    Map* map = generateMapQ1();
    cout <<"OLA"<< endl;
    Order pedido(0,5,1,0); //numeor do pedido:0; Local de entrega vert 5; vendedor 1; typo 0;
    pedido.addProducts(0,1,2,1);
    pedido.addProducts(1,1,2,1);
    cout << "OI" << endl;
    ReturnFindRoutOpt* result =  map->FindRouteOpt(pedido);
    cout << "OLA" << endl;
    cout<< "Rota: ";
    int current = result->nearestDMan->getLocation();
    cout << current << endl;
    while (result->parents[current] != current){
        cout << current << "<- ";
        current = result->parents[current];
    }
    cout << current << endl;

    return 0;
}