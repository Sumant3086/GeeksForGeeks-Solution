// Print Subsequences
// Hard
// 120/120
// 27 upvotes
// Problem statement
// Given a string (lets say of length n), print all the subsequences of the given string.

// Subsequences contain all the strings of length varying from 0 to n. But the order of characters should remain same as in the input string.

// Note :
// The order of subsequences are not important. Print every subsequence in new line.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints
// 1 <= |S| <= 15
// where |S| represents the length of the input string

// Time limit: 1 sec
// Sample Input:
// abc
// Sample Output:
// "" (the double quotes just signifies an empty string, don't worry about the quotes)
// c 
// b 
// bc 
// a 
// ac 
// ab 
// abc 

void solve(int idx,char input[],string curr){
    if(input[idx]=='\0'){
        cout<<curr<<endl;
        return;
    } 
    solve(idx+1,input,curr+input[idx]);
    solve(idx+1,input,curr); 
}

void printSubsequences(char input[]) {
    // Write your code here
    string curr=""; 
    solve(0,input,curr);
}
