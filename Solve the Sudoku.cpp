// Solve the Sudoku
// Difficulty: HardAccuracy: 37.98%Submissions: 113K+Points: 8
// Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

// Examples:

// Input: mat[][] = 

// Output:

// Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
// Input: mat[][] = 

// Output:

// Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
// Constraints:
// mat.size() = 9
// mat[i].size() = 9
// 0 ≤ mat[i][j] ≤ 9

// Company Tags
// ZohoFlipkartAmazonMicrosoftMakeMyTripOla CabsOracleMAQ SoftwareDirectiPayPalSamsung
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.

class Solution {
public:
    bool isValid(int value,int row,int col,vector<vector<int>>& mat){
        for(int i=0;i<9;i++){
            if(mat[row][i]==value)return false;
            if(mat[i][col]==value)return false;
            if(mat[3*(row/3)+i/3][3*(col/3)+i%3]==value)return false;
        }
        return true;
    }
    bool solveSudoku(vector<vector<int>>& mat){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]==0){
                    for(int value=1;value<=9;value++){
                        if(isValid(value,i,j,mat)){
                            mat[i][j]=value;
                            if(solveSudoku(mat))return true;
                            mat[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
