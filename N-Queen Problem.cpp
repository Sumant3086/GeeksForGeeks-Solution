// N-Queen Problem
// Difficulty: HardAccuracy: 35.43%Submissions: 74K+Points: 8
// The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
// Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].



 

// Example 1:

// Input:
// 1
// Output:
// [1]
// Explaination:
// Only one queen can be placed 
// in the single cell available.
// Example 2:

// Input:
// 4
// Output:
// [2 4 1 3 ] [3 1 4 2 ]
// Explaination:
// These are the 2 possible solutions.
 

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function nQueen() which takes n as input parameter and returns a list containing all the possible chessboard configurations in sorted order. Return an empty list if no solution exists.

 

// Expected Time Complexity: O(n!)
// Expected Auxiliary Space: O(n2) 

 

// Constraints:
// 1 ≤ n ≤ 10 

class Solution{
public:
    vector<vector<int>> ans;
    void solve(int col, vector<vector<int>> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if(col == n) {
            vector<int> temp;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if(board[j][i])
                        temp.push_back(j + 1);
                }
            }
            ans.push_back(temp);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 && upperDiagonal[n-1 + col - row] == 0 && lowerDiagonal[row + col] == 0) {
                board[row][col] = row + 1;
                leftRow[row] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                lowerDiagonal[row + col] = 1;
                solve(col + 1, board, leftRow, upperDiagonal, lowerDiagonal, n);
                board[row][col] = 0;
                leftRow[row] = 0;
                upperDiagonal[n-1 + col - row] = 0;
                lowerDiagonal[row + col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n,vector<int>(n,0));

        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};