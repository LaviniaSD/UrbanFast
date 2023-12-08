/**
 * @file EdgeNode.cpp
 * @brief Implementation file for the EdgeNode class.
 */

#include "EdgeNode.h"

// Constructor for the EdgeNode class
EdgeNode::EdgeNode(int originVertex, int otherVertex, int distance, EdgeNode* next):
originVertex(originVertex), 
otherVertex(otherVertex), 
distance(distance), 
next(next) {}
