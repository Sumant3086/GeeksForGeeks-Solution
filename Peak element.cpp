// Given an 0-indexed array of integers arr[] of size n, find its peak element and return it's index. An element is considered to be peak if it's value is greater than or equal to the values of its adjacent elements (if they exist).

// Note: The output will be 1 if the index returned by your function is correct; otherwise, it will be 0.

// Examples :

// Input: n = 3, arr[] = {1, 2, 3} 
// Output: 1
// Explanation: If the index returned is 2, then the output printed will be 1. Since arr[2] = 3 is greater than its adjacent elements, and there is no element after it, we can consider it as a peak element. No other index satisfies the same property, so answer will be printed as 0.
// Input: n = 7, arr[] = {1, 1, 1, 2, 1, 1, 1}
// Output: 1
// Explanation: In this case there are 5 peak elements with indices as {0,1,3,5,6}. Returning any of them will give you correct answer.
// Your Task:
// You don't have to read input or print anything. Complete the function peakElement() which takes the array arr[] and its size n as input parameters and returns the index of the peak element.

// Expected Time Complexity: O( log(n) ).
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 105
// 1 ≤ arr[i] ≤ 106

// Seen this question in a real interview before ?


class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       // Your code here
        if(n==1)
            return arr[0];    
        for(int i=1;i<n;i++){
           if(arr[i]>=arr[i-1] && (i+1==n || arr[i]>=arr[i+1])){
               return i;
           }
       }
       return -1;
    }
};