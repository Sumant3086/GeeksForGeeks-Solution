// Wildcard Pattern Matching
// Difficulty: MediumAccuracy: 31.13%Submissions: 80K+Points: 4
// Given two strings pat and txt which may be of different sizes, You have to return true if the wildcard pattern i.e. pat, matches with txt else return false. All characters of the string pat and txt always belong to the Alphanumeric characters.

// The wildcard pattern pat can include the characters '?' and '*'.
// '?' – matches any single character.
// '*' – matches any sequence of characters (including the empty sequence).

// Note: The matching should cover the entire txt (not partial txt).

// Examples:

// Input: txt = "abcde", pat = "a?c*"
// Output: true
// Explanation: '?' matches with 'b' and '*' matches with "de".
// Input: txt = "baaabab", pat = "a*ab"
// Output: false
// Explanation: Because in string pat character 'a' at first position, pat and txt can't be matched.
// Input: txt = "abc", pat = "*"
// Output: true
// Explanation: '*' matches with whole text "abc".
// Constraints:
// 1 <= txt.size(),pat.size() <= 200

// Company Tags
// ZohoAmazonMicrosoftOla CabsWalmartGoogleInMobiUnited Health Group
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing a

bool wildCard(string &text, string &pattern) {
    // code here
    int m=pattern.size();
int n=text.size();
vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
dp[0][0]=true;
for(int i=1;i<=m;i++){
  dp[i][0]=dp[i-1][0] && pattern[i-1]=='*';
}
for(int i=1;i<=m;i++){
  for(int j=1;j<=n;j++){
     dp[i][j]=pattern[i-1]=='*'? dp[i-1][j] || dp[i][j-1]
        : dp[i-1][j-1] && (pattern[i-1]==text[j-1] || pattern[i-1]=='?');
  }
}
return dp[m][n];
}