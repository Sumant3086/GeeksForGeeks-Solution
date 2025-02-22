// Longest valid Parentheses
// Difficulty: HardAccuracy: 26.13%Submissions: 136K+Points: 8Average Time: 20m
// Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

// A parenthesis string is valid if:

// For every opening parenthesis, there is a closing parenthesis.
// The closing parenthesis must be after its opening parenthesis.
// Examples :

// Input: s = "((()"
// Output: 2
// Explanation: The longest valid parenthesis substring is "()".
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parenthesis substring is "()()".
// Input: s = "())()"
// Output: 2
// Explanation: The longest valid parenthesis substring is "()".
// Constraints:
// 1 ≤ s.size() ≤ 106  
// s consists of '(' and ')' only

// Company Tags
// MicrosoftGoogle
// Topic Tags
// Related Articles
// Expected Complexities

int maxLength(string& s) {
    // code here
    stack<int>st;
    st.push(-1);
    int maxL=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            st.pop();
            if(!st.empty()){
                maxL=max(maxL,i-st.top());
            }else{
                st.push(i);
            }
        }
    }
    return maxL;
}

