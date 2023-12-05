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
        WareHouse *m_warehouse;
        EdgeNode *m_next;

    public:
        EdgeNode(int otherVertex, int weight, int time, EdgeNode *next);

        void setOriginVertex(int originVertex);
        int getOriginVertex();

        void setOtherVertex(int otherVertex);
        int getOtherVertex();

        void setDistance(int distance);
        int getDistance();

        void setDeliveryMan(DeliveryMan *deliveryMan);
        int getDeliveryMan();

        void setWarehouse(WareHouse *warehouse);
        int getWarehouse();

        EdgeNode *next();

};

#endif
