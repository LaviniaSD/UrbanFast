// GraphAdjList.h

#pragma once
#include <iostream>
#include <vector>
#include "EdgeNode.h"

using namespace std;

class Map {
    private:
        int numVertices;
        int numEdges;

    public:
        vector<EdgeNode*> edges;
        
        Map(int numVertices);
        ~Map();

        void addEdge(int v1, int v2, int distance);

        void removeEdge(int v1, int v2);
        
        bool hasEdge(int v1, int v2);

        void print();

        bool isSubGraph(Map &otherMap);
        
        bool isTopological();
};

