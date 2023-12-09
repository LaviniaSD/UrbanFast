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


    // Generate route
    vector<int> route = {0, 1, 5,9,10};

    // Generate orders
    Order order1 = Order(0, 7, 14, 1);
    Order order2 = Order(1, 7, 4, 1);
    Order order3 = Order(2, 7, 11, 1);
    Order order4 = Order(3, 7, 13, 1);
    Order order5 = Order(4, 7, 6, 0);


    // Add products to orders
    order1.addProducts(0,1000,1,30);
    order2.addProducts(1,110,1,1);
    order3.addProducts(2,700,1,18);
    order4.addProducts(3,800,1,20);
    order5.addProducts(4,1000,1,30);


    // Check available orders
    vector<Order> availableOrders;
    availableOrders.push_back(order1);
    availableOrders.push_back(order2);
    availableOrders.push_back(order3);
    availableOrders.push_back(order4);
    availableOrders.push_back(order5);

    // Generate deliveryman
    DeliveryMan deliveryman = DeliveryMan(0, 0, 20, nullptr);

    // Select orders
    vector<int> selectedOrders;
    mapClass.OrdersSugestion(route, availableOrders, deliveryman, selectedOrders,110);
    return 0;
}