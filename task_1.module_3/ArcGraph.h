#ifndef ARCGRAPH_H
#define ARCGRAPH_H

#include "IGraph.h"
#include <vector>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int size);
    ArcGraph(const IGraph& other);
    ~ArcGraph();
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int size;
    std::vector<std::pair<int, int>> edges;
};

#endif
