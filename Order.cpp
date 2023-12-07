#include "Order.h"
#include "Map.h"
#include <iostream>

using namespace std;

Order::Order(int iItems, int iQuantity, int iDestination, int iPrice, DeliveryMan iDeliveryMan, int iOrderNumber, int iOrigin, bool bType):
iItems(iItems),
iQuantity(iQuantity),
iDestination(iDestination),
iPrice(iPrice),
iDeliveryMan(iDeliveryMan),
iOrderNumber(iOrderNumber),
iOrigin(iOrigin),
bType(bType) {}

ReturnDijkstra Order::FindRoute(Map map){
    if (getType == 0){
        // Obter posições do entregador, vendedor e cliente
        int deliverymanPosition = getDeliveryMan().getLocation();
        int sellerPosition = getOrigin();
        int customerPosition = getDestination();

        // Calcular rotas usando Dijkstra
        ReturnDijkstra routeDeliverymanToSeller = map.cptDijkstra(deliverymanPosition);
        ReturnDijkstra routeSellerToCustomer = map.cptDijkstra(sellerPosition);

        // Calcular rota completa concatenando as rotas parciais
        int* DeliverymanToSeller = routeDeliverymanToSeller.parents;
        int* SellerToCustomer = routeSellerToCustomer.parents;
        int* fullRoute = new int[map.getNumVertices()];
        int* distances = new int[map.getNumVertices()];
        int* minDistance = 0;
    
        // Calcula a rota do cliente ao vendedor
        int current = customerPosition;
        while (current != sellerPosition){
            minDistance += routeSellerToCustomer.distances[current];
            fullRoute[current] = SellerToCustomer[current];
            distances[current] = routeSellerToCustomer.distances[current];
            current = SellerToCustomer[current];
        }

        // Calcula a rota do vendedor ao entregador
        while (current != deliverymanPosition){
            minDistance += routeSellerToCustomer.distances[current];
            fullRoute[current] = DeliverymanToSeller[current];
            distances[current] = routeDeliverymanToSeller.distances[current];
            current = DeliverymanToSeller[current];
        }

        fullRoute[deliverymanPosition] = deliverymanPosition;
        minDistance += routeDeliverymanToSeller.distances[deliverymanPosition];
        distances[deliverymanPosition] = 0;

        // Retorna a rota completa
        ReturnDijkstra fullRouteReturn;
        fullRouteReturn.distances = distances;
        fullRouteReturn.parents = fullRoute;
        fullRouteReturn.minDistance = minDistance;

        return fullRouteReturn;

    }

}


