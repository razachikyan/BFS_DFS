#include "./Graph.hpp"

Graph::Graph(const std::string& path) : path(path) {}

void Graph::printGraphData() const {
    for(int i = 0; i < graphData.size(); ++i) {
        std::cout << i + 1 << " - {";
        for(int j = 0; j < graphData[i].size(); ++j) {
            std::cout << ' ' << graphData[i][j] << ' ';
        }
        std::cout << "}\n";
    }
}

void Graph::inputGraphData() {
    std::ifstream inputFile(path);
    std::vector<int> gagatner;
    std::string line;
    std::regex pattern(R"(^\d(-\{(\d+(,\d+)*)?\})?$)");
    if (!inputFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }
    if(inputFile.is_open()) {
        while (!inputFile.eof()) {
            getline (inputFile ,line);
            if(!std::regex_match(line, pattern)) {
                std::cerr << "Formatd qunem ay invalid gandon normal gra" << std::endl;
                return;
            }
            for(int i = 3; i < line.length(); ++i) {
                std::string num;
                while(line[i] != ',' && line[i] != '}') num += line[i++];
                gagatner.push_back(std::stoi(num));
            }
            graphData.push_back(gagatner);
            gagatner = {};
        }
    }
    inputFile.close();
}

void Graph::BFS(int startVertex) {
    int numVertices = graphData.size();
    std::vector<bool> visited(numVertices, false);
    std::queue<int> queue;

    visited[startVertex - 1] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        // Dequeue a vertex from the queue
        int currentVertex = queue.front();
        queue.pop();

        // Process the current vertex (in this example, we'll just print it)
        std::cout << currentVertex << " ";

        // Enqueue all the unvisited neighboring vertices
        for (int neighbor : graphData[currentVertex - 1]) {
            if (!visited[neighbor - 1]) {
                visited[neighbor - 1] = true;
                queue.push(neighbor);
            }
        }
    }
}

void Graph::DFS(int startVertex) {
    int numVertices = graphData.size();
    std::vector<bool> visited(numVertices, false);
    std::stack<int> stack;

    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();
        if (visited[currentVertex - 1]) continue;
        visited[currentVertex - 1] = true;
        std::cout << currentVertex << " ";

        for (int neighbor : graphData[currentVertex - 1]) {
            if (!visited[neighbor - 1]) {
                stack.push(neighbor);
            }
        }
    }
};