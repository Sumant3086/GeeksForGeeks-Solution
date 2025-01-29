// House Robber II
// Difficulty: MediumAccuracy: 39.96%Submissions: 1K+Points: 4
// You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses. Since the houses are in a circle, the first and last houses are also considered adjacent. Determine the maximum amount the thief can steal.

// Examples:

// Input: arr[] = [2, 3, 2]
// Output: 3
// Explanation: nums[0] and nums[2] can't be robbed because they are adjacent houses.
// Input: arr[] = [1, 2, 3, 1]
// Output: 4
// Explanation: Maximum stolen value: nums[0] + nums[2] = 1 + 3 = 4
// Input: arr[] = [2, 2, 3, 1, 2]
// Output: 5
// Explanation: Maximum stolen value: nums[0] + nums[2] = 2 + 3 = 5 or nums[2] + nums[4] = 3 + 2 = 5
// Constraints:
// 2 <= arr.size() <=105
// 0 <= arr[i] <=104

// Related Articles
// Expected Complexities

public:
  int linearRob(vector<int>& arr){
      int n=arr.size();
      if(n==1)return arr[0];
      int prev2=arr[0];
      int prev1=max(arr[0],arr[1]);
      for(int i=2;i<n;i++){
          int curr=max(prev1,prev2+arr[i]);
          prev2=prev1;
          prev1=curr;
      }
      return prev1;
  }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        if(n==0)return 0;
        if(n==1)return arr[0];
        vector<int>removeF(arr.begin()+1,arr.end());
        vector<int>removeL(arr.begin(),arr.end()-1);
    return max(linearRob(removeF),linearRob(removeL));
    }