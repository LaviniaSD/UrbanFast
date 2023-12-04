// GraphAdjList.cpp

#include "GraphAdjList.h"
#include <iostream>

GraphAdjList::GraphAdjList(int numVertices)
: m_numVertices(numVertices), m_numEdges(0), m_edges(nullptr) {
    m_edges = new EdgeNode*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        m_edges[i] = nullptr;
    }
}

GraphAdjList::~GraphAdjList() {
    for (int i = 0; i < m_numVertices; ++i) {
        EdgeNode* edge = m_edges[i];
        while (edge) {
            EdgeNode* next = edge->next();
            delete edge;
            edge = next;
        }
    }
    delete[] m_edges;
}

void GraphAdjList::addEdge(int v1, int v2, int weight, int time) {
    EdgeNode* edge = m_edges[v1];
    while (edge) {
        if (edge->otherVertex() == v2) {
            // Se desejar atualizar o peso neste ponto, você pode fazer isso aqui
            return;
        }
        edge = edge->next();
    }

    // Adiciona uma nova aresta com o peso especificado
    m_edges[v1] = new EdgeNode(v2, weight, time, m_edges[v1]);
    m_numEdges++;
}

void GraphAdjList::removeEdge(int v1, int v2) {
    EdgeNode* edge = m_edges[v1];
    EdgeNode* previousEdge = nullptr;
    while (edge) {
        if (edge->otherVertex() == v2) {
            if (previousEdge) {
                previousEdge->setNext(edge->next());
            } else {
                m_edges[v1] = edge->next();
            }
            delete edge;
            break;
        }
        previousEdge = edge;
        edge = edge->next();
    }
}

void GraphAdjList::print() {
    for (int i = 0; i < m_numVertices; ++i) {
        EdgeNode* edge = m_edges[i];
        std::cout << "Vertex " << i << ":";
        while (edge) {
            std::cout << " (" << i << "," << edge->otherVertex() << ", weight: " << edge->weight() << ")";
            edge = edge->next();
        }
        std::cout << std::endl;
    }
}

EdgeNode** GraphAdjList::edges() {
    return m_edges;
}

bool GraphAdjList::isSubGraph(GraphAdjList &h) {
    EdgeNode** hEdges = h.edges();
    for (int i = 0; i < m_numVertices; ++i) {
        EdgeNode* hEdge = hEdges[i];
        while (hEdge) {
            EdgeNode* gEdge = m_edges[i];
            bool found = false;
            while (gEdge) {
                if (hEdge->otherVertex() == gEdge->otherVertex()) {
                    found = true;
                    break;
                }
                gEdge = gEdge->next();
            }
            if (!found) {
                return false;
            }
            hEdge = hEdge->next();
        }
    }
    return true;
}

bool GraphAdjList::isTopological() {
    for (int i = 0; i < m_numVertices; ++i) {
        EdgeNode* edge = m_edges[i];
        while (edge) {
            if (edge->otherVertex() <= i) {
                return false;
            }
            edge = edge->next();
        }
    }
    return true;
}

// Retorna o número de vértices
int GraphAdjList::getV() {
    return m_numVertices;
}

EdgeNode** GraphAdjList::getE() {
    return m_edges;
}

EdgeNode* GraphAdjList::getAdj(int vertex) {
    if (vertex >= 0 && vertex < m_numVertices) {
        return m_edges[vertex];
    } else {
        return nullptr; // Retorna nullptr se o vértice não for válido
    }
}