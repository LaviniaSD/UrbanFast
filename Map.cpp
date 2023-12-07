// GraphAdjList.cpp
#include "Map.h"
#include "EdgeNode.h"
#include "limits.h"
#include <iostream>
#include <vector>

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

