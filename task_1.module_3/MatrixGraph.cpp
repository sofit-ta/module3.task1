#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size): size(size), adjacencyMatrix(size, std::vector<bool>(size, false)) {}

MatrixGraph::MatrixGraph(const IGraph& other): adjacencyMatrix(other.VerticesCount(), std::vector<bool>(other.VerticesCount(), false)) {
    size = other.VerticesCount();
    for (int i = 0; i < size; i++ ) {
        auto next_vertices = other.GetNextVertices(i);
        for (int j : next_vertices) {
            AddEdge(i, j);
        }
    }
}
MatrixGraph::~MatrixGraph(){
    }

void MatrixGraph::AddEdge(int from, int to) { adjacencyMatrix[from][to] = true; }

int MatrixGraph::VerticesCount() const { return size; }

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> next_vertices;
    for (int i = 0; i < size; i++ ) {
        if (adjacencyMatrix[vertex][i]) {
            next_vertices.push_back(i);
        }
    }
    return next_vertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int i = 0; i < size; ++i) {
        if (adjacencyMatrix[i][vertex]) {
            result.push_back(i);
        }
    }
    return result;
}
