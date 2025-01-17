// Largest subarray of 0's and 1's
// Difficulty: EasyAccuracy: 32.96%Submissions: 85K+Points: 2
// Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.

// Example 1:

// Input:
// N = 4
// A[] = {0,1,0,1}
// Output: 4
// Explanation: The array from index [0...3]
// contains equal number of 0's and 1's.
// Thus maximum length of subarray having
// equal number of 0's and 1's is 4.
// Example 2:

// Input:
// N = 5
// A[] = {0,0,1,0,0}
// Output: 2
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxLen() which takes the array arr[] and the size of the array as inputs and returns the length of the largest subarray with equal number of 0s and 1s.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= N <= 105
// 0 <= A[] <= 1

class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        unordered_map<int,int>map;
        map[0]=-1;
        int len=0;
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=(arr[i]==1)?1:-1;
            if(map.count(sum)){
                len=max(i-map[sum],len);
            }else{
                map[sum]=i;
            }
        }
        return len;
    }
};