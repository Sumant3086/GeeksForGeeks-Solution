// Count Pairs whose sum is less than target
// Difficulty: EasyAccuracy: 53.13%Submissions: 18K+Points: 2
// Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.

// Examples:

// Input: arr[] = [7, 2, 5, 3], target = 8
// Output: 2
// Explanation: There are 2 pairs with sum less than 8: (2, 5) and (2, 3). 
// Input: arr[] = [5, 2, 3, 2, 4, 1], target = 5
// Output: 4
// Explanation: There are 4 pairs whose sum is less than 5: (2, 2), (2, 1), (3, 1) and (2, 1).
// Input: arr[] = [2, 1, 8, 3, 4, 7, 6, 5], target = 7
// Output: 6
// Explanation: There are 6 pairs whose sum is less than 7: (2, 1), (2, 3), (2, 4), (1, 3), (1, 4) and (1, 5).
// Constraints:
// 1 <= arr.size() <= 105
// 0 <= arr[i] <= 104
// 1 <= target <= 104

// Topic Tags
// Related Articles
// Expected Complexities
// If you are faci

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(),arr.end());
        int count=0;
        int n=arr.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum<target){
                count+=(right-left);
                left++;
            }else{
                right--;
            }
        }
        return count;
    }
};