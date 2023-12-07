#include <gtest/gtest.h>
#include "Map.h"

// Test Fixture for Map class
class MapTest : public ::testing::Test {
protected:
    Map* mapa;

    void SetUp() override {
        mapa = new Map(6);
        mapa->addEdge(0, 1, 10);
        mapa->addEdge(0, 2, 20);
        mapa->addEdge(1, 3, 30);
        mapa->addEdge(1, 4, 20);
        mapa->addEdge(2, 4, 90);
        mapa->addEdge(3, 4, 100);
        mapa->addEdge(4, 1, 40);
        mapa->addEdge(4, 5, 60);
        // Setup DeliveryMen locations and other necessary setups
    }

    // Teardown method to cleanup resources
    void TearDown() override {
        delete mapa;
    }
};

// Test case for nearestDMen with valid inputs
TEST_F(MapTest, NearestDMen_ValidInput) {
    vector<int> expected = { /* expected delivery men IDs */ };
    
    vector<int> result = mapa->nearestDMen(/* origin */, /* numDMen */);

    ASSERT_EQ(result, expected);
}

// Test case for nearestDMen with edge cases, like no delivery men
TEST_F(MapTest, NearestDMen_NoDeliveryMen) {
    vector<int> expected = {};

    vector<int> result = mapa->nearestDMen(/* origin */, /* numDMen */);

    ASSERT_EQ(result, expected);
}

// Test case for nearestDMen when only one delivery man is significantly closer than others
TEST_F(MapTest, NearestDMen_OneClosestDeliveryMan) {
    // Set up delivery men locations such that only one is significantly closer to the origin
    // For example, deliveryManList[0] is the closest to the origin point
    // The exact locations depend on your Map and DeliveryMan class implementations

    int origin = /* choose an origin point */;
    int numDMen = /* number of delivery men to return, e.g., 1 */;

    vector<int> expected = { /* ID of the closest delivery man */ };

    vector<int> result = mapa->nearestDMen(origin, numDMen);

    ASSERT_EQ(result.size(), 1); // Check if only one delivery man is returned
    ASSERT_EQ(result[0], expected[0]); // Check if the returned delivery man is the expected closest one
}

// Test case for nearestDMen when all delivery men are at the same distance from the origin
TEST_F(MapTest, NearestDMen_AllDeliveryMenAtSameDistance) {
    // Set up delivery men locations so that all are at the same distance from the origin
    // For instance, if there are 5 delivery men, set them all at a distance that makes them equidistant from the origin
    // The exact setup will depend on your Map and DeliveryMan class implementations

    int origin = /* choose an origin point */;
    int numDMen = /* number of delivery men to return, e.g., total number of delivery men */;

    // Since all delivery men are at the same distance, we expect the IDs of all delivery men, in any order
    vector<int> expected = { /* IDs of all delivery men */ };

    vector<int> result = mapa->nearestDMen(origin, numDMen);

    ASSERT_EQ(result.size(), expected.size()); // Check if the number of returned delivery men matches the expected number

    // Additional checks can be performed to ensure that all IDs in the result are present in the expected list
    // This is necessary as the order may not be guaranteed
    for (int id : result) {
        ASSERT_NE(find(expected.begin(), expected.end(), id), expected.end());
    }
}

// Test case for nearestDMen with an invalid origin that is not in the graph
TEST_F(MapTest, NearestDMen_InvalidOrigin) {
    // Define an invalid origin that is not in the graph
    // The choice of invalid origin should be such that it is not a part of the graph's node set
    int invalidOrigin = /* choose an invalid origin point */;

    int numDMen = /* number of delivery men to return, e.g., 1 or more */;

    vector<int> result = mapa->nearestDMen(invalidOrigin, numDMen);

    // Depending on how nearestDMen handles invalid origins, this might be an empty vector
    // or the method might throw an exception which should be caught and asserted
    vector<int> expected = {}; // Assuming the method returns an empty vector for an invalid origin
    ASSERT_EQ(result, expected);
}


// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
