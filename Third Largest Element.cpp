// Third largest element
// Difficulty: EasyAccuracy: 45.04%Submissions: 140K+Points: 2Average Time: 15m
// Given an array, arr of positive integers. Find the third largest element in it. Return -1 if the third largest element is not found.

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The third largest element in the array [2, 4, 1, 3, 5] is 3.
// Input: arr[] = [10, 2]
// Output: -1
// Explanation: There are less than three elements in the array, so the third largest element cannot be determined.
// Input: arr[] = [5, 5, 5]
// Output: 5
// Explanation: In the array [5, 5, 5], the third largest element can be considered 5, as there are no other distinct elements.
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1 ≤ arr.size ≤ 105
// 1 ≤ arr[i] ≤ 105

// Company Tags
// AmazonMicrosoftMakeMyTrip
// Topic Tags
// Related Interview Experiences
// Related Articles
// If you are facing any issue on this page. Please let us know.

int thirdLargest(vector<int> &arr) {
    // Your code here
    int n=arr.size();
    int first=INT_MIN;
    int second=INT_MIN;
    int third=INT_MIN;
    for(int i:arr){
        if(i>=first){
            third=second;
            second=first;
            first=i;
        }else if(i>=second && i<=first){
            third=second;
            second=i;
        }else if(i>=third && i<=second){
            third=i;
        }
    }
    return (third!=INT_MIN)?third:first;
}