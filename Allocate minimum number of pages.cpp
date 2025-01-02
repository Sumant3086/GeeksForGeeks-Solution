// You have n books, each with arr[i] number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Examples:

// Input: n = 4, arr[] = {12,34,67,90}, m = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

// Input: n = 3, arr[] = {15,17,20}, m = 2
// Output: 32
// Explanation: Allocation is done as {15,17} and {20}.

// Expected Time Complexity: O(n logn)
// Expected Auxilliary Space: O(1)


// Constraints:
// 1 <=  n, m <= 105
// 1 <= arr[ i ] <= 106                                 

 

 class Solution {
  public:
    // Function to find minimum number of pages.
     bool isPossible(int arr[],int n,int m,int currMin) {
        int stuR = 1, currSum = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>currMin)
                return false;
            if (currSum+arr[i]>currMin){
                stuR++;
                currSum=arr[i];
                if (stuR>m)
                    return false;
            } else {
                currSum+=arr[i];
            }
        }
        return true;
     }
    long long findPages(int n, int arr[], int m) {
        // code here
        if (n<m)
            return -1;
            
        long long sum=accumulate(arr,arr+n,0LL);
            int maxP=*max_element(arr,arr+n);
        long long start=maxP,end=sum,result=sum;
        while(start<=end){
            long long mid=(start+end)/2;
            if(isPossible(arr,n,m,mid)){
                result=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }

        return result;
    }
};