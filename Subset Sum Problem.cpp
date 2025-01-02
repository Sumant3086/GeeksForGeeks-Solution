// Subset Sum Problem
// Difficulty: MediumAccuracy: 32.0%Submissions: 293K+Points: 4
// Given an array of positive integers, arr[] and a value, target, determine if there is a subset of the given set with sum equal to given target. 

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
// Input: arr[] = [3, 34, 4, 12, 5, 2, target = 30
// Output: false
// Explanation: There is no subset with target sum 30.
// Input: arr[] = [1, 2, 3], sum = 6
// Output: true
// Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
// Constraints:
// 1 <= arr.size() <= 200
// 1<= arr[i] <= 200
// 1<= sum <= 4*104

// Company Tags
// AmazonMicrosoft
// Topic Tags
// Related Interview Experiences
// Amazon Interview Experience For Sde
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today!  

// banner

// class Solution {
//   public:
//     bool helper(vector<int>& arr,int n,int target){
        
//         if(n==0){
//             return(target==0)?true:false;
//         }
//         return helper(arr,n-1,target)||helper(arr,n-1,target-arr[n-1]);
//     }
//     bool isSubsetSum(vector<int>& arr, int target) {
//         // code here
//         return helper(arr,arr.size(),target);
//     }
// };
class Solution {
  public:
    bool helper(vector<int>& arr,int n,int target,vector<vector<int>>& dp){
        
        if(n==0){
            return(target==0)?true:false;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        if(arr[n-1]>target){
            return dp[n][target]=helper(arr,n-1,target,dp); 
        }
        return dp[n][target]=helper(arr,n-1,target,dp)||helper(arr,n-1,target-arr[n-1],dp);
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(arr,n,target,dp);
    }
};