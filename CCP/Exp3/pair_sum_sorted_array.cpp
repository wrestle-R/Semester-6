#include <bits/stdc++.h>
using namespace std;

bool findPairWithGivenSum(const vector<int>& nums, int target, pair<int, int>& result) {
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            result = {nums[left], nums[right]};
            return true;
        }

        if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 4, 7, 11, 15};
    int target = 15;
    pair<int, int> result;

    if (findPairWithGivenSum(nums, target, result)) {
        cout << "Pair found (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "No such pair exists" << endl;
    }

    return 0;
}