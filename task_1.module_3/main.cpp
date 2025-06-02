#include <iostream>
#include <vector>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

int main()
{
    //создаем граф вида: http://graphonline.ru/?graph=DZVxkLpKiNpbiLep
    IGraph* graph = new ListGraph(7);
    graph->AddEdge(0, 1);
    graph->AddEdge(0, 2);
    graph->AddEdge(0, 5);
    graph->AddEdge(1, 4);
    graph->AddEdge(2, 1);
    graph->AddEdge(2, 3);
    graph->AddEdge(3, 5);
    graph->AddEdge(5, 4);
    graph->AddEdge(5, 6);
    graph->AddEdge(6, 4);
    
    std::cout << "BFS ";
    graph->mainBFS([](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    std::cout << "DFS ";
    graph->mainDFS([](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    std::cout << "topological sort ";
    auto order = graph->topologicalSort();
    for (int vertex : order) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    MatrixGraph matrixGraph(*graph);
    std::cout << "matrixgraph BFS ";
    matrixGraph.mainBFS([](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    ArcGraph arcGraph(matrixGraph);
    std::cout << "arcgraph BFS ";
    arcGraph.mainBFS([](int v) { std::cout << v << " "; });
    std::cout << std::endl;

    SetGraph setGraph(arcGraph);
    std::cout << "setgraph BFS  ";
    setGraph.mainBFS([](int v) { std::cout << v << " "; });
    std::cout << std::endl;
    
    delete graph;

}
