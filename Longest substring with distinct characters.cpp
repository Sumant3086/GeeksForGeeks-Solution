// Longest substring with distinct characters
// Difficulty: EasyAccuracy: 31.32%Submissions: 132K+Points: 2
// Given a string s, find the length of the longest substring with all distinct characters. 

// Examples:

// Input: s = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest substring with all distinct characters.
// Input: s = "aaa"
// Output: 1
// Explanation: "a" is the longest substring with all distinct characters.
// Input: s = "abcdefabcbb"
// Output: 6
// Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
// Constraints:
// 1<= s.size()<=3*104
// All the characters are in lowercase.

// Company Tags
// AmazonMicrosoftHousing.comAdobe
// Topic Tags
// Related Articles
// Expected Complexities


class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_set<char>unq;
        int maxL=0;
        int left=0;
        for(int right=0;right<s.size();right++){
            while(unq.find(s[right])!=unq.end()){
                unq.erase(s[left]);
                left++;
            }
            unq.insert(s[right]);
            maxL=max(maxL,right-left+1);
        }
        return maxL;
    }
};