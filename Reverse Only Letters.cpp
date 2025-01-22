//  Reverse Only Letters
// Easy
// 0/40
// Average time to solve is 15m
// Contributed by
// Asked in companies
// Problem statement
// You are given a string, ‘S’. You need to reverse the string where characters that are not an alphabet stay in the same place, and the rest reverse their positions.

// Eg: “a-bcd” becomes “d-cba”

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 0 <= |S| <= 5000

// Where |S| denotes the length of string 'S'.

// Time Limit: 1 Sec
// Sample Input 1:
// 2
// a-bcd
// !s-cx
// Sample Output 1:
// d-cba
// !x-cs
// Explanation Of Sample Input 1:
// In the first test case:
// “a-bcd” after removing non-letter will be “abcd”.
// Reversing “abcd” will get “dcba”.
// Placing non-letters in the correct position in “dcba”, we get: “d-cba”.

// In the second test case:
// “!s-cx” after removing non-letter will be “scx”.
// Reversing “scx” will get “xcs”.
// Placing non-letters in the correct position in “xcs”, we get: “!x-cs”.
// Sample Input 2:
// 2
// a-bC-dEf-ghIj
// Qedo1ct-eeLg=ntse-T!
// Sample Output 2:
// j-Ih-gfE-dCba
// Test1ng-Leet=code-Q!
// Explanation Of Sample Input 2:
// In the first test case:
// “a-bC-dEf-ghIj” after removing non-letter will be “abCdEfghlj”.
// Reversing “abCdEfghlj” will get “jlhgfEdCba”.
// Placing non-letters in the correct position in “jlhgfEdCba”, we get: “j-Ih-gfE-dCba”.

// In the second test case:
// “!s-cx” after removing non-letter will be “Qedo1ct-eeLg=ntse-T!”.
// Reversing “QedocteeLgntseT” will get “TestngLeetcodeQ”.
// Placing non-letters in the correct position in “TestngLeetcodeQ”, we get: “Test1ng-Leet=code-Q!”.

#include <bits/stdc++.h>  
string reverseOnlyLetters(string & s) {
	// Write your code here.
	vector<char>L;
	for(char c:s){
		if(isalpha(c)){
			L.push_back(c);
		}
	}
	int end=L.size()-1;
	for(int k=0;k<s.size();k++){
		if(isalpha(s[k])){
			s[k]=L[end--];
		}
	}
	return s;
}
