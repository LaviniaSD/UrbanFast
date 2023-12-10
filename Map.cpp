/**
 * @file Map.cpp
 * @brief Implementation file for the Map class.
 */

#include "Map.h"
#include "EdgeNode.h"
#include "limits.h"
#include "DeliveryMan.h"
#include "Heap.h"
#include "Order.h"

#include <iostream>
#include <vector>

using namespace std;

Map::Map(const int numVertices): 
numVertices(numVertices), 
numEdges(0),
numDeliveryMan(0),
numWarehouse(0),
numSeller(0),
deliveryManList(numVertices),
warehouseList(numVertices),
sellerList(numVertices), 
edgesList(numVertices) {
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

void Map::addDeliveryMan(int iDeliveryManID, int iDeliveryManLocation, int iCapacity) {
    // Adds a new DeliveryMan to the list
    DeliveryMan* newDeliveryMan = new DeliveryMan(iDeliveryManID, iDeliveryManLocation, iCapacity, nullptr);
    if(deliveryManList[iDeliveryManLocation]==nullptr){
        deliveryManList[iDeliveryManLocation] = newDeliveryMan;
    }
    else{
        newDeliveryMan->setNext(deliveryManList[iDeliveryManLocation]);
        deliveryManList[iDeliveryManLocation] = newDeliveryMan;
    }
    // Adds a new DeliveryMan to the vector
    deliveryManInMap.push_back(*newDeliveryMan);
    numDeliveryMan++;
}

void Map::addDeliveryMan(DeliveryMan* newDeliveryMan) {
    // Adds a new DeliveryMan to the list
    if(deliveryManList[newDeliveryMan->getLocation()]==nullptr){
        deliveryManList[newDeliveryMan->getLocation()] = newDeliveryMan;
    }
    else{
        newDeliveryMan->setNext(deliveryManList[newDeliveryMan->getLocation()]);
        deliveryManList[newDeliveryMan->getLocation()] = newDeliveryMan;
    }
    // Adds a new DeliveryMan to the vector
    deliveryManInMap.push_back(*newDeliveryMan);
    numDeliveryMan++;
}



void Map::addWarehouse(int iWarehouseID, int iWarehouseLocation) {
    // Adds a new Warehouse to the list
    Warehouse* newWarehouse = new Warehouse(iWarehouseID, iWarehouseLocation, nullptr);
    if(warehouseList[iWarehouseLocation]==nullptr){
        warehouseList[iWarehouseLocation] = newWarehouse;
    }
    else{
        newWarehouse->setNext(warehouseList[iWarehouseLocation]);
        warehouseList[iWarehouseLocation] = newWarehouse;
    }
    // Adds a new Warehouse to the vector
    warehouseInMap.push_back(*newWarehouse);
    numWarehouse++;
}

void Map::addWarehouse(Warehouse* newWarehouse) {
    // Adds a new Warehouse to the list
    if(warehouseList[newWarehouse->getWarehouseLocation()]==nullptr){
        warehouseList[newWarehouse->getWarehouseLocation()] = newWarehouse;
    }
    else{
        newWarehouse->setNext(warehouseList[newWarehouse->getWarehouseLocation()]);
        warehouseList[newWarehouse->getWarehouseLocation()] = newWarehouse;
    }
    // Adds a new Warehouse to the vector
    warehouseInMap.push_back(*newWarehouse);
    numWarehouse++;
}


void Map::addSeller(int iSellerID,int iSellerLocation) {
    // Adds a new Seller to the list
    Seller* newSeller = new Seller(iSellerID, iSellerLocation, nullptr);
    if(sellerList[iSellerLocation]==nullptr){
        sellerList[iSellerLocation] = newSeller;
    }
    else{
        newSeller->setNext(sellerList[iSellerLocation]);
        sellerList[iSellerLocation] = newSeller;
    }
    // Adds a new Seller to the vector
    sellerInMap.push_back(*newSeller);
    numSeller++;
}

void Map::addSeller(Seller* newSeller) {
    // Adds a new Seller to the list
    if(sellerList[newSeller->getSellerLocation()]==nullptr){
        sellerList[newSeller->getSellerLocation()] = newSeller;
    }
    else{
        newSeller->setNext(sellerList[newSeller->getSellerLocation()]);
        sellerList[newSeller->getSellerLocation()] = newSeller;
    }
    // Adds a new Seller to the vector
    sellerInMap.push_back(*newSeller);
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
    std::vector<EdgeNode*> hEdges = otherMap.edgesList;

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

ReturnDijkstra Map::cptDijkstra(int v0) {
    // Inicializa os vetores de distâncias, pais e visitados
    int V = getNumVertices();
    int* distances = new int[V];
    int* parents = new int[V];
    bool* visited = new bool[V];

    for(int i = 0; i < V; i++){
        distances[i] = INT_MAX;
        parents[i] = -1;
        visited[i] = false;
    }

    // Define a distância do vértice inicial como 0 e o pai como ele mesmo
    distances[v0] = 0;
    parents[v0] = v0;

    // Cria a fila de prioridade
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(0, v0));

    // Enquanto a fila não estiver vazia
    while(!heap.empty()){
    
        // Pega o vértice com menor distância
        int v1 = heap.top().second;
        heap.pop();

        // Se a distância for infinita, não há caminho
        if(distances[v1] == INT_MAX){
            break;
        }

        // Para cada vértice adjacente
        EdgeNode* node = edgesList[v1];
        while (node != nullptr) {
            // Pega o vértice adjacente
            int v2 = node->getOtherVertex();

            // Se o vértice não foi visitado
            if (!visited[v2]){
                // Pega a distância entre os vértices
                int distance = node->getDistance();

                // Se a distância do vértice atual + a distância entre os vértices for menor que a distância do vértice adjacente
                if (distances[v1] + distance < distances[v2]){
                    // Atualiza a distância do vértice adjacente
                    distances[v2] = distances[v1] + distance;
                    // Atualiza o pai do vértice adjacente
                    parents[v2] = v1;
                    // Adiciona o vértice adjacente à fila de prioridade
                    heap.push(make_pair(distances[v2], v2));
                }

            }
            // Pega o próximo vértice adjacente
            node = node->getNext();
        }
        // Marca o vértice atual como visitado
        visited[v1] = true;
    }
    // Adiciona os resultados em um struct
    ReturnDijkstra* result = new ReturnDijkstra;
    result->distances = distances;
    result->parents = parents;
    result->minDistance = 0;
    return *result;
}

ReturnDijkstra Map::FindRoute(Order order, DeliveryMan deliveryman){
    // Obtaining the positions of the deliveryman, seller and customer
    int deliverymanPosition = deliveryman.getLocation();
    int sellerPosition = order.getOrigin();
    int customerPosition = order.getDestination();

    // Calculating the routes from the deliveryman to the seller and from the seller to the customer
    ReturnDijkstra routeDeliverymanToSeller = cptDijkstra(deliverymanPosition);
    ReturnDijkstra routeSellerToCustomer = cptDijkstra(sellerPosition);

    // Creating the arrays to store the full route
    int* DeliverymanToSeller = routeDeliverymanToSeller.parents;
    int* SellerToCustomer = routeSellerToCustomer.parents;
    int* fullRoute = new int[getNumVertices()];
    int* distances = new int[getNumVertices()];
    int minDistance = 0;
    
    // Calculing the route from the seller to the customer
    int current = customerPosition;
    while (current != sellerPosition){
        fullRoute[current] = SellerToCustomer[current];
        distances[current] = routeSellerToCustomer.distances[current] + routeDeliverymanToSeller.distances[sellerPosition];
        current = SellerToCustomer[current];
    }
    minDistance += routeSellerToCustomer.distances[customerPosition];

    // Calculing the route from the deliveryman to the seller
    while (current != deliverymanPosition){
        fullRoute[current] = DeliverymanToSeller[current];
        distances[current] = routeDeliverymanToSeller.distances[current];
        current = DeliverymanToSeller[current];
    }
    minDistance += routeDeliverymanToSeller.distances[sellerPosition];
    fullRoute[deliverymanPosition] = deliverymanPosition;
    distances[deliverymanPosition] = 0;

    // Returning the full route
    ReturnDijkstra fullRouteReturn;
    fullRouteReturn.distances = distances;
    fullRouteReturn.parents = fullRoute;
    fullRouteReturn.minDistance = minDistance;

    // Deleting the arrays
    delete[] DeliverymanToSeller;
    delete[] SellerToCustomer;

    return fullRouteReturn;

}

ReturnNearestDMen* Map::nearestDMen(int origin, int numDMen) {
    ReturnNearestDMen* result = new ReturnNearestDMen;

    // Verify exceptional cases
    if (numDMen <= 0 || origin < 0 || origin >= numVertices) {
        result->distances = nullptr;
        result->parents = nullptr;
        result->nearDMen = vector<int>();

        return result;
    }

    // First, get the CPT
    ReturnDijkstra dijkstra = cptDijkstra(origin);
    
    // Then, define the vector to return
    int maxSize;
    if (getNumDeliveryMan() < numDMen) {
        maxSize = getNumDeliveryMan();
    } else {
        maxSize = numDMen;
    }
    vector<int> nearList(maxSize);

    // Now, get the n-nearest Deliverymen with a heap (n = maxSize)
    Heap heap(1);
    for (int i=0; i<getNumDeliveryMan(); i++) {
        int dManLoc = deliveryManInMap[i].getLocation();

        if (heap.getSize() < numDMen) {
            heap.push(i, dijkstra.distances[dManLoc]);
        } else {
            if (heap.getTop().value > dijkstra.distances[dManLoc]) {
                heap.replace(i, dijkstra.distances[dManLoc]);
            }
        }
    }

    // Finally, add the n-nearest Deliverymen to the vector in the correct order
    for (int i=0; i<maxSize; i++) {
        nearList[i] = heap.getTop().id;
        heap.pop();
    }

    result->distances = dijkstra.distances;
    result->parents = dijkstra.parents;
    result->nearDMen = nearList;

    return result;
}


vector<int> Map::getPathParent(int* parent, int origin, int start){
    vector<int> path;
    while (start != origin) {
        path.insert(path.begin(),start);
        start = parent[start];
    }

    // Adicione o vértice de origem ao caminho
    path.insert(path.begin(),origin);

    return path;
}

/*
 * FindRouteOpt - Finds the optimal route for delivering an order.
 *
 * @param order: The order to be delivered.
 * @return: A pointer to ReturnFindRoutOpt structure containing the optimal route information.
 */
ReturnFindRoutOpt* Map::FindRouteOpt(Order* order){
    int numWarehouseAvaible = 0;
    vector<Warehouse> warehouseAvaible; // warehouseAvaible
    vector<DeliveryMan> deliveryManAvaible; //  First delivery, closest to warehouseAvaible (with corresponding positions), is in the deliveryManInMap vector
    vector<int*> routeAvaible; // Array of parents from deliveryManAvaible to warehouseAvaible;
    // Evaluating warehouses
    for(int i = 0; i < numWarehouse; i++){

        // Evaluating if the warehouse contains all the items and required quantities from the order
        bool hasAllProducts = true;
        Product* currentProduct = order->pProducts;
        while (currentProduct != nullptr) {
            if (!warehouseInMap[i].hasProduct(*currentProduct, currentProduct->getQuantity())) {
                hasAllProducts = false;
                break;
            } else {
                currentProduct = currentProduct->getNext();
            }
        }
        // If it has all the products, add the warehouse to the list of available warehouses
        if(hasAllProducts) {
            warehouseAvaible.push_back(warehouseInMap[i]);
            numWarehouseAvaible++;
        }
    }
    int bestComp = INT_MAX;
    int idBestComp = -1;

    for (int i = 0; i < numWarehouseAvaible; i++) {
        // Getting the nearest delivery
        ReturnNearestDMen* nearestDMan = nearestDMen(warehouseAvaible[i].getWarehouseLocation(), 1);
        // Distance from the destination to the warehouse
        order->setOrigin(warehouseAvaible[i].getWarehouseLocation());
        ReturnDijkstra routeDestinationWarehouse = FindRoute(*order, deliveryManInMap[nearestDMan->nearDMen[0]]);
        // Add delivery to the vector of available deliveries
        deliveryManAvaible.push_back(deliveryManInMap[nearestDMan->nearDMen[0]]);
        // Add vector of parents for the delivery to the warehouse
        routeAvaible.push_back(routeDestinationWarehouse.parents);
        // Add to the heap the index of the available warehouse with the total distance
        int tamRouteTemp = routeDestinationWarehouse.minDistance;

        if (tamRouteTemp < bestComp) {
            idBestComp = i;
            bestComp = tamRouteTemp;
        }
    }
    Warehouse* ptrBestWarehouse;
    Warehouse bestWarehouse = warehouseAvaible[idBestComp];
    ptrBestWarehouse = &bestWarehouse;
    DeliveryMan* ptrBestDeliveryMan;
    DeliveryMan bestDeliveryMan = deliveryManAvaible[idBestComp]; // Getting the nearest delivery
    ptrBestDeliveryMan = &bestDeliveryMan;
    int* routeMin = routeAvaible[idBestComp];

    ReturnFindRoutOpt* result = new ReturnFindRoutOpt;
    result->parents = routeMin;
    result->nearestDMan = ptrBestDeliveryMan;
    result->bestWarehouse = ptrBestWarehouse;

    return result;
}

// DFS algorithm for finding warehouses and sellers near the route
void Map::DFS(vector<int> route, int maxDistance, vector<int>& warehousesAndSellers){
    // Create a vector to store the visited vertices
    vector<bool> visited(numVertices, false);
    // Create a queue to store the vertices to be visited
    queue<int> queue; 
    // Push the first vertex to the queue
    queue.push(route[0]);
    // While the stack is not empty
    while(!queue.empty()){
        // Pop the front vertex
        int current = queue.front();
        queue.pop();
        // If the vertex is not visited
        if(!visited[current]){
            // Mark the vertex as visited
            visited[current] = true;
            // If the vertex is a warehouse or a seller
            if(warehouseList[current] != nullptr || sellerList[current] != nullptr){
                // Push the vertex to the vector
                warehousesAndSellers.push_back(current);
            }
            // Get the edges connected to the vertex
            EdgeNode* edge = edgesList[current];
            // While there are edges connected to the vertex
            while(edge!=nullptr){
                // Get the other vertex
                 int otherVertex = edge->getOtherVertex();
                // If the other vertex is not visited and the distance between the vertices is less than the maximum distance
                if(!visited[otherVertex] && edge->getDistance() <= maxDistance){
                    // Push the other vertex to the queue
                    queue.push(otherVertex);
                }
                // Move to the next edge
                edge = edge->getNext();
            }
            visited[current] = true;
        }
    }
}

// Function to check which orders can be delivered in the neighborhood of the route
void Map::checkNeighborhood(vector<Order> orders, vector<int> warehousesAndSellers, vector<Order>& ordersToDeliver){
    int origin;
    // Iterate through the orders
    for(int i = 0; i < orders.size(); i++){
        // Get the origin of the order
        origin = orders[i].getOrigin();
        // Iterate through the warehouses and sellers
        for(int j = 0; j < warehousesAndSellers.size(); j++){
            // If the origin or destination of the order is a warehouse or a seller
            if(origin == warehousesAndSellers[j]){
                // Add the order to the vector
                ordersToDeliver.push_back(orders[i]);
                // Break the loop
                break;
            }
        }
    }
}



// Function to agregate the weight and value of the items in a order
OrderAgregation Map::agregateOrder(Order order){
    // Create a new OrderAgregation
    OrderAgregation orderAgregation;
    // Set the order number
    orderAgregation.iIDNumber = order.getOrderNumber();
    // Set the weight and price to 0
    orderAgregation.iWeight = 0;
    orderAgregation.iPrice = 0;
    // Iterate through the products in the order

    Product* pProducts = order.pProducts;
    while(pProducts != nullptr){
        // Add the weight and price of the product to the orderAgregation
        orderAgregation.iWeight += pProducts->getWeight();
        orderAgregation.iPrice += pProducts->getPrice();
        // Move to the next product
        pProducts = pProducts->getNext();
    }
    // Return the orderAgregation
    return orderAgregation;
}


// Auxiliar function to knapsack
int  Map::knapSackMax(int i, vector<OrderAgregation> orders, vector<vector<int>>& dp, int iCapacity) {
    if(dp[i][iCapacity] == -1){
        if (orders[i].iWeight > iCapacity) {
            dp[i][iCapacity] = knapSackMax(i - 1, orders, dp, iCapacity);
        } else {
            int inKnapsack = orders[i].iPrice + knapSackMax(i - 1, orders, dp, iCapacity - orders[i].iWeight);
            int notinKnapsack = knapSackMax(i - 1, orders, dp, iCapacity);
            dp[i][iCapacity] = max(inKnapsack, notinKnapsack);
        }
    }
    return dp[i][iCapacity];
}

// Main function to knapsack
void  Map::knapSack(vector<OrderAgregation> orders, int iCapacity, vector<int>& selectedItems) {
    // Create a matrix to store the results
    int n = orders.size();
    vector<vector<int>> dp(n + 1, vector<int>(iCapacity + 1, -1));

    // Set the elements of the first row to 0
    for (int i = 0; i <= iCapacity; i++) {
        dp[0][i] = 0;
        for (int j = 1; j <= n; j++) {
            dp[j][0] = 0;
            dp[j][i] = -1;
        }
    }

    knapSackMax(n, orders, dp, iCapacity);

    int i = iCapacity;
    int j = n;

    while (j >= 1) {
        if (dp[j][i] != dp[j - 1][i]) {
            selectedItems.push_back(orders[j - 1].iIDNumber); // Adiciona o ID do item selecionado
            i -= orders[j - 1].iWeight;
        }
        --j;
    }

}

void Map::OrdersSugestion(vector<int> route, vector<Order> orders,DeliveryMan deliveryman ,vector<int>& selectedItems,int maxDistance){
    //DeliveryMan bag's capacity
    deliveryman.getCapacity();

    //DFS
    vector<int> warehousesAndSellers;
    DFS(route,maxDistance,warehousesAndSellers);

    //Check Neighborhood
    vector<Order> ordersToDeliverAux;
    checkNeighborhood(orders,warehousesAndSellers,ordersToDeliverAux);

    // Order Agregation
    vector<OrderAgregation> ordersAgregation;
    for(int i = 0; i < ordersToDeliverAux.size(); i++){
        ordersAgregation.push_back(agregateOrder(ordersToDeliverAux[i]));
    }

    // Knapsack
    knapSack(ordersAgregation,deliveryman.getCapacity(),selectedItems);
}


Map* generateMapQ1() {
    Map* map = new Map(16);
    
    map->addEdge(0,1, 61);
    map->addEdge(0,4, 98);
    map->addEdge(1,2, 114);
    map->addEdge(1,5, 115);
    map->addEdge(2,3, 93);
    map->addEdge(2,6, 87);
    map->addEdge(3,7, 107);
    map->addEdge(4,5, 105);
    map->addEdge(4,8, 128);
    map->addEdge(5,6, 70);
    map->addEdge(5,9, 74);
    map->addEdge(6,7, 103);
    map->addEdge(6,10, 115);
    map->addEdge(7,11, 116);
    map->addEdge(8,9, 127);
    map->addEdge(8,12, 96);
    map->addEdge(9,10, 97);
    map->addEdge(9,13, 116);
    map->addEdge(10,11, 99);
    map->addEdge(10,14, 104);
    map->addEdge(11,15, 95);
    map->addEdge(12,13, 123);
    map->addEdge(13,14, 63);
    map->addEdge(14,15, 127);

    map->addDeliveryMan(1, 5, 10);
    map->addDeliveryMan(2, 12, 10);
    map->addDeliveryMan(2, 15, 10);

    map->addWarehouse(0,7);
    map->addWarehouse(1,6);

    map->addSeller(1, 7);



    return map;
}

Map* generateMapQ4() {
    Map* map = new Map(16);
    
    map->addEdge(0,1, 61);
    map->addEdge(0,4, 98);
    map->addEdge(1,2, 114);
    map->addEdge(1,5, 115);
    map->addEdge(2,3, 93);
    map->addEdge(2,6, 87);
    map->addEdge(3,7, 107);
    map->addEdge(4,5, 105);
    map->addEdge(4,8, 128);
    map->addEdge(5,6, 70);
    map->addEdge(5,9, 74);
    map->addEdge(6,7, 103);
    map->addEdge(6,10, 115);
    map->addEdge(7,11, 116);
    map->addEdge(8,9, 127);
    map->addEdge(8,12, 96);
    map->addEdge(9,10, 97);
    map->addEdge(9,13, 116);
    map->addEdge(10,11, 99);
    map->addEdge(10,14, 104);
    map->addEdge(11,15, 95);
    map->addEdge(12,13, 123);
    map->addEdge(13,14, 63);
    map->addEdge(14,15, 127);

    map->addDeliveryMan(1, 5, 10);
    map->addDeliveryMan(2, 12, 10);
    map->addDeliveryMan(2, 15, 10);

    map->addWarehouse(0,4);
    map->addWarehouse(1,13);
    map->addWarehouse(2,14);
    map->addWarehouse(3,6);
    map->addWarehouse(4,11);

    // Add sellers
    map->addSeller(1, 8);

    //Add itens to the warehouses
    map->warehouseInMap[0].addProducts(0,1000,1,30);
    map->warehouseInMap[1].addProducts(1,110,1,1);
    map->warehouseInMap[2].addProducts(2,700,1,18);
    map->warehouseInMap[3].addProducts(3,800,1,20);
    map->warehouseInMap[4].addProducts(4,1000,1,30);

    // Add in WarehouseList the warehouses that have products
    map->sellerInMap[0].addProducts(4,1000,1,30);

    for(int current = 0; current < map->warehouseInMap.size(); current++){
        if(map->warehouseList[current] != nullptr || map->sellerList[current] != nullptr){
            // Check if it's a warehouse
            if (map->warehouseList[current] != nullptr) {
                Warehouse* currentWarehouse = map->warehouseList[current];
            }

            // Check if it's a seller
            if (map->sellerList[current] != nullptr) {
                Seller* currentSeller = map->sellerList[current];
            }
        }
        
    }
    
    return map;
}

Map* generateMapQ2() {
    Map* map = new Map(16);
    
    map->addEdge(0,1, 61);
    map->addEdge(0,4, 98);
    map->addEdge(1,2, 114);
    map->addEdge(1,5, 115);
    map->addEdge(2,3, 93);
    map->addEdge(2,6, 87);
    map->addEdge(3,7, 107);
    map->addEdge(4,5, 105);
    map->addEdge(4,8, 128);
    map->addEdge(5,6, 70);
    map->addEdge(5,9, 74);
    map->addEdge(6,7, 103);
    map->addEdge(6,10, 115);
    map->addEdge(7,11, 116);
    map->addEdge(8,9, 127);
    map->addEdge(8,12, 96);
    map->addEdge(9,10, 97);
    map->addEdge(9,13, 116);
    map->addEdge(10,11, 99);
    map->addEdge(10,14, 104);
    map->addEdge(11,15, 95);
    map->addEdge(12,13, 123);
    map->addEdge(13,14, 63);
    map->addEdge(14,15, 127);

    map->addDeliveryMan(1, 4, 10);
    map->addDeliveryMan(2, 11, 10);
    map->addDeliveryMan(2, 14, 10);

    map->addWarehouse(0,8);
    map->addWarehouse(1,13);
    map->addWarehouse(2,14);
    map->addWarehouse(3,6);
    map->addWarehouse(4,11);

    map->addSeller(0,8);
    map->sellerInMap[0].addProducts(0,1,2,1);
    map->warehouseInMap[0].addProducts(0,1,2,1);
    map->warehouseInMap[0].addProducts(1,2,3,1);
    map->warehouseInMap[1].addProducts(3,1,2,1);
    map->warehouseInMap[1].addProducts(4,2,3,1);

    return map;
}