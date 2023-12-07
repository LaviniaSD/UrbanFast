#pragma once
#include <vector>

using namespace std;

struct HeapNode {
    int id;
    int value;
};

class Heap {
    private:
        vector<HeapNode> body;
        int size;
        int type;

    public:
        // -1 for min heap, 1 for max heap
        Heap(int type);
        ~Heap();

        int getSize();

        int getLeft(int i);
        int getRight(int i);
        int getParent(int i);

        HeapNode getTop();

        void swap(int a, int b);
        void heapify(int i);

        void push(int id, int value);
        void pop();
        void replace(int id, int value);

        void print();
};