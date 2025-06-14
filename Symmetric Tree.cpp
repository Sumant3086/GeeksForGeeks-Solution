// Symmetric Tree
// Difficulty: EasyAccuracy: 44.96%Submissions: 166K+Points: 2Average Time: 20m
// Given the root of a binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.


// A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

// Examples:

// Input: root[] = [1, 2, 2, 3, 4, 4, 3]
//    ex-1_1
// Output: True
// Explanation: As the left and right half of the above tree is mirror image, tree is symmetric.
// Input: root[] = [1, 2, 2, N, 3, N, 3]
//    ex-2_1
// Output: False
// Explanation:  As the left and right half of the above tree is not the mirror image, tree is not symmetric. 
// Constraints:
// 1  ≤ number of nodes ≤ 2000

// Expected Complexities
// Company Tags
// AmazonMicrosoft
// Topic Tags
// Related Articles
// If you are facing any issue on this page. Please let us know.

    
class Solution {
  public:
    bool helper(Node* r1,Node* r2){
        if(r1==NULL && r2==NULL) return 1;
        if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)) return 0;
        return ((r1->data==r2->data) && helper(r1->left, r2->right) && helper(r1->right, r2->left));
    }
    bool isSymmetric(Node* root) { 
        if(root==NULL)return "True";
        return helper(root->left,root->right);
        
    }
};