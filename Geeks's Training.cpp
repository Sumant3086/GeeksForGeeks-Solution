// Geek's Training
// Difficulty: MediumAccuracy: 49.98%Submissions: 97K+Points: 4
// Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

// Example:

// Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
// Output: 11
// Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
// Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
// Output: 6
// Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.
// Input: arr[]= [[4, 2, 6]]
// Output: 6
// Explanation: Geek will learn a new move to make his merit points as 6.
// Constraint:
// 1 <=  n <= 105   
// 1 <=  arr[i][j] <= 100

// Topic Tags
// Related Articles
// Expected Complexities




class Solution {
  public:
    int backTrack(vector<vector<int>> &arr,int n,int lastAct,int day,vector<vector<int>> &dp){
        if(day>=n)return 0;
        if(dp[day][lastAct]!=-1){
            return dp[day][lastAct];
        }
        int maxi=0;
        for(int i=0;i<3;i++){
            int totPoints=0;
            int currPoints=0;
            if(i!=lastAct){
                currPoints=arr[day][i];
            }
            totPoints=currPoints+backTrack(arr,n,i,day+1,dp);
            maxi=max(maxi,totPoints);
        }
        return dp[day][lastAct]=maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(3+1,-1));
        return backTrack(arr,n,3,0,dp);
    }
};
// class Solution {
//   public:
//     int backTrack(vector<vector<int>> &arr,int n,int lastAct,int day){
//         if(day>=n)return 0;
//         int maxi=0;
//         for(int i=0;i<3;i++){
//             int totPoints=0;
//             int currPoints=0;
//             if(i!=lastAct){
//                 currPoints=arr[day][i];
//             }
//             totPoints=currPoints+backTrack(arr,n,i,day+1);
//             maxi=max(maxi,totPoints);
//         }
//         return maxi;
//     }
    
//     int maximumPoints(vector<vector<int>>& arr) {
//         // Code here
//         int n=arr.size();
//         return backTrack(arr,n,3,0);
//     }
// };