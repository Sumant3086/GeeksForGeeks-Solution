// You are given a string s consisting only of lowercase English letters. Your task is to find the longest palindromic substring that can be obtained by rearranging the letters of s. If there are multiple longest palindromic substrings, find lexicographically smallest one.

// Examples:
// Input: s = "abaccd"
// Output: "acbca"
// Explanation: Rearrange s as "dacbca", then longest palindromic substring is "acbca".

// Input: s = "abcb"
// Output: "bab"
// Explanation: Rearrange s as "babc", then longest palindromic substring is "bab".

// Constraints:
// • 1 ≤ s.size() ≤ 10^6

// The accuracy rate for this problem is 72.72%, it has had 99+ submissions, and is worth 10 points.

string findSubstring(string s) {
        // code here
        unordered_map<char,int>freq;
        for(char c:s){
            freq[c]++;
        }
        string half="";
        char middle='\0';
        for(char ch='a';ch<='z';ch++){
            if(freq[ch]>0){
                half+=string(freq[ch]/2,ch);
                if(freq[ch]%2==1){
                    if(middle=='\0' || ch<middle){
                        middle=ch;
                    }
                }
            }
        }
        string rev=half;
        reverse(rev.begin(),rev.end());
        string res=half+(middle!='\0'?string(1,middle):"")+rev;
        return res;
    }
