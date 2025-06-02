#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include "IGraph.h"
#include <vector>

class ListGraph : public IGraph {
public:
    explicit ListGraph(int size);
    ListGraph(const IGraph& graph);
    ~ListGraph();

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};

#endif
