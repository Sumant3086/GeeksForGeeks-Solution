// Introduction to DP
// Difficulty: MediumAccuracy: 46.1%Submissions: 70K+Points: 4
// Geek is learning data structures, and he recently learned about the top-down and bottom-up dynamic programming approaches. Geek is having trouble telling them apart from one another.

// When given an integer n, where n is based on a 0-based index, find the nth Fibonacci number.

// Every ith number in the series equals the sum of the (i-1)th and (i-2)th numbers, where the first and second numbers are specified as 0 and 1, respectively.

// For the given issue, code both top-down and bottom-up approaches.

// Note : As the answer might be large, return the final answer modulo 109 + 7

// Example 1:

// Input:
// n = 5
// Output: 5
// Explanation: 0,1,1,2,3,5 as we can see 5th number is 5.
// Example 2:

// Input:
// n = 6
// Output: 8
// Explanation: 0,1,1,2,3,5,8 as we can see 6th number is 8.
// Constraints:
// 1 <= n <= 104

// Your Task:
// You don't need to read input or print anything. Your task is to complete two functions topDown() and bottomUp() which take n as input parameters and return the nth Fibonacci number.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Topic Tags
// Related Articles


 public:
    int MOD=1e9+7;
    long long int fib(int n,vector<long long int>&dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=(fib(n-1,dp)+fib(n-2,dp))%MOD;
        return dp[n];
    }
    long long int topDown(int n) {
    vector<long long int>dp(n+1,-1);
        return fib(n,dp);
        // code here
    }
long long int bottomUp(int n) {
        // code here
    vector<long long int>dp(n+1,0);
        if(n<=1){
            return n;
        }
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%MOD;
        }
        return dp[n];
    }