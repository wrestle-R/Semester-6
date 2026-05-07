#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    explicit Graph(int vertices) : adjacency(vertices) {}

    void addEdge(int first, int second) {
        adjacency[first].push_back(second);
        adjacency[second].push_back(first);
    }

    bool isBipartite() const {
        vector<int> color(adjacency.size(), -1);

        for (int start = 0; start < (int)adjacency.size(); ++start) {
            if (color[start] != -1) {
                continue;
            }

            queue<int> pending;
            pending.push(start);
            color[start] = 0;

            while (!pending.empty()) {
                int current = pending.front();
                pending.pop();

                for (int neighbor : adjacency[current]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[current];
                        pending.push(neighbor);
                    } else if (color[neighbor] == color[current]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

private:
    vector<vector<int>> adjacency;
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    cout << (graph.isBipartite() ? "Graph is Bipartite" : "Graph is not Bipartite") << endl;

    return 0;
}