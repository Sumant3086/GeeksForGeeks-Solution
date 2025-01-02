// Subsets
// Difficulty: MediumAccuracy: 44.3%Submissions: 30K+Points: 4
// Given a set of positive integers, find all its subsets.

// Example 1 :

// Input : 
// array = {1, 2, 3}
// Output :
// // this space denotes null element. 
// 1
// 1 2
// 1 2 3
// 1 3
// 2
// 2 3
// 3
// Explanation: 
// The following are the subsets 
// of the array {1, 2, 3}.
// Example 2 :

// Input :
// array = {1, 2}
// Output :

// 1 
// 1 2
// 2
// Explanation :
// The following are the 
// subsets of {1, 2}.
// Your task :
// You don't have to read input or print anything. Your task is to complete the function subsets() which takes the array of integers as input and returns the list of lists containing the subsets of the given set of numbers in lexicographical order.
 
// Expected Time Complexity : O(2n)
// Expected Auxiliary Space : O((2n)*length of each subset)
 
// Constraints :
// 1 <= n <= 15
// 1 <= arr[i] <=104

class Solution {
  public:
  vector<vector<int>>ans;
  void dummy(vector<int>A,vector<int>temp,int i){
      if(i==A.size()){
          ans.push_back(temp);
          return;
      }
      temp.push_back(A[i]);//Take
      dummy(A,temp,i+1);
      temp.pop_back();
      dummy(A,temp,i+1);//NOT Take
      return;
  }
    vector<vector<int> > subsets(vector<int>& a) {
        // code here
        vector<int>temp;
        dummy(a,temp,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};