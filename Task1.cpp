#include "Map.h"
#include "Heap.h"

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> Map::nearestDMen(int origin, int numDMen) {
    // First, get the CPT
    ReturnDijkstra dijkstra = cptDijkstra(origin);
    
    // Then, define the vector to return
    int maxSize;
    if (getNumDeliveryMan() < numDMen) {
        maxSize = getNumDeliveryMan();
    } else {
        maxSize = numDMen;
    }
    vector<int> nearestDMen(maxSize);

    // Now, get the n-nearest Deliverymen with a heap (n = maxSize)
    Heap heap(1);
    for (int i=0; i<getNumDeliveryMan(); i++) {
        int dManLoc = deliveryManList[i]->getLocation();

        if (heap.getSize() < numDMen) {
            heap.push(i, dijkstra.distances[dManLoc]);
        } else {
            if (heap.getTop().value > dijkstra.distances[dManLoc]) {
                heap.replace(i, dijkstra.distances[dManLoc]);
            }
        }
    }

    // Finally, add the n-nearest Deliverymen to the vector in the correct order
    for (int i=0; i<maxSize; i++) {
        nearestDMen[i] = heap.getTop().id;
        heap.pop();
    }

    return nearestDMen;
}

Map* generateMapQ1() {
    Map* map = new Map(16);
    
    map->addEdge(1,2, 61);
    map->addEdge(1,5, 98);
    map->addEdge(2,3, 114);
    map->addEdge(2,6, 115);
    map->addEdge(3,4, 93);
    map->addEdge(3,7, 87);
    map->addEdge(4,8, 107);
    map->addEdge(5,6, 105);
    map->addEdge(5,9, 128);
    map->addEdge(6,7, 70);
    map->addEdge(6,10, 74);
    map->addEdge(7,8, 103);
    map->addEdge(7,11, 115);
    map->addEdge(8,12, 116);
    map->addEdge(9,10, 127);
    map->addEdge(9,13, 96);
    map->addEdge(10,11, 97);
    map->addEdge(10,14, 116);
    map->addEdge(11,12, 99);
    map->addEdge(11,15, 104);
    map->addEdge(12,16, 95);
    map->addEdge(13,14, 123);
    map->addEdge(14,15, 63);
    map->addEdge(15,16, 127);

    map->addDeliveryMan(1, 5, 10, 0);
    map->addDeliveryMan(2, 5, 10, 0);

    return map;
}

int main() {
    cout << "oi";
    // mapa.print();

    return 0;
}
