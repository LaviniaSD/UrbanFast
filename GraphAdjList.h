// GraphAdjList.h

#ifndef GRAPHADJLIST_H
#define GRAPHADJLIST_H

#include "EdgeNode.h"

class GraphAdjList {
private:
    int m_numVertices;
    int m_numEdges;
    EdgeNode **m_edges;

public:
    GraphAdjList(int numVertices);
    ~GraphAdjList();

    void addEdge(int v1, int v2, int , int time);
    void removeEdge(int v1, int v2);
    void print();
    EdgeNode** edges();
    bool isSubGraph(GraphAdjList &h);
    bool isTopological();
    int getV();
    EdgeNode** getE();
    EdgeNode* getAdj(int vertex);
};

#endif
