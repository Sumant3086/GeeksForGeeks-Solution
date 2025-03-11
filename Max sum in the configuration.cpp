// Max sum in the configuration
// Difficulty: MediumAccuracy: 36.56%Submissions: 113K+Points: 4Average Time: 30m
// Given an integer array(0-based indexing) arr[]. Find the maximum value of the sum of i*arr[i] for all 0 <= i <= arr.size()-1, where arr[i] is the element at index i in the arr[]. The only operation allowed is to rotate(clockwise or counterclockwise) the array any number of times.

// Examples :

// Input: arr[] = [8, 3, 1, 2]
// Output: 29
// Explanation: Out of all the possible configurations by rotating the elements: arr[] = [3, 1, 2, 8] here (3*0) + (1*1) + (2*2) + (8*3) sum is maximum i.e. 29.
// Input: arr[] = [1, 2, 3]
// Output: 8
// Explanation: Out of all the possible configurations by rotating the elements: arr[] = [1, 2, 3] here (1*0) + (2*1) + (3*2) sum is maximum i.e. 8.
// Input: arr[] = [4, 13]
// Output: 13
// Constraints:
// 1<=arr.size()<=104
// 1<=arr[i]<=20

// Company Tags
// Amazon
// Topic Tags
// ArraysData StructuresMathematical
// Related Articles
// Expected Complexities


class Solution {
    public:
      int maxSum(vector<int> &arr) {
          // Your code here
          int n=arr.size();
          int initial=accumulate(arr.begin(),arr.end(),0);
          int sum=0;
          for(int i=0;i<n;i++){
              sum+=i*arr[i];
          }
          int maxS=sum;
          int currS=sum;
          for(int i=1;i<n;i++){
              currS=currS+initial-n*arr[n-i];
              maxS=max(maxS,currS);
          }
          return maxS;
      }
  };