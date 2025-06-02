
#include "IGraph.h"
#include <functional>
#include <deque>
#include <queue>

//функции обходов, общие для всех видов графов

void IGraph::topologicalSortInternal(int vertex, std::vector<bool> &visited, std::deque<int> &sorted) {
    visited[vertex] = true;
    for (int next : GetNextVertices(vertex)) {
        if (!visited[next]) {
            topologicalSortInternal(next, visited, sorted);
        }
    }
    sorted.push_front(vertex);
}

std::deque<int> IGraph::topologicalSort() {
    std::deque<int> sorted;
    std::vector<bool> visited(VerticesCount(), false);
    for (int i = 0; i < VerticesCount(); ++i) {
        if (!visited[i]) {
            topologicalSortInternal(i, visited, sorted);
        }
    }
    return sorted;
}

void IGraph::DFS(int vertex, std::vector<bool> &visited, const std::function<void(int)> &func) {
    visited[vertex] = true;
    func(vertex);
    for (int next : GetNextVertices(vertex)) {
        if (!visited[next]) {
            DFS(next, visited, func);
        }
    }
}

void IGraph::mainDFS(const std::function<void(int)> &func) {
    std::vector<bool> visited(VerticesCount(), false);
    for (int i = 0; i < VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(i, visited, func);
        }
    }
}

void IGraph::BFS(int vertex, std::vector<bool> &visited, const std::function<void(int)> &func) {
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        int current = qu.front();
        qu.pop();

        func(current);

        for (int next: GetNextVertices(current)) {
            if (!visited[next]) {
                visited[next] = true;
                qu.push(next);
            }
        }
    }
}

void IGraph::mainBFS(const std::function<void(int)> &func) {
    std::vector<bool> visited(VerticesCount(), false);
    for (int i = 0; i < VerticesCount(); ++i) {
        if (!visited[i]) {
            BFS(i, visited, func);
        }
    }
}
