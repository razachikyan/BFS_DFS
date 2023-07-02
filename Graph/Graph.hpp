#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <regex>

using graph = std::vector<std::vector<int>>;

class Graph {
private:
    graph graphData;
    std::string path;
public:
    Graph(const std::string& path);
    void printGraphData() const;
    void inputGraphData();
    void BFS(int startVertex);
    void DFS(int startVertex);
};


#endif