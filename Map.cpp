// GraphAdjList.cpp
#include "Map.h"
#include "EdgeNode.h"
#include <iostream>

using namespace std;

Map::Map(int numVertices): numVertices(numVertices), numEdges(0),deliveryManList(numVertices),warehouseList(numVertices),sellerList(numVertices), edgesList(numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        edgesList[i] = nullptr;
    }
}

Map::~Map() {
    // Clean up the DeliveryMan list
    for (int i = 0; i < numVertices; ++i) {
        DeliveryMan* deliveryMan = deliveryManList[i];
        while (deliveryMan) {
            DeliveryMan* nextDeliveryMan = deliveryMan->getNext();
            delete deliveryMan;
            deliveryMan = nextDeliveryMan;
        }
    }

    // Clean up the Warehouse list
    for (int i = 0; i < numVertices; ++i) {
        Warehouse* warehouse = warehouseList[i];
        while (warehouse) {
            Warehouse* nextWarehouse = warehouse->getNext();
            delete warehouse;
            warehouse = nextWarehouse;
        }
    }

    // Clean up the Seller list
    for (int i = 0; i < numVertices; ++i) {
        Seller* seller = sellerList[i];
        while (seller) {
            Seller* nextSeller = seller->getNext();
            delete seller;
            seller = nextSeller;
        }
    }

    // Clean up the EdgeNode list
    for (int i = 0; i < numVertices; ++i) {
        EdgeNode* edge = edgesList[i];
        while (edge) {
            EdgeNode* nextEdge = edge->getNext();
            delete edge;
            edge = nextEdge;
        }
    }
}

void Map::addDeliveryMan(int iDeliveryManID, int iDeliveryManLocation, int iCapacity, int iQuantity) {
    // Adds a new DeliveryMan to the list
    DeliveryMan* newDeliveryMan = new DeliveryMan(iDeliveryManID, iDeliveryManLocation, iCapacity, iQuantity, nullptr);
    if(!deliveryManList[iDeliveryManLocation]){
        deliveryManList[iDeliveryManLocation] = newDeliveryMan;
    }
    else{
        newDeliveryMan->setNext(deliveryManList[iDeliveryManLocation]);
        deliveryManList[iDeliveryManLocation] = newDeliveryMan;
    }
    numDeliveryMan++;
}


void Map::addWarehouse(int iWarehouseID, int iWarehouseLocation) {
    // Adds a new Warehouse to the list
    Warehouse* newWarehouse = new Warehouse(iWarehouseID, iWarehouseLocation, nullptr);
    if(!warehouseList[iWarehouseLocation]){
        warehouseList[iWarehouseLocation] = newWarehouse;
    }
    else{
        newWarehouse->setNext(warehouseList[iWarehouseLocation]);
        warehouseList[iWarehouseLocation] = newWarehouse;
    }
    numWarehouse++;
}


void Map::addSeller(int iSellerID,int iSellerLocation) {
    // Adds a new Seller to the list
    Seller* newSeller = new Seller(iSellerID, iSellerLocation, nullptr);
    if(!sellerList[iSellerLocation]){
        sellerList[iSellerLocation] = newSeller;
    }
    else{
        newSeller->setNext(sellerList[iSellerLocation]);
        sellerList[iSellerLocation] = newSeller;
    }
    numSeller++;
}


void Map::addEdge(int v1, int v2, int distance) {
    // Adds one side of the edge
    EdgeNode* edge = edgesList[v1];
    if (!edge) edgesList[v1] = new EdgeNode(v1, v2, distance, nullptr);

    while (edge) {
        if (edge->getOtherVertex() == v2) {
            // If the edge already exists, update the distance
            edge->setDistance(distance);
            break;
        }
        if (edge->getNext() == nullptr) {
            // Add the new edge to the end of the list
            edge->setNext(new EdgeNode(v1, v2, distance, nullptr));
        }
        edge = edge->getNext();
    }

    // Does the same for the other side of the edge
    edge = edgesList[v2];
    if (!edge) edgesList[v2] = new EdgeNode(v2, v1, distance, nullptr);
    while (edge) {
        if (edge->getOtherVertex() == v1) {
            // If the edge already exists, update the distance
            edge->setDistance(distance);
            break;
        }
        if (edge->getNext() == nullptr) {
            // Add the new edge to the end of the list
            edge->setNext(new EdgeNode(v2, v1, distance, nullptr));
        }
        edge = edge->getNext();
    }
    numEdges++;
}

void Map::removeEdge(int v1, int v2) {
    // Removes one side of the edge
    EdgeNode* edge = edgesList[v1];
    EdgeNode* previousEdge = nullptr;
    
    while (edge) {
        if (edge->getOtherVertex() == v2) {
            if (previousEdge) {
                previousEdge->setNext(edge->getNext());
            } else {
                edgesList[v1] = edge->getNext();
            }
            
            delete edge;
            break;
        }

        previousEdge = edge;
        edge = edge->getNext();
    }

    // removes the other side of the edge
    edge = edgesList[v2];
    previousEdge = nullptr;
    
    while (edge) {
        if (edge->getOtherVertex() == v1) {
            if (previousEdge) {
                previousEdge->setNext(edge->getNext());
            } else {
                edgesList[v2] = edge->getNext();
            }
            
            delete edge;
            break;
        }

        previousEdge = edge;
        edge = edge->getNext();
    }
    numEdges--;
}

bool Map::hasEdge(int v1, int v2) {
    EdgeNode* edge = edgesList[v1];
    while(edge) {
        if (edge->getOtherVertex() == v2) return true;
        
        edge = edge->getNext();
    }
    return false;
}

// Checks if a DeliveryMan with the given ID and location exists in the Map
bool Map::hasDeliveryMan(int iDeliveryManID, int iDeliveryManLocation) {
    DeliveryMan* deliveryMan = deliveryManList[iDeliveryManLocation];

    while (deliveryMan) {
        if (deliveryMan->getDeliveryManID() == iDeliveryManID) {
            return true;  // Found a DeliveryMan with the specified ID and location
        }

        deliveryMan = deliveryMan->getNext();
    }

    return false; // DeliveryMan not found
}

// Checks if a Warehouse with the given ID and location exists in the Map
bool Map::hasWarehouse(int iWarehouseID, int iWarehouseLocation) {
    Warehouse* warehouse = warehouseList[iWarehouseLocation];

    while (warehouse) {
        if (warehouse->getWarehouseID() == iWarehouseID) {
            return true; // Found a Warehouse with the specified ID and location
        }

        warehouse = warehouse->getNext();
    }

    return false; // Warehouse not found
}

// Checks if a Seller with the given ID and location exists in the Map
bool Map::hasSeller(int iSellerID, int iSellerLocation) {
    Seller* seller = sellerList[iSellerLocation];

    while (seller) {
        if (seller->getSellerID() == iSellerID) {
            return true; // Found a Seller with the specified ID and location
        }

        seller = seller->getNext();
    }

    return false; // Seller not found
}

// Prints the adjacency list representation of the Map
void Map::print() {
    for (int i = 0; i < numVertices; ++i) {
        EdgeNode* edge = edgesList[i];
        cout << "Vertex " << i << ":";
        while (edge) {
            cout << " ("<< edge->getOtherVertex() << ", d = " << edge->getDistance() << ")";
            edge = edge->getNext();
        }
        cout << endl;
    }
}

// Checks if the current Map is a subgraph of the otherMap
bool Map::isSubGraph(Map & otherMap) {
    vector hEdges = otherMap.edgesList;

    for (int v1 = 0; v1 < numVertices; v1++) {
        EdgeNode* hEdge = hEdges[v1];

        while (hEdge) {
            int v2 = hEdge->getOtherVertex();
            if (!hasEdge(v1, v2)) return false;  // Edge not found in the current Map
             
            hEdge = hEdge->getNext();
        }
    }
    return true; // All edges in otherMap are found in the current Map
}
