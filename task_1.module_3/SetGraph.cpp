#include "SetGraph.h"

SetGraph::SetGraph(int size): size(size), adjacencySets(size) {}

SetGraph::SetGraph(const IGraph& other): adjacencySets(other.VerticesCount()) {
    size = other.VerticesCount();
    for (int i = 0; i < size; i++ ) {
        auto next_verticle = other.GetNextVertices(i);
        for (int adj_verticies : next_verticle) {
            AddEdge(i, adj_verticies);
        }
    }
}

SetGraph::~SetGraph(){
    }

void SetGraph::AddEdge(int from, int to) { adjacencySets[from].insert(to); }

int SetGraph::VerticesCount() const { return size; }

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev_verticies;
    for (int i = 0; i < size; i++ ) {
        if (adjacencySets[i].find(vertex) != adjacencySets[i].end()) {
            prev_verticies.push_back(i);
        }
    }
    return prev_verticies;
}
