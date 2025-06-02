#include "ArcGraph.h"

ArcGraph::ArcGraph(int size): size(size) {}

ArcGraph::ArcGraph(const IGraph& other) {
    size = other.VerticesCount();
    for (int i = 0; i < size; i++) {
        std::vector<int> next_vertices = other.GetNextVertices(i);
        for (int adj_vertices : next_vertices) { AddEdge(i, adj_vertices); }
    }
}
ArcGraph::~ArcGraph(){
    }
void ArcGraph::AddEdge(int from, int to) {
    edges.push_back(std::pair(from, to));
}
int ArcGraph::VerticesCount() const { return size; }

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> next_vertices;
    for (const std::pair<int,int>& edge: edges) {
        if (edge.first == vertex) {
            next_vertices.push_back(edge.second);
        }
    }
    return next_vertices;
}
std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> prev_vertices;
    for (const std::pair<int,int>& edge: edges) {
        if (edge.second == vertex) {
            prev_vertices.push_back(edge.first);
        }
    }
    return prev_vertices;
}
