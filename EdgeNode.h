// EdgeNode.h

#include "Deliveryman.h"
#include "Warehouse.h"

#ifndef EDGENODE_H
#define EDGENODE_H


class EdgeNode {
    private:
        int m_originVertex;
        int m_otherVertex;
        int m_distance;
        DeliveryMan *m_deliveryMan;
        Warehouse *m_warehouse;
        EdgeNode *m_next;

    public:
        EdgeNode(int otherVertex, int weight, int time, EdgeNode *next);

        int otherVertex();
        int weight();
        int time();
        EdgeNode *next();
        void setNext(EdgeNode *next);
};

#endif
