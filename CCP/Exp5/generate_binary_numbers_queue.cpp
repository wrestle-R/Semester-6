#include <bits/stdc++.h>
using namespace std;

vector<string> generateBinaryNumbers(int count) {
    queue<string> pending;
    vector<string> result;

    pending.push("1");
    for (int i = 0; i < count; ++i) {
        string current = pending.front();
        pending.pop();
        result.push_back(current);
        pending.push(current + "0");
        pending.push(current + "1");
    }

    return result;
}

void printVector(const vector<string>& values) {
    cout << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        cout << values[i];
        if (i + 1 != values.size()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int count = 10;
    vector<string> binaries = generateBinaryNumbers(count);

    cout << "Binary numbers from 1 to " << count << ": ";
    printVector(binaries);

    return 0;
}