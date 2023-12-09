#include "Map.h"
#include "Order.h"
#include "Deliveryman.h"
#include <iostream>

using namespace std;

int main(){
    cout<<"Testando a funcao FindRoute"<<endl;

    // Generate map
    Map* map = generateMapQ1();
    Map mapClass = *map;

    //Generate a order
    Order order(0, 5, 1, 0);

    // Generate deliveryman
    DeliveryMan deliveryman = DeliveryMan(0, 0, 10, nullptr);

    // Generate a route
    ReturnDijkstra rd;

    rd = mapClass.FindRoute(order, deliveryman);
    cout << rd.minDistance << endl;

}