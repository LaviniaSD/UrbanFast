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
        EdgeNode(int originVertex, int otherVertex, int distance, DeliveryMan *deliveryMan, WareHouse *warehouse, EdgeNode *next);

        int originVertex(){
            return m_originVertex;
        }

        int otherVertex(){
            return m_otherVertex;
        }
        int distance(){
            return m_distance;
        }
        DeliveryMan *deliveryMan(){
            return m_deliveryMan;
        }
        WareHouse *warehouse(){
            return m_warehouse;
        }
        EdgeNode *next();
        void setNext(EdgeNode *next);
};

#endif
