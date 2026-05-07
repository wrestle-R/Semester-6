#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringWithoutRepeating(const string& text) {
    unordered_map<char, int> lastSeen;
    int left = 0;
    int bestLength = 0;

    for (int right = 0; right < (int)text.size(); ++right) {
        char current = text[right];
        if (lastSeen.count(current)) {
            left = max(left, lastSeen[current] + 1);
        }

        lastSeen[current] = right;
        bestLength = max(bestLength, right - left + 1);
    }

    return bestLength;
}

int main() {
    string text = "abcabcbb";
    cout << "Longest substring without repeating characters = "
         << lengthOfLongestSubstringWithoutRepeating(text) << endl;
    return 0;
}