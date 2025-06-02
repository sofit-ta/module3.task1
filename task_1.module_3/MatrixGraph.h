#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

#include "IGraph.h"
#include <vector>

class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int size);
    MatrixGraph(const IGraph& other);
    ~MatrixGraph();
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int size;
    std::vector<std::vector<bool>> adjacencyMatrix;
};

#endif
