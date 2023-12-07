#include "Customer.h"
#include "Deliveryman.h"
#include "EdgeNode.h"
#include "Map.h"
#include "Order.h"
#include "Product.h"
#include "Seller.h"
#include "Warehouse.h"


#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    cout << "oi";

    Map* G0;
    Map G0Ob(6);
    G0 = &G0Ob;
    G0->addEdge(0, 1,10);
    G0->addEdge(0, 2,20);
    G0->addEdge(1, 3,30);
    G0->addEdge(1, 4,20);
    G0->addEdge(2, 4,90);
    G0->addEdge(3, 4,100);
    G0->addEdge(4, 1,40);
    G0->addEdge(4, 5,60);


    return 0;
}
