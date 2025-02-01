// Word Search
// Difficulty: MediumAccuracy: 32.69%Submissions: 66K+Points: 4
// You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

// Examples :

// Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: true
// Explanation:

// The letter cells which are used to construct the "GEEK" are colored.
// Input: mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: false
// Explanation:

// It is impossible to construct the string word from the mat using each cell only once.
// Input: mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
// Output: true
// Explanation:

// There are multiple ways to construct the word "AB".
// Constraints:
// 1 ≤ n, m ≤ 6
// 1 ≤ L ≤ 15
// mat and word consists of only lowercase and uppercase English letters.

// Company Tags
// AmazonMicrosoftIntuitApple
// Topic Tags
// Related Articles
// Expected Complexities


public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
          for(int i =0; i<mat.size(); i++){
            for(int j =0; j<mat[0].size(); j++){
                if(mat[i][j]==word[0]){
                  vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
                  if(check(mat, i, j , 0 , word , visit)){
                      return true;
                  }

                }
            }
        }
        return false;
    }
    
    private:
    bool check(vector<vector<char>>& mat, int i, int j, int idx,  string& word ,  vector<vector<bool>>&visit)
   {
    
    if(idx == word.size()){
        return true;
    }
    
    // base case -->
    
    if(i<0 || j<0 || i>=mat.size()||  j>=mat[0].size() || visit[i][j] || mat[i][j]!= word[idx]){
        return false;
    }
    visit[i][j] = true;
    
    if(check(mat , i,  j-1, idx+1 , word, visit )||  //left
     check(mat , i,  j+1, idx+1 , word, visit )|| //right
     check(mat , i-1,  j, idx+1 , word, visit )|| //up
     check(mat , i+1,  j, idx+1 , word, visit )) //down
     {
         return true;
     }
     visit[i][j] = false;
     return false;
     

    }