
#include <bits/stdc++.h>
using namespace std;

int linearSearch(const vector<int>& nums, int target) {
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (nums[i] == target) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {5, 9, 2, 7, 1, 6};
    int target = 7;

    int index = linearSearch(nums, target);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}