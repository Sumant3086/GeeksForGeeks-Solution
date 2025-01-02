// Expression contains redundant bracket or not
// MediumAccuracy: 48.71%Submissions: 21K+Points: 4
// Be the comment of the day in POTD and win a GfG T-Shirt!
// Solve right now

// banner
// Given a string of balanced expression str, find if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. Return 1 ifit contains a redundant parenthesis, else 0.
// Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

// Example 1:

// Input:
// exp = ((a+b))
// Output:
// Yes
// Explanation:
// ((a+b)) can reduced to (a+b).
// Example 2:

// Input:
// exp = (a+b+(c+d))
// Output:
// No
// Explanation:
// (a+b+(c+d)) doesn't have any redundant or multiple
// brackets.
// Your task:
// You don't have to read input or print anything. Your task is to complete the function checkRedundancy() which takes the string s as input and returns 1 if it contains redundant parentheses else 0.

// Constraints:
// 1<=|str|<=104

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)
class Solution {
  public:
   
bool checkRedundancy(string &expr) {
    stack<char> st;
    for (char c : expr) {
        if (c == ')') {
            if (st.empty()) return false; // handle edge case
            char top = st.top();
            st.pop();
            bool operatorFound = false;
            while (!st.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
                top = st.top();
                st.pop();
            }
            if (top != '(') return false; // handle unbalanced parentheses
            if (!operatorFound) {
                return true; // Redundant parentheses found
            }
        } else {
            st.push(c);
        }
    }
    return false;
}
 

};