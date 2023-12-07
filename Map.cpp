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
    for (int i = 0; i < numVertices; ++i) {
        EdgeNode* edge = edgesList[i];
        while (edge) {
            EdgeNode* next = edge->getNext();
            delete edge;
            edge = next;
        }
    }
}

void Map::addDeliveryMan(DeliveryMan* newDeliveryMan) {
    DeliveryMan* vertice = deliveryManList[newDeliveryMan->getLocation()];
    if(vertice!=nullptr){
        while(vertice->getNext()!=nullptr){
            vertice = vertice->getNext();
        }
        vertice->setNext(newDeliveryMan);
    }
    else{
        deliveryManList[newDeliveryMan->getLocation()] = newDeliveryMan;
    }
    numDeliveryMan++;
}

void Map::addWarehouse(Warehouse* newWarehouse) {
    Warehouse* vertice = warehouseList[newWarehouse->getLocation()];
    if(vertice!=nullptr){
        while(vertice->getNext()!=nullptr){
            vertice = vertice->getNext();
        }
        vertice->setNext(newWarehouse);
    }
    else{
        warehouseList[newWarehouse->getLocation()] = newWarehouse;
    }
    numWarehouse++;
}

void Map::addSeller(Seller* newSeller) {
    Seller* vertice = sellerList[newSeller->getSellerLocation()];
    if(vertice!=nullptr){
        while(vertice->getNext()!=nullptr){
            vertice = vertice->getNext();
        }
        vertice->setNext(newSeller);
    }
    else{
        sellerList[newSeller->getSellerLocation()] = newSeller;
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

bool Map::isSubGraph(Map & otherMap) {
    vector hEdges = otherMap.edgesList;

    for (int v1 = 0; v1 < numVertices; v1++) {
        EdgeNode* hEdge = hEdges[v1];

        while (hEdge) {
            int v2 = hEdge->getOtherVertex();
            if (!hasEdge(v1, v2)) return false;
            
            hEdge = hEdge->getNext();
        }
    }
    return true;
}
