// EdgeNode.cpp

#include "EdgeNode.h"

EdgeNode::EdgeNode(int otherVertex, int weight, int time, EdgeNode *next)
: m_otherVertex(otherVertex), m_weight(weight), m_time(time), m_next(next) {}

int EdgeNode::otherVertex() {
    return m_otherVertex;
}

int EdgeNode::weight() {
    return m_weight;
}

int EdgeNode::time() {
    return m_time;
}

EdgeNode *EdgeNode::next() {
    return m_next;
}

void EdgeNode::setNext(EdgeNode *next) {
    m_next = next;
}
