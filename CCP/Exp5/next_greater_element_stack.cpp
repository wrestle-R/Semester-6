#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(const vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    stack<int> pendingIndices;

    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!pendingIndices.empty() && nums[pendingIndices.top()] < nums[i]) {
            result[pendingIndices.top()] = nums[i];
            pendingIndices.pop();
        }

        pendingIndices.push(i);
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
    vector<int> nums = {4, 5, 2, 25};
    vector<int> result = nextGreaterElements(nums);

    cout << "Next greater elements: ";
    printVector(result);

    return 0;
}