// Count Subarrays with given XOR
// Difficulty: MediumAccuracy: 58.86%Submissions: 26K+Points: 4
// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

// Examples: 

// Input: arr[] = [4, 2, 2, 6, 4], k = 6
// Output: 4
// Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
// Input: arr[] = [5, 6, 7, 8, 9], k = 5
// Output: 2
// Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
// Input: arr[] = [1, 1, 1, 1], k = 0
// Output: 4
// Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
// Constraints:

// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤105
// 0 ≤ k ≤ 105
// Topic Tags
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today!  

// banner

public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int count=0;
        int prefXOR=0;
        unordered_map<int,int>freq;
        freq[0]=1;
        for(int num:arr){
            prefXOR^=num;
            int target=prefXOR^k;
            if(freq.find(target)!=freq.end()){
                count+=freq[target];
            }
            freq[prefXOR]++;
        }
        return count;
    }