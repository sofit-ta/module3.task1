#ifndef IGRAPH_H
#define IGRAPH_H

#include <iostream>
#include <vector>


struct IGraph {
    virtual ~IGraph() {}
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const = 0;
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
    
    void topologicalSortInternal(int vertex, std::vector<bool> &visited, std::deque<int> &sorted);
    std::deque<int> topologicalSort();
    void DFS(int vertex, std::vector<bool> &visited, const std::function<void(int)> &func);
    void mainDFS(const std::function<void(int)> &func);
    void BFS(int vertex, std::vector<bool> &visited, const std::function<void(int)> &func);
    void mainBFS(const std::function<void(int)> &func);
};

#endif
