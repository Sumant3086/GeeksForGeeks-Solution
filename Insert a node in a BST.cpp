// Insert a node in a BST
// Difficulty: EasyAccuracy: 47.15%Submissions: 155K+Points: 2
// Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. If K is already present in the BST, don't modify the BST.

// Example 1:

// Input:
//      2
//    /   \   
//   1     3
// K = 4
// Output: 
// 1 2 3 4
// Explanation: 
// After inserting the node 4
// Inorder traversal will be 1 2 3 4.
// Example 2:

// Input:
//         2
//       /   \
//      1     3
//              \
//               6
// K = 4
// Output: 
// 1 2 3 4 6
// Explanation: 
// After inserting the node 4
// Inorder traversal of the above tree will be 1 2 3 4 6.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and Key K as input parameters and returns the root of the modified BST after inserting K. 
// Note: The generated output contains the inorder traversal of the modified tree.

// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= Number of nodes initially in BST <= 105
// 1 <= K <= 109

class Solution
{
    public:
        Node* insert(Node* node, int data) {
        
            // Your code goes here
    if(node==nullptr){
        return new Node(data);
    }
    if(data<node->data){
        node->left=insert(node->left,data);
    }else if (data>node->data){
        node->right=insert(node->right,data);
    }
    return node;
    }

};
