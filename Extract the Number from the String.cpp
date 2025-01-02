// Extract the Number from the String
// Difficulty: EasyAccuracy: 12.06%Submissions: 56K+Points: 2
// Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

// Note: Numbers and words are separated by spaces only. It is guaranteed that there are no leading zeroes in the answer.

// Examples :

// Input: sentence="This is alpha 5057 and 97"
// Output: 5057
// Explanation: 5057 is the only number that does not have a 9.
// Input: sentence="Another input 9007"
// Output: -1
// Explanation: Since there is no number that does not contain a 9,output is -1.
// Expected Time Complexity: O(n)
// Expected Auxillary Space: O(n)

// Constraints:
// 1<=n<=106
// 1<=answer<=1018

// n is the length of a given sentence.


class Solution {
  public:
    long long ExtractNumber(string sentence) {
         stringstream ss(sentence);
        string temp;
        vector<string> v;
        while(ss>>temp){
          v.push_back(temp);  
        }
        vector<long long> res;
        for(int i=0; i<v.size(); i++){
            if(all_of(v[i].begin(), v[i].end(), ::isdigit)){
                if(v[i].find('9')==string::npos) res.push_back(stoll(v[i]));
            }
        }
        if(!res.size()) return -1;
        else {
            sort(res.begin(), res.end());
            return res[res.size()-1];
        }
        // code here
    }
};