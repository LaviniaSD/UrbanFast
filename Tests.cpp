#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>
#include "Map.h"


Map* generateMapTest() {
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

    map->addWarehouse(0,4);
    map->addWarehouse(1,13);
    map->addWarehouse(2,14);
    map->addWarehouse(3,6);
    map->addWarehouse(4,11);

    map->addSeller(0,8);
    map->sellerInMap[0].addProducts(0,1,2,1);
    map->warehouseInMap[0].addProducts(0,1,2,1);
    map->warehouseInMap[0].addProducts(1,2,3,1);
    map->warehouseInMap[1].addProducts(0,1,2,1);
    map->warehouseInMap[1].addProducts(2,2,3,1);

    return map;
}

class MapTest : public ::testing::Test {
protected:
    Map* mapa;

    // Setup method to initialize a Map instance using generateMapQ1
    void SetUp() override {
        mapa = generateMapTest();
    }

    // Teardown method to cleanup resources
    void TearDown() override {
        delete mapa;
    }
};

// Test case when one delivery man is significantly closer than others
TEST_F(MapTest, NearestDMen_OneClosestDeliveryMan) {
    int expected = 4;

    ReturnNearestDMen* resultStruct = mapa->nearestDMen(1, 1);
    vector<int> result = resultStruct->nearDMen;
    int locationResult = mapa->deliveryManInMap[result[0]].getLocation();

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(locationResult, expected);

    delete resultStruct;
}


// Test case when all delivery men are at the same distance from the origin
TEST_F(MapTest, NearestDMen_AllDeliveryMenAtSameDistance) {
    vector<int> expected = {5, 12, 15};

    ReturnNearestDMen* resultStruct = mapa->nearestDMen(0, 3);
    vector<int> result = resultStruct->nearDMen;

    delete resultStruct;

    ASSERT_EQ(result.size(), expected.size());
}


// Test case with an invalid origin
TEST_F(MapTest, NearestDMen_InvalidOrigin) {
    int invalidOrigin = 16;

    ReturnNearestDMen* resultStruct = mapa->nearestDMen(invalidOrigin, 1);
    vector<int> result = resultStruct->nearDMen;

    // This assumes that the function returns an empty vector in case of an invalid origin
    vector<int> expected = {};
    ASSERT_EQ(result, expected);

    delete resultStruct;
}

// Test case where the number of delivery men requested is more than available
TEST_F(MapTest, NearestDMen_MoreDeliveryMenRequestedThanAvailable) {
    int origin = 1;
    int numDMenRequested = mapa->getNumDeliveryMan() + 1;

    ReturnNearestDMen* resultStruct = mapa->nearestDMen(origin, numDMenRequested);
    vector<int> result = resultStruct->nearDMen;

    // This assumes that the function returns all delivery men if the requested number is too high
    vector<int> expected = {5, 12, 15};
    ASSERT_EQ(result.size(), expected.size());

    delete resultStruct;
}

// Q3 
TEST_F(MapTest, FindRouteOpt_ValidRouteAndDistance) {
    Order order(0,5,1,0); //numeor do pedido:0; Local de entrega vert 5; vendedor 1; typo 0;
    order.addProducts(0,1,2,1);
    order.addProducts(1,1,2,1);

    DeliveryMan deliveryMan = mapa->deliveryManInMap[0];

    ReturnFindRoutOpt* result = mapa->FindRouteOpt(order);

    ASSERT_NE(result, nullptr);
    ASSERT_EQ((result->nearestDMan->getLocation()), 388);

    // delete result;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*

FILE ITERATOR OVER DIRECTORY EXAMPLE


#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;
 
int main() {
  std::string path = "./cases/";

  for (const auto & entry : fs::directory_iterator(path)) {
    std::cout << entry.path() << std::endl;
  }
}


*/
