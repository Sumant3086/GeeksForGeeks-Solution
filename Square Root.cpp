// Square Root
// Difficulty: EasyAccuracy: 54.03%Submissions: 293K+Points: 2
// Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.

// Floor value of any number is the greatest Integer which is less than or equal to that number

// Examples:

// Input: n = 4
// Output: 2
// Explanation: Since, 4 is a perfect square, so its square root is 2.
// Input: n = 11
// Output: 3
// Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.
// Input: n = 1
// Output: 1
// Constraints:
// 1 ≤ n ≤  3 x 104

// Company Tags
// VMWareFlipkartAccoliteAmazonMicrosoft
// Topic Tags
// SearchingMathematicalBinary SearchAlgorithms
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today

class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int low=1;
        int high=n;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(mid*mid==n){
                return mid;
            }else if(mid*mid<n){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};