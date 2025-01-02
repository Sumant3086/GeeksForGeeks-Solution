// Histogram Max Rectangular Area
// Difficulty: HardAccuracy: 32.12%Submissions: 167K+Points: 8
// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

// Example 1:

// Input:
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12
// Explanation: In this example the largest area would be 12 of height 4 and width 3. We can achieve this 
// area by choosing 3rd, 4th and 5th bars.


// Example 2:

// Input:
// N = 8
// arr[] = {7 2 8 9 1 3 6 5}
// Output: 16
// Explanation: Maximum size of the histogram 
// will be 8  and there will be 2 consecutive 
// histogram. And hence the area of the 
// histogram will be 8x2 = 16.
// Your Task:
// The task is to complete the function getMaxArea() which takes the array arr[] and its size N as inputs and finds the largest rectangular area possible and returns the answer.

// Expected Time Complxity : O(N)
// Expected Auxilliary Space : O(N)

// Constraints:
// 1 ≤ N ≤ 106

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
         if(n==0)return 0;
        vector<long long>heights(arr,arr+n);
        heights.push_back(0); 
        vector<int>stack{-1};
        long long result=0;
        for(int i=0;i<=n;++i){ 
            while(stack.size()>1 && heights[stack.back()]>=heights[i]){
                int k=stack.back();
                stack.pop_back();
                long long w=i-stack.back()-1;
                long long s=heights[k]*w;
                result=max(result,s);
            }
            stack.push_back(i);
        }
        return result;
    }
};
// 0 ≤ arr[i] ≤ 1012