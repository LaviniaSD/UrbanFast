/**
 * @file Map.h
 * @brief Header file for the Map class.
 * 
 * This file contains the declaration of the Map class, which represents a city map as a graph.
 * The class provides methods to add and remove deliverymen, warehouses, and sellers, as well as to add and remove edges between vertices.
 * It also includes methods to check the existence of deliverymen, warehouses, and sellers, and to print the adjacency list representation of the map.
 * Additionally, it provides a method to check if the current map is a subgraph of another map.
 * The class also includes methods to perform Dijkstra's algorithm and find the nearest deliverymen.
*/ 

#pragma once
#include <iostream>
#include <vector>
#include "EdgeNode.h"
#include "DeliveryMan.h"
#include "Warehouse.h"
#include "Seller.h"

using namespace std;
struct ReturnFindRoutOpt {
    int* distanceTotal; // Distância total da rota otimizada
    vector<int> routeMin; // Rota mínima otimizada
    DeliveryMan* nearestDMan; // Entregador mais próximo
};

struct ReturnMstPRIM {
    int* distances;
    int* parents;
};

struct OrderAgregation {
    int iIDNumber;
    int iWeight;
    int iPrice;
};

/**
 * @brief Struct that represents the return values of Dijkstra's algorithm.
 * 
 * This struct contains three integer arrays: distances, parents, and minDistance.
 * - distances: an array that stores the shortest distances from the source vertex to each vertex in the graph.
 * - parents: an array that stores the parent vertex of each vertex in the shortest path tree.
 * - minDistance: an array that stores the minimum distance from the source vertex to each vertex in the graph.
 */
struct ReturnDijkstra{
    int* distances;
    int* parents;
    int minDistance;
};

/**
 * @brief Struct that represents the return value of a function that finds the nearest D men.
 * 
 * This struct contains two arrays: distances and parents, and a vector of integers nearDMen.
 * The distances array stores the distances from the source to each vertex in the graph.
 * The parents array stores the parent vertex of each vertex in the shortest path tree.
 * The nearDMen vector stores the indices of the nearest deliverymen found, in crescent distance order. Use these indices in map.deliveryManInMap.
 */
struct ReturnNearestDMen {
    int* distances;
    int* parents;
    vector<int> nearDMen;
};

/**
 * @brief Class representing a city map as a graph, through an adjacency list.
 * 
 * This class stores information about a map, including the number of vertices, edges, deliverymen, warehouses, and sellers.
 * It also provides methods to add and remove deliverymen, warehouses, and sellers, as well as to add and remove edges between vertices.
 * The class also includes methods to check the existence of deliverymen, warehouses, and sellers, and to print the adjacency list representation of the map.
 * Additionally, it provides a method to check if the current map is a subgraph of another map.
 */
class Map {
    private:
        int numVertices; // Number of vertices in the map
        int numEdges; // Number of edges in the map
        int numDeliveryMan; // Number of deliverymen in the map
        int numWarehouse; // Number of warehouses in the map
        int numSeller; // Number of sellers in the map

    public:
        
        vector<DeliveryMan> deliveryManInMap; // Vector of deliverymen 
        vector<Warehouse> warehouseInMap; // Vector of warehouses 
        vector<Seller> sellerInMap; // Vector of sellers 

        vector<DeliveryMan*> deliveryManList; // List of deliverymen at each vertex
        vector<Warehouse*> warehouseList; // List of warehouses at each vertex
        vector<Seller*> sellerList; // List of sellers at each vertex
        vector<EdgeNode*> edgesList; // Adjacency list representing the edges between vertices
        
        /**
         * @brief Constructor for the Map class.
         * 
         * @param numVertices The number of vertices in the map.
         */
        Map(int numVertices);

        /**
         * @brief Destructor for the Map class.
         * 
         * This destructor cleans up dynamically allocated memory.
         */
        ~Map();

        /**
         * @brief Getter function to retrieve the number of vertices in the map.
         * 
         * @return The number of vertices in the map.
         */
        int getNumVertices(){
            return numVertices;
        }

        /**
         * @brief Getter function to retrieve the number of edges in the map.
         * 
         * @return The number of edges in the map.
         */
        int getNumEdges(){
            return numEdges;
        }

        /**
         * @brief Getter function to retrieve the number of deliverymen in the map.
         * 
         * @return The number of deliverymen in the map.
         */
        int getNumDeliveryMan(){
            return numDeliveryMan;
        }

        /**
         * @brief Getter function to retrieve the number of warehouses in the map.
         * 
         * @return The number of warehouses in the map.
         */
        int getNumWarehouse(){
            return numWarehouse;
        }

        /**
         * @brief Getter function to retrieve the number of sellers in the map.
         * 
         * @return The number of sellers in the map.
         */
        int getNumSeller(){
            return numSeller;
        }

        /**
         * @brief Method to add a new DeliveryMan to the Map.
         * 
         * @param iDeliveryManID The ID of the deliveryman.
         * @param iDeliveryManLocation The vertice location of the deliveryman.
         * @param iCapacity The weight capacity of the deliveryman.
         */
        void addDeliveryMan(int iDeliveryManID, int iDeliveryManLocation,int iCapacity);

        /**
         * @brief Method to add a new Warehouse to the Map.
         * 
         * @param iWarehouseID The ID of the warehouse.
         * @param iWarehouseLocation The location of the warehouse.
         */
        void addWarehouse(int iWarehouseID, int iWarehouseLocation);

        /**
         * @brief Method to add a new Seller to the Map.
         * 
         * @param iSellerID The ID of the seller.
         * @param iSellerLocation The location of the seller.
         */
        void addSeller(int iSellerID, int iSellerLocation);

        /**
         * @brief Method to add a new edge between two vertices in the Map.
         * 
         * @param v1 The first vertex.
         * @param v2 The second vertex.
         * @param distance The distance between the two vertices.
         */
        void addEdge(int v1, int v2, int distance);

        /**
         * @brief Method to remove an edge between two vertices in the Map.
         * 
         * @param v1 The first vertex.
         * @param v2 The second vertex.
         */
        void removeEdge(int v1, int v2);
        
        /**
         * @brief Method to check if there is an edge between two vertices in the Map.
         * 
         * @param v1 The first vertex.
         * @param v2 The second vertex.
         * @return True if there is an edge between the two vertices, false otherwise.
         */
        bool hasEdge(int v1, int v2);

        /**
         * @brief Method to check if a DeliveryMan with the given ID and location exists in the Map.
         * 
         * @param iDeliveryManID The ID of the deliveryman.
         * @param iDeliveryManLocation The location of the deliveryman.
         * @return True if the deliveryman exists, false otherwise.
         */
        bool hasDeliveryMan(int iDeliveryManID, int iDeliveryManLocation);

        /**
         * @brief Method to check if a Warehouse with the given ID and location exists in the Map.
         * 
         * @param iWarehouseID The ID of the warehouse.
         * @param iWarehouseLocation The location of the warehouse.
         * @return True if the warehouse exists, false otherwise.
         */
        bool hasWarehouse(int iWarehouseID, int iWarehouseLocation);

        /**
         * @brief Method to check if a Seller with the given ID and location exists in the Map.
         * 
         * @param iSellerID The ID of the seller.
         * @param iSellerLocation The location of the seller.
         * @return True if the seller exists, false otherwise.
         */
        bool hasSeller(int iSellerID, int iSellerLocation);

        /**
         * @brief Method to print the adjacency list representation of the Map.
         */
        void print();

        /**
         * @brief Method to perform Dijkstra's algorithm starting from a given vertex.
         * 
         * @param v0 The starting vertex.
         * @return The result of Dijkstra's algorithm.
         */
        ReturnDijkstra cptDijkstra(int v0);

        /**
         * @brief Method to find the nearest deliverymen from a given origin.
         * 
         * @param origin The origin vertex.
         * @param numDMen The number of deliverymen to find.
         * @return The result of finding the nearest deliverymen.
         */
        ReturnNearestDMen* nearestDMen(int origin, int numDMen);   

        /**
         * @brief Method to find the best route to an order.
         * 
         * @param order The order to be delivered.
         * @param deliveryman The deliveryman to assign the order to.
         * @return The result of finding the route.
         */
        ReturnDijkstra FindRoute(Order order, DeliveryMan deliveryman);

        // Additional method initialize to PRIM
        void initializePRIM(int origin, int* parent, bool* inTree,int* verticeCost);

        // Get the path by parrent array
        vector<int> getPathParent(int* parent, int origin, int start);

        // Additional method to create a MST 
        ReturnMstPRIM* mstPrim(int origin, int* parent);
        
        // Additional method to find the optimized route
        ReturnFindRoutOpt* FindRouteOpt(Order order);

        // DFS algorithm for finding warehouses and sellers near the route
        vector<int> DFS(vector<int> route, int maxDistance);

        // Function to check which orders can be delivered in the neighborhood of the route
        vector<Order> checkNeighborhood(vector<Order> orders, vector<int> warehousesAndSellers);

        // Function to agregate the weight and value of the items in a order
        OrderAgregation agregateOrder(Order order);

        // Auxiliar function to knapsack
        int knapSackMax(int i, vector<OrderAgregation>& orders, vector<vector<int>>& dp, int iCapacity);

        // Main function to knapsack
        vector<int> knapSack(vector<OrderAgregation> orders, int iCapacity);

        // Select the orders to be delivered based on the knapsack algorithm
        vector<int> selectedOrders(vector<OrderAgregation>& orders, vector<vector<int>>& dp, int iCapacity);

        // Function to order the suggestions
        vector<int> OrderSuggestions(vector<int> route, vector<Order> orders, int maxDistance, DeliveryMan deliveryman);
};
