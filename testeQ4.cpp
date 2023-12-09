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

    //Generate a route
    vector<int> route = {0, 1, 5,9,10};

    // Generate deliveryman
    DeliveryMan deliveryman = DeliveryMan(0, 0, 20, nullptr);

    // Generate the orders
    Order order1 = Order(0, 7, 14, 1);
    Order order2 = Order(1, 7, 4, 1);
    Order order3 = Order(2, 7, 11, 1);
    Order order4 = Order(3, 7, 13, 1);
    Order order5 = Order(4, 7, 6, 0);

    // Add products to the orders
    order1.addProducts(0,1000,1,30);
    order2.addProducts(1,110,1,1);
    order3.addProducts(2,700,1,18);
    order4.addProducts(3,800,1,20);
    order5.addProducts(4,1000,1,30);

    // Generate a orders array
    vector<Order> orders = {order1,order2,order3,order4,order5};
    cout<<"prepare to sugest"<<endl;
    // Sugest new orders
    vector<int> sugestions = mapClass.OrderSuggestions(route,orders,deliveryman,110);
    cout<<"sugestions ok"<<endl;
}