// LCS of three strings
// Difficulty: MediumAccuracy: 48.52%Submissions: 82K+Points: 4
// Given three strings s1, s2, and s3 containing uppercase letters, lowercase letters, and digits, find the length of longest common sub-sequence in all three given strings.

// Examples:

// Input: s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks"
// Output: 5
// Explanation: "geeks"is the longest common subsequence with length 5.
// Input: s1 = "abcd1e2", s2 = "bc12ea", s3 = "bd1ea"
// Output: 3
// Explanation:  Longest common subsequence is "b1e" i.e. length = 3.
// Constraints:
// 1  ≤  s1.size(), s2.size(), s3.size()  ≤  100

// Expected Complexities
// Company Tags
// DE Shaw
// Topic Tags
// Related Interview Experiences
// Related Articles
// If you are facing any issue on this page. Please let us know.


class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                for (int k = 1; k <= n3; k++) {
                    if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) {
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    } else {
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                    }
                }
            }
        }

        return dp[n1][n2][n3];
    }
};
