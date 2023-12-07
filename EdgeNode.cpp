// EdgeNode.cpp

#include "EdgeNode.h"

EdgeNode::EdgeNode(int originVertex, int otherVertex, int distance, EdgeNode* next):
originVertex(originVertex), 
otherVertex(otherVertex), 
distance(distance), 
next(next) {}
