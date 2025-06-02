#ifndef SETGRAPH_H
#define SETGRAPH_H

#include "IGraph.h"
#include <set>
#include <vector>

class SetGraph : public IGraph {
public:
    explicit SetGraph(int size);
    SetGraph(const IGraph& other);
    ~SetGraph();
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int size;
    std::vector<std::set<int>> adjacencySets;
};

#endif
