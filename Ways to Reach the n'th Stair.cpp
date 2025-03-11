// Ways to Reach the n'th Stair
// Difficulty: MediumAccuracy: 21.9%Submissions: 216K+Points: 4
// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).

// Examples:

// Input: n = 1
// Output: 1
// Explanation: There is only one way to climb 1 stair. 
// Input: n = 2
// Output: 2
// Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}.  
// Input: n = 4
// Output: 5
// Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.
// Constraints:
// 1 ≤ n ≤ 44

// Company Tags
// FlipkartAmazonMicrosoftOYO RoomsAdobe
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
class Solution {
    public:
      int countWays(int n) {
          // your code here
          int dp[n+1]; 
          dp[0]=1;
          dp[1]=1;
          for(int i=2;i<=n;i++){
              dp[i]=dp[i-1]+dp[i-2];
          }
          return dp[n];
      }
  };