// Permutations of a String
// Difficulty: MediumAccuracy: 34.65%Submissions: 278K+Points: 4
// Given a string s. The task is to return a vector of string of all unique permutations of the given string, s that may contain duplicates in lexicographically sorted order. 

// Examples:

// Input: "ABC"
// Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
// Explanation: Given string ABC has permutations in 6 forms as "ABC", "ACB", "BAC", "BCA", "CAB" and "CBA".
// Input: "ABSG"
// Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
// Explanation: Given string ABSG has 24 permutations.
// Input: "AAA"
// Output: ["AAA"]
// Explanation: No other unique permutations can be formed as all the characters are same.
// Constraints:
// 1 <= s.size() <= 5

// Company Tags
// ZohoAccoliteAmazonMicrosoftOYO RoomsSamsungSnapdealCitrixWalmartMAQ SoftwareCisco
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today!  

// banner

class Solution {
  public:
  void backtrack(string &s,vector<string>& res,string& curr,vector<bool>& visited){
      if(curr.size()==s.size()){
          res.push_back(curr);
          return;
      }
      for(int i=0;i<s.size();i++){
          if(visited[i] || (i>0 && s[i]==s[i-1] && !visited[i-1])){
              continue;
          }
          visited[i]=true;
          curr.push_back(s[i]);
          backtrack(s,res,curr,visited);
          visited[i]=false;
          curr.pop_back();
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        sort(s.begin(),s.end());
        vector<string>res;
        string curr;
        vector<bool>visited(s.size(),false);
        backtrack(s,res,curr,visited);
        return res;
    }
};