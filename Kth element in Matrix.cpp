// Kth element in Matrix
// Difficulty: MediumAccuracy: 61.42%Submissions: 67K+Points: 4Average Time: 35m
// Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Examples:
// Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.
// Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
// Output: 30
// Explanation: 30 is the 7th smallest element.
// Constraints:
// 1 <= n <= 500
// 1 <= mat[i][j] <= 10000
// 1 <= k <= n*n

// Expected Complexities
// Company Tags
// AccoliteAmazonSamsung
// Topic Tags
// Related Interview Experiences
// Related Articles
// If you are facing any issue on this page. Please let us know.
// Flat discounts active on all GfG Courses! Avail before 1st June!  

// banner
 int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
         priority_queue<int,vector<int>,greater<>>pq;
        for(auto i:matrix)
        {
            for(auto j:i)
            {
                pq.push(j);
            }
        }
        while(k-- >1)
        {
            pq.pop();
        }
        return pq.top();
    }