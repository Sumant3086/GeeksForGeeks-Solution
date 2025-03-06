// Longest Common Subsequence
// Difficulty: MediumAccuracy: 41.68%Submissions: 301K+Points: 4
// Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

// A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

// Examples:

// Input: s1 = "ABCDGH", s2 = "AEDFHR"
// Output: 3
// Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.
// Input: s1 = "ABC", s2 = "AC"
// Output: 2
// Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.
// Input: s1 = "XYZW", s2 = "XYWZ"
// Output: 3
// Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.
// Constraints:
// 1<= s1.size(), s2.size() <=103
// Both strings s1 and s2 contain only uppercase English letters.

// Company Tags
// PaytmVMWareAmazonMicrosoftCitrixMakeMyTrip
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.

class Solution {
    public:
      int lcs(string &s1, string &s2) {
          // code here
           int m = s1.size(), n = s2.size();
          vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
          
          for (int i = 1; i <= m; i++)
              for (int j = 1; j <= n; j++)
                  dp[i][j] = s1[i-1] == s2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
      
          return dp[m][n];
      }
  };