// 3170. Lexicographically Minimum String After Removing Stars
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

// While there is a '*', do the following operation:

// Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
// Return the lexicographically smallest resulting string after removing all '*' characters.

 

// Example 1:

// Input: s = "aaba*"

// Output: "aab"

// Explanation:

// We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

// Example 2:

// Input: s = "abc"

// Output: "abc"

// Explanation:

// There is no '*' in the string.

 

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters and '*'.
// The input is generated such that it is possible to delete all '*' characters.

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 88,405/180.5K
// Acceptance Rate
// 49.0%
// Topics
// icon
// Companies
// Discussion (174)

// Choose a type



// Copyright © 2025 LeetCode. All rights reserved.


class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> freq(26);
        int a = 'a';

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (!freq[j].empty()) {
                        freq[j].pop_back();
                        break;
                    }
                }
            } else {
                freq[s[i] - a].push_back(i);
            }
        }

        vector<bool> keep(s.size(), false);
        for (const auto& stack : freq) {
            for (int idx : stack) {
                keep[idx] = true;
            }
        }

        string result;
        for (int i = 0; i < s.size(); i++) {
            if (keep[i]) result += s[i];
        }
        return result;
    }
};