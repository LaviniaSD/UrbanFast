// GraphAdjList.cpp
#include "Map.h"
#include "EdgeNode.h"
#include <iostream>

using namespace std;

Map::Map(int numVertices): numVertices(numVertices), numEdges(0), edges(numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        edges[i] = nullptr;
    }
}

Map::~Map() {
    for (int i = 0; i < numVertices; ++i) {
        EdgeNode* edge = edges[i];
        while (edge) {
            EdgeNode* next = edge->getNext();
            delete edge;
            edge = next;
        }
    }
}

void Map::addEdge(int v1, int v2, int distance) {
    // Adds one side of the edge
    EdgeNode* edge = edges[v1];
    if (!edge) edges[v1] = new EdgeNode(v1, v2, distance, nullptr, nullptr, nullptr);

    while (edge) {
        if (edge->getOtherVertex() == v2) {
            // If the edge already exists, update the distance
            edge->setDistance(distance);
            break;
        }
        if (edge->getNext() == nullptr) {
            // Add the new edge to the end of the list
            edge->setNext(new EdgeNode(v1, v2, distance, nullptr, nullptr, nullptr));
        }
        edge = edge->getNext();
    }

    // Does the same for the other side of the edge
    edge = edges[v2];
    if (!edge) edges[v2] = new EdgeNode(v2, v1, distance, nullptr, nullptr, nullptr);
    while (edge) {
        if (edge->getOtherVertex() == v1) {
            // If the edge already exists, update the distance
            edge->setDistance(distance);
            break;
        }
        if (edge->getNext() == nullptr) {
            // Add the new edge to the end of the list
            edge->setNext(new EdgeNode(v2, v1, distance, nullptr, nullptr, nullptr));
        }
        edge = edge->getNext();
    }
    numEdges++;
}

void Map::removeEdge(int v1, int v2) {
    // Removes one side of the edge
    EdgeNode* edge = edges[v1];
    EdgeNode* previousEdge = nullptr;
    
    while (edge) {
        if (edge->getOtherVertex() == v2) {
            if (previousEdge) {
                previousEdge->setNext(edge->getNext());
            } else {
                edges[v1] = edge->getNext();
            }
            
            delete edge;
            break;
        }

        previousEdge = edge;
        edge = edge->getNext();
    }

    // removes the other side of the edge
    edge = edges[v2];
    previousEdge = nullptr;
    
    while (edge) {
        if (edge->getOtherVertex() == v1) {
            if (previousEdge) {
                previousEdge->setNext(edge->getNext());
            } else {
                edges[v2] = edge->getNext();
            }
            
            delete edge;
            break;
        }

        previousEdge = edge;
        edge = edge->getNext();
    }
}

bool Map::hasEdge(int v1, int v2) {
    EdgeNode* edge = edges[v1];
    while(edge) {
        if (edge->getOtherVertex() == v2) return true;
        
        edge = edge->getNext();
    }
    return false;
}

void Map::print() {
    for (int i = 0; i < numVertices; ++i) {
        EdgeNode* edge = edges[i];
        cout << "Vertex " << i << ":";
        while (edge) {
            cout << " ("<< edge->getOtherVertex() << ", d = " << edge->getDistance() << ")";
            edge = edge->getNext();
        }
        cout << endl;
    }
}

bool Map::isSubGraph(Map & otherMap) {
    vector hEdges = otherMap.edges;

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
