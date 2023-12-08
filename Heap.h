/**
 * @file Heap.h
 * @brief This file contains the declaration of the Heap class and the HeapNode struct.
 */

#pragma once
#include <vector>

using namespace std;

/**
 * @struct HeapNode
 * @brief Struct representing a node in the heap.
 */
struct HeapNode {
    int id; /**< The ID of the node. */
    int value; /**< The value of the node. */
};

/**
 * @class Heap
 * @brief Class representing a heap data structure.
 */
class Heap {
    private:
        vector<HeapNode> body; /**< The vector storing the heap elements. */
        int size; /**< The size of the heap. */
        int type; /**< The type of the heap (-1 for min heap, 1 for max heap). */

    public:
        /**
         * @brief Constructor for the Heap class.
         * @param type The type of the heap (-1 for min heap, 1 for max heap).
         */
        Heap(int type);

        /**
         * @brief Destructor for the Heap class.
         */
        ~Heap();

        /**
         * @brief Get the size of the heap.
         * @return The size of the heap.
         */
        int getSize();

        /**
         * @brief Get the index of the left child of a node.
         * @param i The index of the node.
         * @return The index of the left child.
         */
        int getLeft(int i);

        /**
         * @brief Get the index of the right child of a node.
         * @param i The index of the node.
         * @return The index of the right child.
         */
        int getRight(int i);

        /**
         * @brief Get the index of the parent of a node.
         * @param i The index of the node.
         * @return The index of the parent.
         */
        int getParent(int i);

        /**
         * @brief Get the top element of the heap.
         * @return The top element of the heap.
         */
        HeapNode getTop();

        /**
         * @brief Swap two elements in the heap.
         * @param a The index of the first element.
         * @param b The index of the second element.
         */
        void swap(int a, int b);

        /**
         * @brief Heapify the heap starting from a given index.
         * @param i The index to start heapify from.
         */
        void heapify(int i);

        /**
         * @brief Push a new element into the heap.
         * @param id The ID of the element.
         * @param value The value of the element.
         */
        void push(int id, int value);

        /**
         * @brief Pop the top element from the heap.
         */
        void pop();

        /**
         * @brief Replace the value of an element in the heap.
         * @param id The ID of the element.
         * @param value The new value of the element.
         */
        void replace(int id, int value);

        /**
         * @brief Print the elements of the heap.
         */
        void print();
};