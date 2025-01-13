// Fruit Into Baskets
// Difficulty: MediumAccuracy: 47.98%Submissions: 80K+Points: 4
// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array of fruits, return the maximum number of fruits you can pick.

// Examples:

// Input: arr[]= [2, 1, 2]
// Output: 3
// Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.
// Input: arr[] = [3, 1, 2, 2, 2, 2]
// Output: 5
// Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] <=105

// Topic Tags
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today!  

// banner

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        // code here
        map<int,int>mp;
        int l=0,r=0,maxL=0;
        while(r<arr.size()){
            mp[arr[r]]++;
            if(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
            }
            maxL=max(maxL,r-l+1);
            r++;
        }
        return maxL;
    }
};
// class Solution {
//   public:
//     int totalFruits(vector<int> &arr) {
//         // code here
//         int maxL=0;
//         for(int i=0;i<arr.size();i++){
//             set<int>st;
//             for(int j=i;j<arr.size();j++){
//                 st.insert(arr[j]);
//                 if(st.size()<=2){
//                     maxL=max(maxL,j-i+1);
//                 }else{
//                     break;
//                 }
//             }
//         }
//         return maxL;
//     }
// };