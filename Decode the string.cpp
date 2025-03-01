// Decode the string
// Difficulty: MediumAccuracy: 44.28%Submissions: 50K+Points: 4Average Time: 10m
// Given an encoded string s, the task is to decode it. The encoding rule is :

// k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets.
// Note: The test cases are generated so that the length of the output string will never exceed 105 .

// Examples:

// Input: s = "1[b]"
// Output: "b"
// Explanation: "b" is present only one time.
// Input: s = "3[b2[ca]]"
// Output: "bcacabcacabcaca"
// Explanation:
// 1. Inner substring “2[ca]” breakdown into “caca”.
// 2. Now, new string becomes “3[bcaca]”
// 3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.
// Constraints:
// 1 ≤ |s| ≤ 105 
// 1 <= k <= 100

// Company Tags
// MicrosoftFacebook
// Topic Tags
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us

class Solution {
    public:
      string decodedString(string &s) {
          stack<string> strStack;
          stack<int> numStack;
          string curStr = "";
          int num = 0;
          
          for (char c : s) {
              if (isdigit(c)) 
                  num = num * 10 + (c - '0');
              else if (c == '[') {
                  numStack.push(num);
                  strStack.push(curStr);
                  num = 0;
                  curStr = "";
              } 
              else if (c == ']') {
                  string temp = curStr;
                  curStr = strStack.top(); strStack.pop();
                  int repeat = numStack.top(); numStack.pop();
                  while (repeat--) curStr += temp;
              } 
              else curStr += c;
          }
          
          return curStr;
      }
  };
  