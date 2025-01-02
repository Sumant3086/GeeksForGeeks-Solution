// Subarrays with sum K
// Difficulty: MediumAccuracy: 49.74%Submissions: 57K+Points: 4
// Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

// Examples:

// Input: arr = [10, 2, -2, -20, 10], k = -10
// Output: 3
// Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
// Input: arr = [9, 4, 20, 3, 10, 5], k = 33
// Output: 2
// Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
// Input: arr = [1, 3, 5], k = 0
// Output: 0
// Explaination: No subarray with 0 sum.
// Constraints:

// 1 ≤ arr.size() ≤ 105
// -103 ≤ arr[i] ≤ 103
// -107 ≤ k ≤ 107
// Company Tags
// Microsoft
// Topic Tags
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today!  

// banner


// class Solution {
//   public:
//   int countSubarraysHelper(vector<int>& arr, int start, int n, int k) {
//         if(start>=n)return 0;
//         int sum=0;
//         int count=0;
//         for(int end=start;end<n;end++){
//             sum+=arr[end];
//             if(sum==k){
//                 count++;
//             }
//         }
//         return count+countSubarraysHelper(arr,start+1,n,k);
//     }
//     int countSubarrays(vector<int>& arr,int k) {
//         return countSubarraysHelper(arr,0,arr.size(), k);
//     }
// };

class Solution {
public:
     int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumCount;
        int count=0, prefixSum=0;
        prefixSumCount[0]=1;
        for (int num:arr) {
            prefixSum+=num;
            if (prefixSumCount.find(prefixSum-k)!=prefixSumCount.end()) {
                count+=prefixSumCount[prefixSum-k];
            }
            prefixSumCount[prefixSum]++;
        }
        return count;
    }
};