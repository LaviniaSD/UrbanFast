// EdgeNode.h

#include "Deliveryman.h"
#include "Warehouse.h"

#pragma once

class EdgeNode {
    private:
        int originVertex;
        int otherVertex;
        int distance;
        EdgeNode* next;

    public:
        EdgeNode(int originVertex, int otherVertex, int distance, EdgeNode* next);
        
        void setOriginVertex(int newOrigin){
            originVertex = newOrigin;
        }
        int getOriginVertex(){
            return originVertex;
        }

        void setOtherVertex(int newOther){
            otherVertex = newOther;
        }
        int getOtherVertex(){
            return otherVertex;
        }

        void setDistance(int newDistance){
            distance = newDistance;
        }
        int getDistance(){
            return distance;
        }
        
        void setNext(EdgeNode* newNext){
            next = newNext;
        }
        EdgeNode* getNext(){
            return next;
        }
};
