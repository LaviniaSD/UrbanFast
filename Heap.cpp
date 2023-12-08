/**
 * @file Heap.cpp
 * @brief Implementation file for the Heap class.
 */

#include <vector>
#include <iostream>
#include <cmath>
#include "Heap.h"

using namespace std;

Heap::Heap(int type): size(0), type(type), body(1) {}
Heap::~Heap() {
    for (int i = 1; i <= size; ++i) delete &body[i];
}


int Heap::getSize() {
    return size;
}

int Heap::getLeft(int i) {
    return 2 * i;
}

int Heap::getRight(int i) {
    return 2 * i + 1;
}

int Heap::getParent(int i) {
    return floor(i / 2);
}

HeapNode Heap::getTop() {
    return body[1];
}

void Heap::swap(int a, int b) {
    HeapNode aux = body[a];
    body[a] = body[b];
    body[b] = aux;
}

// Fix the position of the element in the given index
void Heap::heapify(int i) {
    int l = getLeft(i);
    int r = getRight(i);
    int up = getParent(i);
    int inx = i;

    if (l <= size 
    && body[l].value * type > body[i].value * type) {
        inx = l;
    }
    if (r <= size 
    && body[r].value * type > body[inx].value * type) {
        inx = r;
    }
    else if (up >= 1 
    && body[up].value * type < body[inx].value * type) {
        inx = up;
    }

    if (inx != i) {
        swap(i, inx);
        heapify(inx);
    }
}

// Add a new element to the heap
void Heap::push(int id, int value) {
    HeapNode node = *new HeapNode;
    node.id = id;
    node.value = value;

    body.push_back(node);
    size++;

    int i = size;
    heapify(i);
}

// Remove the top element
void Heap::pop() {
    swap(1, size);
    body.pop_back();
    size--;

    heapify(1);
}

// Replace the top element with the given, and fix the heap
void Heap::replace(int id, int value) {
    body[1].id = id;
    body[1].value = value;
    heapify(1);
}

void Heap::print() {
    for (int i = 1; i <= size; i++) {
        cout << body[i].id << " ";
        
        // Check if i+1 is a power of 2
        if (log2(i + 1) == floor(log2(i + 1))) {
            cout << endl;
        }
    }
    cout << endl;
}

