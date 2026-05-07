#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMinimum(const vector<int>& nums, int k) {
    if (k <= 0 || nums.empty() || k > (int)nums.size()) {
        return {};
    }

    deque<int> indices;
    vector<int> result;

    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!indices.empty() && indices.front() <= i - k) {
            indices.pop_front();
        }

        while (!indices.empty() && nums[indices.back()] >= nums[i]) {
            indices.pop_back();
        }

        indices.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[indices.front()]);
        }
    }

    return result;
}

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
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMinimum(nums, k);
    cout << "Sliding window minimums: ";
    printVector(result);

    return 0;
}