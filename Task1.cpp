#include "Map.h"
#include "Heap.h"

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

Map* generateMapQ1() {
    Map* map = new Map(16);
    
    map->addEdge(0,1, 61);
    map->addEdge(0,4, 98);
    map->addEdge(1,2, 114);
    map->addEdge(1,5, 115);
    map->addEdge(2,3, 93);
    map->addEdge(2,6, 87);
    map->addEdge(3,7, 107);
    map->addEdge(4,5, 105);
    map->addEdge(4,8, 128);
    map->addEdge(5,6, 70);
    map->addEdge(5,9, 74);
    map->addEdge(6,7, 103);
    map->addEdge(6,10, 115);
    map->addEdge(7,11, 116);
    map->addEdge(8,9, 127);
    map->addEdge(8,12, 96);
    map->addEdge(9,10, 97);
    map->addEdge(9,13, 116);
    map->addEdge(10,11, 99);
    map->addEdge(10,14, 104);
    map->addEdge(11,15, 95);
    map->addEdge(12,13, 123);
    map->addEdge(13,14, 63);
    map->addEdge(14,15, 127);

    map->addDeliveryMan(1, 5, 10);
    map->addDeliveryMan(2, 12, 10);
    map->addDeliveryMan(2, 15, 10);

    map->addSeller(1, 7);

    return map;
}

int main() {

    
    Map* map = generateMapQ1();
    // map->print();

    ReturnNearestDMen nearDMen = *map->nearestDMen(1, 1);
    cout << "Nearest Deliverymen is in vertex: " << map->deliveryManInMap[nearDMen.nearDMen[0]].getLocation() << endl;

    return 0;
}
