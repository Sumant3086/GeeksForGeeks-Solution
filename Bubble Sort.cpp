// Bubble Sort
// Difficulty: EasyAccuracy: 59.33%Submissions: 178K+Points: 2
// Given an Integer N and a list arr. Sort the array using bubble sort algorithm.
// Example 1:

// Input: 
// N = 5
// arr[] = {4, 1, 3, 9, 7}
// Output: 
// 1 3 4 7 9
// Example 2:

// Input:
// N = 10 
// arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
// Output: 
// 1 2 3 4 5 6 7 8 9 10

// Your Task: 
// You don't have to read input or print anything. Your task is to complete the function bubblesort() which takes the array and it's size as input and sorts the array using bubble sort algorithm.

// Expected Time Complexity: O(N^2).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 103
// 1 <= arr[i] <= 103

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Your code here
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
};