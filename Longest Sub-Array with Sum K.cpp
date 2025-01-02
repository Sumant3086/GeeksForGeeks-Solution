// Longest Sub-Array with Sum K
// Difficulty: MediumAccuracy: 24.64%Submissions: 291K+Points: 4
// Given an array arr containing n integers and an integer k. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k.

 

// Examples:
 

// Input :
// arr[] = {10, 5, 2, 7, 1, 9}, k = 15
// Output : 4
// Explanation:
// The sub-array is {5, 2, 7, 1}.
// Input : 
// arr[] = {-1, 2, 3}, k = 6
// Output : 0
// Explanation: 
// There is no such sub-array with sum 6.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

 

// Constraints:
// 1<=n<=105
// -105<=arr[i], K<=105

int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<int,int>map;
        int sum=0;
        int maxL=0;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
             if(sum==K){
                maxL=max(maxL,i+1);
            }
            if(map.find(sum-K)!=map.end()){
                maxL=max(maxL,i-map[sum-K]);
            }
            if(map.find(sum)==map.end()){
                map[sum]=i;
            }
        }
    return maxL;
    } 