#include <bits/stdc++.h>
using namespace std;

int countOccurrences(const vector<int>& nums, int target) {
    int count = 0;
    for (int value : nums) {
        if (value == target) {
            ++count;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {2, 4, 2, 8, 2, 6, 2};
    int target = 2;

    cout << "Occurrences of " << target << " = " << countOccurrences(nums, target) << endl;

    return 0;
}