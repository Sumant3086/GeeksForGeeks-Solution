// Longest Repeating Character Replacement
// Difficulty: MediumAccuracy: 50.84%Submissions: 8K+Points: 4
// Given a string s and an integer k. You can choose any string character in one operation and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.
// Note: s consists of only uppercase English letters.

// Examples:

// Input: s = "ABBA", k = 2 
// Output: 4 
// Explanation: Replace the 2 occurrences of 'A' with 2 'B's or vice-versa.
// Input: s = "ADBD", k = 1
// Output: 3
// Explanation: Change 'B' into 'D'. now s = "ADDD"
// Expected Time Complexity : (|s|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= |s| <= 105

// Topic Tags
// Related Articles

int characterReplacement(string& s, int k) {
        // code here
        int n=s.size();
        int l=0;
        int maxF=0;
        int maxL=0;
        unordered_map<char,int>mp;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            maxF=max(maxF,mp[s[r]]);
            while(r-l+1-maxF>k){
                mp[s[l]]--;
                l++;
            }
            maxL=max(maxL,r-l+1);
        }
        return maxL;
    }