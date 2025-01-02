// Sort The Array
// Difficulty: BasicAccuracy: 41.02%Submissions: 116K+Points: 1
// Given a random set of numbers, Print them in ascending sorted order.

// Example 1:

// Input:
// n = 4
// arr[] = {1, 5, 3, 2}
// Output: {1, 2, 3, 5}
// Explanation: After sorting array will 
// be like {1, 2, 3, 5}.
// Example 2:

// Input:
// n = 2
// arr[] = {3, 1}
// Output: {1, 3}
// Explanation: After sorting array will
// be like {1, 3}.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function sortArr() which takes the list of integers and the size n as inputs and returns the modified list.

// Expected Time Complexity: O(n * log n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ n, arr[i] ≤ 105

// Seen this question in a real interview before ?
// Yes
// No
// Company Tags
// Cisco
// Topic Tags

class Solution {
public:
    void merge(vector<int>& nums,int left,int mid,int right){
        int n1=mid-left+1;
        int n2=right-mid;
        vector<int>L(n1);
        vector<int>R(n2);

        for(int i=0;i<n1;++i)
            L[i]=nums[left+i];
        for(int j=0;j<n2;++j)
            R[j]=nums[mid+1+j];
        int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                nums[k]=L[i];
                ++i;
            }else{
                nums[k]=R[j];
                ++j;
            }
            ++k;
        }
        while(i<n1){
            nums[k]=L[i];
            ++i;
            ++k;
        }
        while(j<n2){
            nums[k]=R[j];
            ++j;
            ++k;
        }
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left<right){
            int mid=(left+right)/2;
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }
    vector<int> sortArr(vector<int>& nums,int n) {
       
            mergeSort(nums,0,nums.size()-1);
        
        return nums;
    }
};