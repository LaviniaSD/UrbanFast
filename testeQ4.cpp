#include "Map.h"
#include "Order.h"
#include "Deliveryman.h"
#include <iostream>

using namespace std;

int main(){
    cout<<"Testando a funcao FindRoute"<<endl;

    // Generate map
    Map* map = generateMapQ4();
    Map mapClass = *map;

    //Generate a route
    vector<int> route = {0, 1, 2, 3, 4, 5, 6, 7};

    // Generate deliveryman
    DeliveryMan deliveryman = DeliveryMan(0, 0, 10, nullptr);

    // Generate a orders array
    vector<Order> order = {Order(0, 5, 1, 0), Order(1, 5, 1, 0), Order(2, 5, 1, 0), Order(3, 5, 1, 0), Order(4, 5, 1, 0), Order(5, 5, 1, 0), Order(6, 5, 1, 0), Order(7, 5, 1, 0)};

    // Generate a route
    ReturnDijkstra rd;

    rd = mapClass.FindRoute(order, deliveryman);
    cout << rd.minDistance << endl;

}