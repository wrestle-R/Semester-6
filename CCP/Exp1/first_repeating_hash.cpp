#include <bits/stdc++.h>
using namespace std;

int firstRepeatingHash(const vector<int>& nums) {
    unordered_set<int> seen;

    for (int i = (int)nums.size() - 1; i >= 0; --i) {
        if (seen.count(nums[i])) {
            return nums[i];
        }

        seen.insert(nums[i]);
    }

    return -1;
}

int main() {
    vector<int> nums = {10, 5, 3, 4, 3, 5, 6};

    int repeated = firstRepeatingHash(nums);
    if (repeated != -1) {
        cout << "First repeating element = " << repeated << endl;
    } else {
        cout << "No repeating element found" << endl;
    }

    return 0;
}