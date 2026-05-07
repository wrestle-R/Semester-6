#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    explicit Graph(int vertices) : adjacency(vertices) {}

    void addEdge(int from, int to) {
        adjacency[from].push_back(to);
    }

    vector<int> topologicalSortKahn(bool& hasCycle) const {
        vector<int> indegree(adjacency.size(), 0);
        for (const auto& neighbors : adjacency) {
            for (int neighbor : neighbors) {
                ++indegree[neighbor];
            }
        }

        queue<int> pending;
        for (int vertex = 0; vertex < (int)adjacency.size(); ++vertex) {
            if (indegree[vertex] == 0) {
                pending.push(vertex);
            }
        }

        vector<int> order;
        while (!pending.empty()) {
            int current = pending.front();
            pending.pop();
            order.push_back(current);

            for (int neighbor : adjacency[current]) {
                --indegree[neighbor];
                if (indegree[neighbor] == 0) {
                    pending.push(neighbor);
                }
            }
        }

        hasCycle = (order.size() != adjacency.size());
        return order;
    }

private:
    vector<vector<int>> adjacency;
};

void printVector(const vector<int>& values) {
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    Graph graph(6);
    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    bool hasCycle = false;
    vector<int> order = graph.topologicalSortKahn(hasCycle);

    if (hasCycle) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "One possible topological order: ";
        printVector(order);
    }

    return 0;
}