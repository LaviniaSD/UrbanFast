// EdgeNode.h

#include "DeliveryMan.h"
#include "Warehouse.h"

#pragma once

class EdgeNode {
    private:
        int originVertex; // Origin vertex of the edge
        int otherVertex; // The other vertex connected by the edge
        int distance; // Distance or weight associated with the edge
        EdgeNode* next; // Pointer to the next edge in the list

    public:
        // Constructor for the EdgeNode class
        EdgeNode(int originVertex, int otherVertex, int distance, EdgeNode* next);
        
        // Setter and getter for the origin vertex of the edge
        void setOriginVertex(int newOrigin){
            originVertex = newOrigin;
        }
        int getOriginVertex(){
            return originVertex;
        }

        // Setter and getter for the other vertex connected by the edge
        void setOtherVertex(int newOther){
            otherVertex = newOther;
        }
        int getOtherVertex(){
            return otherVertex;
        }

        // Setter and getter for the distance or weight associated with the edge
        void setDistance(int newDistance){
            distance = newDistance;
        }
        int getDistance(){
            return distance;
        }
        
        // Setter and getter for the pointer to the next edge in the list
        void setNext(EdgeNode* newNext){
            next = newNext;
        }
        EdgeNode* getNext(){
            return next;
        }
};
