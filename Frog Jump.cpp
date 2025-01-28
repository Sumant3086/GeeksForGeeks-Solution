// Frog Jump
// Difficulty: MediumAccuracy: 49.55%Submissions: 108K+Points: 4
// Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

// Example:

// Input: heights[] = [20, 30, 40, 20] 
// Output: 20
// Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20-30|  = 10
// Total Cost = 10 + 10 = 20
// Input: heights[] = [30, 20, 50, 10, 40]
// Output: 30
// Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
// jump from stair 0 to 2: cost = |50 - 30| = 20
// jump from stair 2 to 4: cost = |40-50|  = 10
// Total Cost = 20 + 10 = 30
// Constraints:

// 1 <= height.size() <= 105
// 0 <= height[i]<=104
// Topic Tags
// Related Articles
// Expected Complexities


class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,0);
        // dp[0]=0;
        int prev=0;
        int prev2=0;
        int curr=0;
        for(int i=1;i<n;i++){
            int left=prev+abs(height[i]-height[i-1]);
            int right=INT_MAX;
            if(i>=2){
                right=prev2+abs(height[i]-height[i-2]);
            }
            curr=min(left,right);
            prev2=prev;
            prev=curr;
        }
        // return dp[n-1];
        return prev;
    }
};
// class Solution {
//   public:
//     int minCost(vector<int>& height) {
//         // Code here
//         int n=height.size();
//         vector<int>dp(n,0);
//         dp[0]=0;
//         for(int i=1;i<n;i++){
//             int left=dp[i-1]+abs(height[i]-height[i-1]);
//             int right=INT_MAX;
//             if(i>=2){
//                 right=dp[i-2]+abs(height[i]-height[i-2]);
//             }
//             dp[i]=min(left,right);
//         }
//         return dp[n-1]; 
//     }
// };
// class Solution {
//   public:
//   int helper(int idx,vector<int>& height,vector<int>& dp){
//       if(idx==0)return 0;
//       if(dp[idx]!=-1){
//           return dp[idx];
//       }
//       int left=helper(idx-1,height,dp)+abs(height[idx]-height[idx-1]);
//       int right=INT_MAX;
//       if(idx>1){
//           right=helper(idx-2,height,dp)+abs(height[idx]-height[idx-2]);
//       }
//       return dp[idx]=min(left,right);
//   }
//     int minCost(vector<int>& height) {
//         // Code here
//         int n=height.size();
//         vector<int>dp(n+1,-1);
//         return helper(n-1,height,dp);
//     }
// };
// class Solution {
//   public:
//   int helper(int idx,vector<int>& height){
//       if(idx==0)return 0;
//       int left=helper(idx-1,height)+abs(height[idx]-height[idx-1]);
//       int right=INT_MAX;
//       if(idx>1){
//           right=helper(idx-2,height)+abs(height[idx]-height[idx-2]);
//       }
//       return min(left,right);
//   }
//     int minCost(vector<int>& height) {
//         // Code here
//         int n=height.size();
//         return helper(n-1,height);
//     }
// };