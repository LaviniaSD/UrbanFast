#include <gtest/gtest.h>
#include "Map.h"
#include "Order.h"
#include "DeliveryMan.h"
#include "Product.h"

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

    map->addSeller(1, 7);

    return map;
}

class MapOptRouteTest : public ::testing::Test {
protected:
    Map* map;

    void SetUp() override {
        map = generateMapQ1();
    }

    void TearDown() override {
        delete map;
    }
};

TEST_F(MapOptRouteTest, FindRouteOpt_ValidRouteAndDistance) {
    Product product(1, 50, 10, 2, nullptr);
    ProductQuantity productQuantity(product, 5);

    Order order(1, 10, 7, false); 
    order.pProducts = &productQuantity;

    DeliveryMan deliveryMan = map->deliveryManInMap[0];

    ReturnFindRoutOpt* result = map->FindRouteOpt(order);

    ASSERT_NE(result, nullptr);
    ASSERT_EQ(*(result->distanceTotal), 388);
    ASSERT_NE(result->nearestDMan, nullptr);
    ASSERT_FALSE(result->routeMin.empty());
    ASSERT_EQ(result->routeMin, std::vector<int>({7, 11, 10}));
    ASSERT_EQ(result->routeMin.back(), order.getDestination());


    delete result;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
