// Count all triplets with given sum in sorted array
// Difficulty: MediumAccuracy: 34.34%Submissions: 7K+Points: 4
// Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

// Examples:

// Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
// Output: 4
// Explanation: Two triplets that add up to -2 are:
// arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
// arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
// arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
// arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2
// Input: arr[] = [-2, 0, 1, 1, 5], target = 1
// Output: 0
// Explanation: There is no triplet whose sum is equal to 1. 
// Constraints:
// 3 ≤ arr.size() ≤ 103
// -105 ≤ arr[i], target ≤ 105

// Topic Tags
// Related Articles
// Expected Complexities
// C++ (g++ 5.4)



//   public:




 public:
    int countTriplets(vector<int>& arr, int target) {
    unordered_map<int, int> freq;
    for(int e:arr){
        freq[e]++;
    }
    int ans=0;
    for (int i=0;i<arr.size();i++){
        freq[arr[i]]--;  
        for (int j=0;j<i;j++){ 
            int lookfor=target-arr[i]-arr[j];
            if (freq.find(lookfor) != freq.end()) {
                ans+=freq[lookfor];
            }
        }
    }
    return ans;
    } 
