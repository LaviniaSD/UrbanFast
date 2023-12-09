#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
#include <gtest/gtest.h>
#include "Map.h"

using namespace std;
namespace fs = std::filesystem;

struct caseData {
    // Counters
    int numVertices = 0;
    int numEdges = 0;
    int numDeliveryMen = 0;
    int numItems = 0;
    int numSellers = 0;
    int numWarehouses = 0;
    int numOrders = 0;
    int noiseLevel = 0;
    int questionNumber = 0;

    // Definitions
    vector<vector<int>> edges;
    vector<vector<int>> deliveryMen;
    vector<vector<int>> items;
    vector<vector<int>> sellers;
    vector<vector<int>> warehouses;
    vector<vector<int>> orders;
};

// Function to read a case from a txt file and return a caseData struct
bool readCaseData(caseData data, string fileName) {

    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Unable to open file: " << fileName << endl;
        return 1;
    }

    caseData data;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string marker;
        ss >> marker;

        // Vertice count
        if (marker == "VC") {
            ss >> data.numVertices;

        // Edge count
        } else if (marker == "EC") {
            ss >> data.numEdges;
        }

        // Delivery Men Count
        else if (marker == "DMC") {
            ss >> data.numDeliveryMen;
        }

        // Items Count
        else if (marker == "IC") {
            ss >> data.numItems;
        }

        // Sellers Count
        else if (marker == "SC") {
            ss >> data.numSellers;
        }

        // Warehouses Count
        else if (marker == "WC") {
            ss >> data.numWarehouses;
        }

        // Orders Count
        else if (marker == "OC") {
            ss >> data.numOrders;
        }

        // Noise Level
        else if (marker == "NL") {
            ss >> data.noiseLevel;
        }

        // Question Number
        else if (marker == "QN") {
            ss >> data.questionNumber;
        }

        // Edges Definition
        else if (marker == "ED") {
            int a, b, c;
            ss >> a >> b >> c;
            data.edges.push_back({a, b, c});
        }

        // Delivery Men Definition
        else if (marker == "DM") {
            int a, b, c;
            ss >> a >> b >> c;
            data.edges.push_back({a, b, c});
        }

        // Items Definition
        else if (marker == "ID") {
            int a, b, c;
            ss >> a >> b >> c;
            data.items.push_back({a, b, c});
        }

        // Sellers Definition
        else if (marker == "SD") {
            int a, b;
            ss >> a >> b;
            data.sellers.push_back({a, b});
        }

        // Warehouses Definition
        else if (marker == "DCD") {
            int a, b;
            ss >> a >> b;
            data.warehouses.push_back({a, b});
        }

        // Orders Definition
        else if (marker == "OD") {
            int a, b;
            ss >> a >> b;
            data.orders.push_back({a, b});
        }

        // Unknown marker
        else {
            cout << "Unknown marker: " << marker << endl;
            return false;
        }

    }

    file.close();
    return true;
}

Map* LoadMap(string fileName) {

    caseData data;
    string filename;

    if (!readCaseData(data, filename)) {
        return nullptr;
    }

    // Instantiate map
    Map* map = new Map(data.numVertices);

    // Add edges
    for (vector<int> edge : data.edges) {
        map->addEdge(edge[0], edge[1], edge[2]);
    }

    // Add Delivery Men
    for (vector<int> deliveryMan : data.deliveryMen) {
        map->addDeliveryMan(deliveryMan[0], deliveryMan[1], deliveryMan[2]);
    }

    // Add Items
    for (vector<int> item : data.items) {
        map->addItem(item[0], item[1], item[2]);
    }

    // Add Sellers
    for (vector<int> seller : data.sellers) {
        map->addSeller(seller[0], seller[1]);
    }

    // Add Warehouses
    for (vector<int> warehouse : data.warehouses) {
        map->addWarehouse(warehouse[0], warehouse[1]);
    }

    // Add Orders
    for (vector<int> order : data.orders) {
        map->addOrder(order[0], order[1]);
    }

    return map;
}

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

    map->addDeliveryMan(1, 5, 10);
    map->addDeliveryMan(2, 12, 10);
    map->addDeliveryMan(2, 15, 10);

    map->addSeller(1, 7);

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
    int expected = 5;

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


// // Test case with an invalid origin
// TEST_F(MapTest, NearestDMen_InvalidOrigin) {
//     int invalidOrigin = 16;

//     ReturnNearestDMen* resultStruct = mapa->nearestDMen(invalidOrigin, 1);
//     vector<int> result = resultStruct->nearDMen;

//     // This assumes that the function returns an empty vector in case of an invalid origin
//     vector<int> expected = {};
//     ASSERT_EQ(result, expected);

//     delete resultStruct;
// }

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
    Order order(1, 10, 7, false);
    order.addProducts(1, 50, 10, 2);

    DeliveryMan deliveryMan = mapa->deliveryManInMap[0];

    ReturnFindRoutOpt result = *mapa->FindRouteOpt(order);

    // ASSERT_NE(result, nullptr);
    // ASSERT_EQ(*(result->distanceTotal), 388);
    // ASSERT_NE(result->nearestDMan, nullptr);
    // ASSERT_FALSE(result->routeMin.empty());
    // ASSERT_EQ(result->routeMin, std::vector<int>({7, 11, 10}));
    // ASSERT_EQ(result->routeMin.back(), order.getDestination());


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
