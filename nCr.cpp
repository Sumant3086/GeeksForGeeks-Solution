// nCr
// Difficulty: MediumAccuracy: 14.82%Submissions: 324K+Points: 4
// Given two integer values n and r, the task is to find the value of Binomial Coefficient nCr

// A binomial coefficient nCr can be defined as the coefficient of xr in the expansion of (1 + x)n that gives the number of ways to choose r objects from a set of n objects without considering the order.
// The binomial coefficient nCr is calculated as : C(n,r) = n! / r! * (n-r) !
// Note: If r is greater than n, return 0.
// It is guaranteed that the value of nCr will fit within a 32-bit integer.

// Examples:

// Input: n = 5, r = 2
// Output: 10
// Explaination: The value of 5C2 is calculated as 5!/(5−2)!*2! = 5!/3!*2! = 10.
// Input: n = 2, r = 4
// Output: 0
// Explaination: Since r is greater than n, thus 2C4 = 0
// Input: n = 5, r = 0
// Output: 1
// Explaination: The value of 5C0 is calculated as 5!/(5−0)!*0! = 5!/5!*0! = 1.
// Constraints:
// 1 ≤ n ≤ 100
// 1 ≤ r ≤ 100

// Expected Complexities
// Topic Tags
// Related Articles
// If you are facing any issue on this page. Please let u


class Solution {
    public:
      int nCr(int n, int r) {
          // code here
          if(n<r) return 0;
          if((n-r)<r) r= n-r;  
          int MOD = 1000000007;
          
          int dp[r+1]; //1 available in every col 
          memset(dp, 0, sizeof(dp));
          dp[0] = 1;  //starting from 1
          for(int i=1; i<=n; i++){
              for(int j= min(r,i); j>0; j--){
                  dp[j] = (dp[j] + dp[j-1])%MOD;
              }
          }
          return dp[r];
      }
  };