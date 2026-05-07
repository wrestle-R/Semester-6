#include <bits/stdc++.h>
using namespace std;

int maxSumSubarrayOfSizeK(const vector<int>& nums, int k) {
    if (k <= 0 || nums.empty() || k > (int)nums.size()) {
        return 0;
    }

    int windowSum = 0;
    for (int i = 0; i < k; ++i) {
        windowSum += nums[i];
    }

    int bestSum = windowSum;
    for (int right = k; right < (int)nums.size(); ++right) {
        windowSum += nums[right] - nums[right - k];
        bestSum = max(bestSum, windowSum);
    }

    return bestSum;
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << "Maximum sum of subarray of size " << k << " = " << maxSumSubarrayOfSizeK(nums, k) << endl;

    return 0;
}