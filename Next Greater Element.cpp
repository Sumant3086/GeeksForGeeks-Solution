// Next Greater Element
// Difficulty: MediumAccuracy: 32.95%Submissions: 434K+Points: 4Average Time: 20m
// Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// Examples

// Input: arr[] = [1, 3, 2, 4]
// Output: [3, 4, 4, -1]
// Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
// Input: arr[] = [6, 8, 0, 1, 3]
// Output: [8, -1, 1, 3, -1]
// Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1 , for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
// Input: arr[] = [10, 20, 30, 50]
// Output: [20, 30, 50, -1]
// Explanation: For a sorted array, the next element is next greater element also exxept for the last element.
// Input: arr[] = [50, 40, 30, 10]
// Output: [-1, -1, -1, -1]
// Explanation: There is no greater element for any of the elements in the array, so all are -1.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 109

// Company Tags
// FlipkartAmazonMicrosoftMakeMyTripAdobe
// Topic Tags
// StackData Structures
// Related Interview Experiences
// Adobe Interview Experience Adobe For WomenMakemytrip Interview Experience On Campus Virtual ExperienceFlipkart Interview Set 9 CampusFlipkart Interview For Sde Ii 2
// Related Articles
// Next Greater Element
// Expected Complexities
// Time Complexity: O(n)Auxiliary Space: O(n)
// If you are facing any issue on this page.  

public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>NGE(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                NGE[i]=st.top();
            }
            st.push(arr[i]);
        }
        return NGE;
    }