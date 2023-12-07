#include "Map.h"

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> Map::nearestDMen(int origin, int numDMen) {
    ReturnDijkstra dijkstra = cptDijkstra(origin);

    if (getNumDeliveryMan() > numDMen) {
        vector<int> nearestDMen(getNumDeliveryMan());
    } else {
        vector<int> nearestDMen(numDMen);
    }
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

    mapa.print();

    return 0;
}
