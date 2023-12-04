// EdgeNode.h

#ifndef EDGENODE_H
#define EDGENODE_H

class EdgeNode {
public:
    EdgeNode(int otherVertex, int weight, int time, EdgeNode *next);
    int otherVertex();
    int weight();
    int time();
    EdgeNode *next();
    void setNext(EdgeNode *next);

private:
    int m_otherVertex;
    int m_weight;
    int m_time;
    EdgeNode *m_next;
};

#endif
