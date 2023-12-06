// EdgeNode.cpp

#include "EdgeNode.h"

EdgeNode::EdgeNode(int originVertex, int otherVertex, int distance, DeliveryMan* deliveryMan, Warehouse* warehouse, EdgeNode* next):
originVertex(originVertex), 
otherVertex(otherVertex), 
distance(distance), 
deliveryMan(deliveryMan), 
warehouse(warehouse), 
next(next) {}
