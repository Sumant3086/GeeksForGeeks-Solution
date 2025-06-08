// Sum-string
// Difficulty: HardAccuracy: 50.56%Submissions: 35K+Points: 8
// Given a string s consisting of digits, determine whether it can be classified as a sum-string.

// A sum-string is a string that can be split into two or more non-empty substrings such that:


// The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

// This condition must apply recursively to the substrings before it.

// The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

// Examples:

// Input: s = "12243660"
// Output: true
// Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
// 24 = 12 + 12, 36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
// Input: s = "1111112223"
// Output: true
// Explanation: Split the string as {"1", "111", "112", "223"}, where:
// 112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
// Input: s = "123456"
// Output: false
// Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
// Constraints:
// 1 <= s.size() <= 100
// String consists of characters from '0' to '9'.

// Expected Complexities
// Company Tags
// Nutanix
// Topic Tags
// Related Articles
// If you are facing any issue on this page. Please let us know.

class Solution {
  public:
      string addStr(const string &a, const string &b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res = char(sum % 10 + '0') + res;
            carry = sum / 10;
        }
        return res;
    }

    bool check(const string &s, int start, string a, string b) {
        while (start < s.size()) {
            string sum = addStr(a, b);
            if (s.substr(start, sum.size()) != sum) return false;
            start += sum.size();
            a = b;
            b = sum;
        }
        return true;
    }

    int isSumString(string &s) {
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            string a = s.substr(0, i);
            if (a.size() > 1 && a[0] == '0') continue;
            for (int j = i + 1; j < n; ++j) {
                string b = s.substr(i, j - i);
                if (b.size() > 1 && b[0] == '0') continue;
                if (check(s, j, a, b)) return 1;
            }
        }
        return 0;
    }
};