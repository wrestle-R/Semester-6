#include <bits/stdc++.h>
using namespace std;

void dutchNationalFlagSort(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = (int)nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            ++low;
            ++mid;
        } else if (nums[mid] == 1) {
            ++mid;
        } else {
            swap(nums[mid], nums[high]);
            --high;
        }
    }
}

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i + 1 != nums.size()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    printVector(nums);
    dutchNationalFlagSort(nums);
    cout << "After sorting: ";
    printVector(nums);

    return 0;
}