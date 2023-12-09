#include "Map.h"
#include "Order.h"
#include "Deliveryman.h"
#include <iostream>

using namespace std;

int main(){
    cout<<"Teste Q4"<<endl;

    // Generate map
    Map* map = generateMapQ4();
    Map mapClass = *map;

    
    cout<<"Mapa gerado"<<endl;

    // Generate route
    vector<int> route = {0, 1, 5,9,10};

    cout<<"Rota gerada"<<endl;

    // Find warehouses and sellers
    vector<int> placesNearRoute;

    mapClass.DFS(route, 0, placesNearRoute);

    cout<<"Armazens e vendedores encontrados"<<endl;

    // Generate orders
    Order order1 = Order(0, 7, 14, 1);
    Order order2 = Order(1, 7, 4, 1);
    Order order3 = Order(2, 7, 11, 1);
    Order order4 = Order(3, 7, 13, 1);
    Order order5 = Order(4, 7, 6, 0);

    cout<<"Encomendas geradas"<<endl;

    // Add products to orders
    order1.addProducts(0,1000,1,30);
    order2.addProducts(1,110,1,1);
    order3.addProducts(2,700,1,18);
    order4.addProducts(3,800,1,20);
    order5.addProducts(4,1000,1,30);

    cout<<"Produtos adicionados as encomendas"<<endl;

    // Check available orders
    vector<Order> availableOrders;
    availableOrders.push_back(order1);
    availableOrders.push_back(order2);
    availableOrders.push_back(order3);
    availableOrders.push_back(order4);
    availableOrders.push_back(order5);

    cout<<"Encomendas disponiveis"<<endl;

    // Check available orders near route
    vector<Order> OptionsOfOrder;
    mapClass.checkNeighborhood(availableOrders, placesNearRoute, OptionsOfOrder);

    cout<<"Encomendas disponiveis perto da rota"<<endl;

    // Agregate orders
    vector<OrderAgregation> ordersVector;
    for(int i = 0; i < OptionsOfOrder.size(); i++){
        ordersVector.push_back(map->agregateOrder(OptionsOfOrder[i]));
    }

    cout<<"Encomendas agregadas"<<endl;

    // Knapsack 
    vector<int> knapsack;

    mapClass.knapSack(ordersVector, 20, knapsack);

    cout<<"Mochila feita"<<endl;

    cout<<"Encomendas a serem entregues:"<<endl;
    for(int i = 0; i < knapsack.size(); i++){
        cout<<knapsack[i]<<endl;
    }

    return 0;
}