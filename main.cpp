#include <iostream>
#include "./Graph/Graph.hpp"

int main() {
    Graph graph1 = Graph("./Graph.txt");
    graph1.inputGraphData();
    graph1.printGraphData();
    graph1.BFS(1);
    std::cout << std::endl;
    graph1.DFS(1);
    system("pause");
    return 0;
}