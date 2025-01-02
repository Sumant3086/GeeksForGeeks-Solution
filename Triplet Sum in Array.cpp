// Triplet Sum in Array
// Difficulty: MediumAccuracy: 35.0%Submissions: 284K+Points: 4
// Given an array arr of size n and an integer x. Find if there's a triplet in the array which sums up to the given integer x.

// Examples

// Input:n = 6, x = 13, arr[] = [1,4,45,6,10,8]
// Output: 1
// Explanation: The triplet {1, 4, 8} in the array sums up to 13.
// Input: n = 5, x = 10, arr[] = [1,2,4,3,6,7]
// Output: 1
// Explanation: Triplets {1,3,6} & {1,2,7} in the array sum to 10. 
// Input: n = 6, x = 24, arr[] = [40,20,10,3,6,7]
// Output: 0
// Explanation: There is no triplet with sum 24. 
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n ≤ 103
// 1 ≤ arr[i] ≤ 105

bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        sort(arr,arr+n);
        for(int i=0;i<n-2;i++){
            int ans=x-arr[i];
            int start=i+1,end=n-1;
            while(start<end){
                if(arr[start]+arr[end]==ans)
                return 1;
                else if(arr[start]+arr[end]>ans){
                    end--;
                }
                else start++;
            }
        }
        return 0;
    }