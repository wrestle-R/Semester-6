#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    explicit Graph(int vertices) : adjacency(vertices) {}

    void addEdge(int first, int second) {
        adjacency[first].push_back(second);
        adjacency[second].push_back(first);
    }

    int countConnectedComponents() const {
        vector<bool> visited(adjacency.size(), false);
        int components = 0;

        for (int vertex = 0; vertex < (int)adjacency.size(); ++vertex) {
            if (!visited[vertex]) {
                ++components;
                depthFirstSearch(vertex, visited);
            }
        }

        return components;
    }

private:
    void depthFirstSearch(int vertex, vector<bool>& visited) const {
        visited[vertex] = true;
        for (int neighbor : adjacency[vertex]) {
            if (!visited[neighbor]) {
                depthFirstSearch(neighbor, visited);
            }
        }
    }

    vector<vector<int>> adjacency;
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    cout << "Number of connected components = " << graph.countConnectedComponents() << endl;

    return 0;
}