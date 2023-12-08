/**
 * @file EdgeNode.h
 * @brief Defines the EdgeNode class, which represents an edge in a graph.
 */

#pragma once

/**
 * @class EdgeNode
 * @brief Represents an edge in a graph.
 */
class EdgeNode {
    private:
        int originVertex; // Origin vertex of the edge
        int otherVertex; // The other vertex connected by the edge
        int distance; // Distance or weight associated with the edge
        EdgeNode* next; // Pointer to the next edge in the list

    public:
        /**
         * @brief Constructor for the EdgeNode class
         * 
         * @param originVertex The origin vertex of the edge
         * @param otherVertex The other vertex connected by the edge
         * @param distance The distance or weight associated with the edge
         * @param next Pointer to the next edge in the list
         */
        EdgeNode(int originVertex, int otherVertex, int distance, EdgeNode* next);
        
        /**
         * @brief Setter for the origin vertex of the edge
         * 
         * @param newOrigin The new origin vertex value
         */
        void setOriginVertex(int newOrigin){
            originVertex = newOrigin;
        }
        
        /**
         * @brief Getter for the origin vertex of the edge
         * 
         * @return The origin vertex of the edge
         */
        int getOriginVertex(){
            return originVertex;
        }

        /**
         * @brief Setter for the other vertex connected by the edge
         * 
         * @param newOther The new other vertex value
         */
        void setOtherVertex(int newOther){
            otherVertex = newOther;
        }
        
        /**
         * @brief Getter for the other vertex connected by the edge
         * 
         * @return The other vertex connected by the edge
         */
        int getOtherVertex(){
            return otherVertex;
        }

        /**
         * @brief Setter for the distance or weight associated with the edge
         * 
         * @param newDistance The new distance or weight value
         */
        void setDistance(int newDistance){
            distance = newDistance;
        }
        
        /**
         * @brief Getter for the distance or weight associated with the edge
         * 
         * @return The distance or weight associated with the edge
         */
        int getDistance(){
            return distance;
        }
        
        /**
         * @brief Setter for the pointer to the next edge in the list
         * 
         * @param newNext The new pointer to the next edge
         */
        void setNext(EdgeNode* newNext){
            next = newNext;
        }
        
        /**
         * @brief Getter for the pointer to the next edge in the list
         * 
         * @return The pointer to the next edge in the list
         */
        EdgeNode* getNext(){
            return next;
        }
};
