#include <bits/stdc++.h>
using namespace std;

struct Entry {
    int priority;
    int value;
};

struct EntryComparator {
    bool operator()(const Entry& left, const Entry& right) const {
        if (left.priority == right.priority) {
            return left.value < right.value;
        }

        return left.priority < right.priority;
    }
};

class PriorityQueueHeap {
public:
    void push(int value, int priority) {
        heap.push({priority, value});
    }

    bool empty() const {
        return heap.empty();
    }

    Entry top() const {
        return heap.top();
    }

    void pop() {
        heap.pop();
    }

private:
    priority_queue<Entry, vector<Entry>, EntryComparator> heap;
};

int main() {
    PriorityQueueHeap queue;
    queue.push(10, 2);
    queue.push(40, 5);
    queue.push(25, 3);
    queue.push(50, 5);

    cout << "Removal order by priority: ";
    while (!queue.empty()) {
        Entry current = queue.top();
        queue.pop();
        cout << "(" << current.value << ", priority=" << current.priority << ") ";
    }
    cout << endl;

    cout << "Insert and delete operations run in O(log n)." << endl;

    return 0;
}