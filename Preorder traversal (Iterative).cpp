
// Preorder traversal (Iterative)
// Difficulty: MediumAccuracy: 81.12%Submissions: 33K+Points: 4
// Given a Binary tree. Find the preorder traversal of the tree without using recursion.


// Example 1:

// Input:
//            1
//          /   \
//         2     3
//       /  \
//      4    5
// Output: 1 2 4 5 3
// Explanation:
// Preorder traversal (Root->Left->Right) of 
// the tree is 1 2 4 5 3.
// Example 2

// Input:
//             8
//           /   \
//          1      5
//           \    /  \
//            7  10   6
//             \  /
//             10 6
// Output: 8 1 7 10 5 10 6 6 
// Explanation:
// Preorder traversal (Root->Left->Right) 
// of the tree is 8 1 7 10 5 10 6 6.
 

// Your task:

// You don't need to read input or print anything. Your task is to complete the function preOrder() which takes the root of the tree as input and returns a list containing the preorder traversal of the tree, calculated without using recursion.


// Expected time complexity: O(N)
// Expected auxiliary space: O(N)


// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105

class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
        vector<int>res;
        if(!root)return res;
        stack<Node*>s;
        s.push(root);
        while(!s.empty()){
            Node* node =s.top();
            s.pop();
            res.push_back(node->data);
            if(node->right)s.push(node->right);
            if(node->left)s.push(node->left);
        }
        return res;
    }
};