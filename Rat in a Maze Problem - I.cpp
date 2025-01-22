// Rat in a Maze Problem - I
// Difficulty: MediumAccuracy: 35.75%Submissions: 314K+Points: 4
// Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

// The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

// Examples:

// Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]
// Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
// Input: mat[][] = [[1, 0], [1, 0]]
// Output: []
// Explanation: No path exists and the destination cell is blocked.
// Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
// Output: ["DDRR", "RRDD"]
// Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
// Constraints:
// 2 ≤ mat.size() ≤ 5
// 0 ≤ mat[i][j] ≤ 1

// Company Tags
// AmazonMicrosoft
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today!  




class Solution {
    public:
    vector<string>path;
    bool isSafe(int i,int j,int n){
        return i>=0 && i<n && j>=0 && j<n;
    }
    void solve(int i,int j,vector<vector<int>>& m,int n,string& temp){
        if(!isSafe(i,j,n) || m[i][j]==0){
            return ;
        }
        if(i==n-1 && j==n-1){
            path.push_back(temp);
            return;
        }
        
        m[i][j]=0;
        
        temp.push_back('D');
        solve(i+1,j,m,n,temp);
        temp.pop_back();
        
        
        temp.push_back('R');
        solve(i,j+1,m,n,temp);
        temp.pop_back();
        
        
        temp.push_back('L');
        solve(i,j-1,m,n,temp);
        temp.pop_back();
        
        
        temp.push_back('U');
        solve(i-1,j,m,n,temp);
        temp.pop_back();
        
        
        m[i][j]=1;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m) {
        // code here
        int n=m.size();
            string temp="";
            solve(0,0,m,n,temp);
            return path;
    }
};
