// Closest Neighbour in BST
// Difficulty: EasyAccuracy: 36.98%Submissions: 58K+Points: 2
// Given the root of a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.

// Examples:

 

// Input: root = [10, 7, 15, 2, 8, 11, 16], k = 14

// Output: 11
// Explanation: The greatest element in the tree which is less than or equal to 14, is 11.
// Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 24

// Output: 21
// Explanation: The greatest element in the tree which is less than or equal to 24, is 21. 
// Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 4

// Output: 3
// Explanation: The greatest element in the tree which is less than or equal to 4, is 3.
// Constraints:
// 1 <= number of nodes <= 105
// 1 <= node->data, k <= 105
// All nodes are unique in the BST

// Expected Complexities
// Topic Tags
// Related Articles
// If you are facing any issue on this page. Please let us know.
// Flat discounts active on all GfG Courses! Avail before 1st June!  

// banner


class Solution {
  public:
    void help(Node* root, int k, int &ans){
        if(!root)
            return;
        if(root->data > k)
            help(root->left, k, ans);
        else{
            ans = root->data;
            help(root->right, k, ans);
        }
        return;
    }
  
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        help(root, k, ans);
        return ans;
    }
};