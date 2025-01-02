// Largest BST
// Difficulty: MediumAccuracy: 29.73%Submissions: 119K+Points: 4
// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

// Example 1:

// Input:
//         1
//       /   \
//      4     4
//    /   \
//   6     8
// Output: 1
// Explanation: There's no sub-tree with size
// greater than 1 which forms a BST. All the
// leaf Nodes are the BSTs with size equal
// to 1.
// Example 2:

// Input: 6 6 3 N 2 9 3 N 8 8 2
//             6
//         /       \
//        6         3
//         \      /   \
//          2    9     3
//           \  /  \
//           8 8    2 
// Output: 2
// Explanation: The following sub-tree is a
// BST of size 2: 
//        2
//     /    \ 
//    N      8
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function largestBst() that takes the root node of the Binary Tree as its input and returns the size of the largest subtree which is also the BST. If the complete Binary Tree is a BST, return the size of the complete Binary Tree. 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106



class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
       	//Your code here
int ans=0;
vector<int>traceTree(Node* root){
    if(!root)return vector<int>{0,1,INT_MAX,INT_MIN};
    int min=root->data;
    int max=root->data;
    int size=1;
    if(root->right==NULL && root->left==NULL) return vector<int>{1,1,root->data,root->data};
    int isBST=1;
    if(root->left){
        vector<int>v1=traceTree(root->left);
        if(!v1[1] || root->data<=v1[3])isBST=0;
        size+=v1[0];
        min=v1[2];
    }
    if(root->right){
        vector<int>v1=traceTree(root->right);
        if(!v1[1] || root->data>=v1[2])isBST=0;
        size+=v1[0];
        max=v1[3];
    }
    if(isBST){
        ans=std::max(ans,size);
    }
    return {size,isBST,min,max};
}
    int largestBst(Node* root){
        ans=1;
        traceTree(root);
        return ans;
    }
};