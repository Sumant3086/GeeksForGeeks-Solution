// Spirally traversing a matrix
// Difficulty: MediumAccuracy: 35.2%Submissions: 249K+Points: 4
// Given a matrix of size r*c. Traverse the matrix in spiral form.

// Example 1:

// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
// Explanation:

// Example 2:

// Input:
// r = 3, c = 4  
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12}}
// Output: 
// 1 2 3 4 8 12 11 10 9 5 6 7
// Explanation:
// Applying same technique as shown above, 
// output for the 2nd testcase will be 
// 1 2 3 4 8 12 11 10 9 5 6 7.

// Your Task:
// You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, r and c as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

// Expected Time Complexity: O(r*c)
// Expected Auxiliary Space: O(r*c), for returning the answer only.

// Constraints:
// 1 <= r, c <= 100
// 0 <= matrixi <= 100


    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int row=matrix.size();
        int col=matrix[0].size();
        int count=0;
        int total=row*col;
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        vector<int>ans;
        while(count<total){
            for(int idx=startingCol;count<total && idx<=endingCol;idx++){
                ans.push_back(matrix[startingRow][idx]);
                count++;
            }
            startingRow++;
            for(int idx=startingRow;count<total && idx<=endingRow;idx++){
                ans.push_back(matrix[idx][endingCol]);
                count++;
            }
            endingCol--;
            for(int idx=endingCol;count<total && idx>=startingCol;idx--){
                ans.push_back(matrix[endingRow][idx]);
                count++;
            }
            endingRow--;
            for(int idx=endingRow;count<total && idx>=startingRow;idx--){
                ans.push_back(matrix[idx][startingCol]);
                count++;
            }
             startingCol++;
        }
        return ans;
    }