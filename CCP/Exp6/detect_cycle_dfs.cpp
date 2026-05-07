#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    explicit Graph(int vertices) : adjacency(vertices) {}

    void addEdge(int from, int to) {
        adjacency[from].push_back(to);
    }

    bool hasCycle() const {
        vector<bool> visited(adjacency.size(), false);
        vector<bool> recursionStack(adjacency.size(), false);

        for (int vertex = 0; vertex < (int)adjacency.size(); ++vertex) {
            if (!visited[vertex] && depthFirstSearch(vertex, visited, recursionStack)) {
                return true;
            }
        }

        return false;
    }

private:
    bool depthFirstSearch(int vertex, vector<bool>& visited, vector<bool>& recursionStack) const {
        visited[vertex] = true;
        recursionStack[vertex] = true;

        for (int neighbor : adjacency[vertex]) {
            if (!visited[neighbor] && depthFirstSearch(neighbor, visited, recursionStack)) {
                return true;
            }

            if (recursionStack[neighbor]) {
                return true;
            }
        }

        recursionStack[vertex] = false;
        return false;
    }

    vector<vector<int>> adjacency;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);

    cout << (graph.hasCycle() ? "Graph contains a cycle" : "Graph does not contain a cycle") << endl;

    return 0;
}