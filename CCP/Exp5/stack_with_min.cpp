#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    void push(int value) {
        values.push(value);
        if (minimums.empty() || value <= minimums.top()) {
            minimums.push(value);
        }
    }

    void pop() {
        if (values.empty()) {
            return;
        }

        if (values.top() == minimums.top()) {
            minimums.pop();
        }

        values.pop();
    }

    int top() const {
        return values.top();
    }

    int getMin() const {
        return minimums.top();
    }

    bool empty() const {
        return values.empty();
    }

private:
    stack<int> values;
    stack<int> minimums;
};

int main() {
    MinStack stack;
    for (int value : {5, 3, 7, 2}) {
        stack.push(value);
        cout << "Pushed " << value << ", current min = " << stack.getMin() << endl;
    }

    cout << "Top element = " << stack.top() << endl;
    stack.pop();
    cout << "After one pop, current min = " << stack.getMin() << endl;

    return 0;
}