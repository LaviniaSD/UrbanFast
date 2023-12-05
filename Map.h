// GraphAdjList.h

#ifndef GRAPHADJLIST_H
#define GRAPHADJLIST_H

#include "StreetIntersection.h"

class GraphAdjList {
private:
    int m_numVertices;
    int m_numEdges;
    EdgeNode **m_edges;

public:
    GraphAdjList(int numVertices);
    ~GraphAdjList();

    void addEdge(int v1, int v2, int distance, WareHouse *warehouse, DeliveryMan *deliveryMan);
    void removeEdge(int v1, int v2);

    void print();

    EdgeNode** edges();

    void setNumVertices(int numVertices);
    int getNumVertices();

    void setNumEdges(int numEdges);
    int getNumEdges();

    void setEdges(EdgeNode **edges);
    EdgeNode** getEdges();
    
};

#endif
