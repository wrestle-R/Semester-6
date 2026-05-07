#include <bits/stdc++.h>
using namespace std;

class TopKFrequentStream {
public:
    void add(int value) {
        int currentFrequency = frequency[value];
        if (currentFrequency > 0) {
            ranking.erase({-currentFrequency, value});
        }

        frequency[value] = currentFrequency + 1;
        ranking.insert({-frequency[value], value});
    }

    vector<int> topK(int k) const {
        vector<int> result;
        for (auto it = ranking.begin(); it != ranking.end() && (int)result.size() < k; ++it) {
            result.push_back(it->second);
        }
        return result;
    }

private:
    unordered_map<int, int> frequency;
    set<pair<int, int>> ranking;
};

void printVector(const vector<int>& values) {
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
    TopKFrequentStream stream;
    vector<int> incomingValues = {5, 2, 5, 3, 5, 2, 4, 2};
    int k = 3;

    for (int value : incomingValues) {
        stream.add(value);
        cout << "After inserting " << value << ", top " << k << " elements are: ";
        printVector(stream.topK(k));
    }

    cout << "Ordering rule: higher frequency first, then smaller value on ties." << endl;

    return 0;
}