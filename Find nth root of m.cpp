// Find nth root of m
// Difficulty: EasyAccuracy: 25.06%Submissions: 182K+Points: 2
// You are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

// Examples :

// Input: n = 2, m = 9
// Output: 3
// Explanation: 32 = 9
// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.
// Input: n = 1, m = 14
// Output: 14
// Constraints:
// 1 <= n <= 30
// 1 <= m <= 109

// Company Tags
// DirectiAccenture
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities

public:
    int nthRoot(int n, int m) {
        int low=0;
        int high=m; 
        while(low<=high){
            int mid=(low+high)/2;
            if(pow(mid,n)==m){
                return mid;
            }else if(pow(mid,n)>m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }