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
        int numVertices; // Number of vertices in the map
        int numEdges; // Number of edges in the map
        int numDeliveryMan; // Number of deliverymen in the map
        int numWarehouse; // Number of warehouses in the map
        int numSeller; // Number of sellers in the map

    public:
        vector<DeliveryMan*> deliveryManList; // List of deliverymen at each vertex
        vector<Warehouse*> warehouseList; // List of warehouses at each vertex
        vector<Seller*> sellerList; // List of sellers at each vertex
        vector<EdgeNode*> edgesList; // Adjacency list representing the edges between vertices
        
        // Constructor initializes the Map with a given number of vertices
        Map(int numVertices);

        // Destructor to clean up dynamically allocated memory
        ~Map();

        // Getter functions to retrieve the number of vertices, edges, deliverymen, warehouses, and sellers
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

        // Method to add a new DeliveryMan to the Map
        void addDeliveryMan(int iDeliveryManID, int iDeliveryManLocation,int iCapacity, int iQuantity);

        // Method to add a new Warehouse to the Map
        void addWarehouse(int iWarehouseID, int iWarehouseLocation);

        // Method to add a new Seller to the Map
        void addSeller(int iSellerID, int iSellerLocation);

        // Method to add a new edge between two vertices in the Map
        void addEdge(int v1, int v2, int distance);

        // Method to remove an edge between two vertices in the Map
        void removeEdge(int v1, int v2);
        
        // Method to check if there is an edge between two vertices in the Map
        bool hasEdge(int v1, int v2);

        // Method to check if a DeliveryMan with the given ID and location exists in the Map
        bool hasDeliveryMan(int iDeliveryManID, int iDeliveryManLocation);

        // Method to check if a Warehouse with the given ID and location exists in the Map
        bool hasWarehouse(int iWarehouseID, int iWarehouseLocation);

        // Method to check if a Seller with the given ID and location exists in the Map
        bool hasSeller(int iSellerID, int iSellerLocation);

        // Method to print the adjacency list representation of the Map
        void print();

        // Method to check if the current Map is a subgraph of another Map
        bool isSubGraph(Map &otherMap);

        ReturnDijkstra cptDijkstra(int v0);

        vector<int> nearestDMen(int origin, int numDMen);   
};

