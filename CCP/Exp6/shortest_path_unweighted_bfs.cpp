#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    explicit Graph(int vertices) : adjacency(vertices) {}

    void addEdge(int first, int second) {
        adjacency[first].push_back(second);
        adjacency[second].push_back(first);
    }

    vector<int> shortestPathFromSource(int source) const {
        vector<int> distance(adjacency.size(), -1);
        queue<int> pending;

        distance[source] = 0;
        pending.push(source);

        while (!pending.empty()) {
            int current = pending.front();
            pending.pop();

            for (int neighbor : adjacency[current]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[current] + 1;
                    pending.push(neighbor);
                }
            }
        }

        return distance;
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
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    vector<int> distance = graph.shortestPathFromSource(0);

    cout << "Shortest distances from source 0: ";
    printVector(distance);

    return 0;
}