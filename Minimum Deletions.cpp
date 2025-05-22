// Minimum Deletions
// Difficulty: MediumAccuracy: 58.8%Submissions: 59K+Points: 4
// Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

// Examples:

// Input: s = "aebcbda"
// Output: 2
// Explanation: Remove characters 'e' and 'd'.
// Input: s = "geeksforgeeks"
// Output: 8
// Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
// 13 (length of s) - 5 = 8.
// Constraints:
// 1 ≤ s.size() ≤ 103

// Expected Complexities
// Company Tags
// Amazon
// Topic Tags
// Related Articles

    int LPS(string S, int n){
        string T=S;
        reverse(S.begin(),S.end());
        vector<int> curr(n+1,0), prev(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(S[i-1]==T[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return curr[n];
    }
  public:
    int minDeletions(string s) {
        int n=s.length();
        int lps_len=LPS(s,n);
        return n-lps_len;
    }