// GraphAdjList.h

#pragma once
#include <iostream>
#include <vector>
#include "EdgeNode.h"
#include "DeliveryMan.h"
#include "Warehouse.h"
#include "Seller.h"

using namespace std;

struct ReturnDijkstra{
    int* distances;
    int* parents;
    int* minDistance;
};

class Map {
    private:
        int numVertices;
        int numEdges;
        int numDeliveryMan;
        int numWarehouse;
        int numSeller;

    public:
        vector<DeliveryMan*> deliveryManList;
        vector<Warehouse*> warehouseList;
        vector<Seller*> sellerList;
        vector<EdgeNode*> edgesList;
        
        Map(int numVertices);
        ~Map();

        int getNumVertices(){
            return numVertices;
        }
        int getNumEdges(){
            return numEdges;
        }
        int getNumDeliveryMan(){
            return numDeliveryMan;
        }
        int getNumWarehouse(){
            return numWarehouse;

        }int getNumSeller(){
            return numSeller;
        }

        void addDeliveryMan(DeliveryMan* newDeliveryMan);

        void addWarehouse(Warehouse* newWarehouse);

        void addSeller(Seller* newSeller);

        void addEdge(int v1, int v2, int distance);

        void removeEdge(int v1, int v2);
        
        bool hasEdge(int v1, int v2);

        bool hasDeliveryMan(int vertice);

        bool hasWarehouse(int vertice);

        bool hasSeller(int vertice);

        void print();

        bool isSubGraph(Map &otherMap);
        
        bool isTopological();

        ReturnDijkstra cptDijkstra(int v0);


};

