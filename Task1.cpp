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

int main() {
    cout << "oi";

    Map mapa(6);
    
    mapa.addEdge(0, 1, 10);
    mapa.addEdge(0, 2, 20);
    mapa.addEdge(1, 3, 30);
    mapa.addEdge(1, 4, 20);
    mapa.addEdge(2, 4, 90);
    mapa.addEdge(3, 4, 100);
    mapa.addEdge(4, 1, 40);
    mapa.addEdge(4, 5, 60);

    // mapa.print();

    return 0;
}
