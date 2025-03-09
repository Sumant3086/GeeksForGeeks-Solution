// Palindrome SubStrings
// Difficulty: MediumAccuracy: 45.8%Submissions: 38K+Points: 4Average Time: 30m
// Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

// Examples

// Input: s = "abaab"
// Output: 3
// Explanation: All palindromic substrings are : "aba" , "aa" , "baab".
// Input: s = "aaa"
// Output: 3
// Explanation: All palindromic substrings are : "aa", "aa", "aaa".
// Input: s = "abbaeae"
// Output: 4
// Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".
// Constraints:
// 2 ≤ s.size() ≤ 103
// string contains only lowercase english characters

// Company Tags
// Morgan StanleyAmazonOla CabsSAP Labs
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue o

int countPS(string &s) {
    // code here
     int n = s.size(), count = 0;
    auto expand = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 >= 2) count++;  
            left--;
            right++;
        }
    };
    for (int i = 0; i < n; i++) {
        expand(i, i);      
        expand(i, i + 1);  
    }

    return count;
}