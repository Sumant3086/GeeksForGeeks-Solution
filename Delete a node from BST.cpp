// Delete a node from BST
// Difficulty: MediumAccuracy: 40.7%Submissions: 116K+Points: 4
// Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

// Example 1:

// Input:
//       2
//     /   \
//    1     3
// X = 12
// Output: 1 2 3
// Explanation: In the given input there
// is no node with value 12 , so the tree
// will remain same.
// Example 2:

// Input:
//             1
//              \
//               2
//                 \
//                  8 
//                /    \
//               5      11
//             /  \    /  \
//            4    7  9   12
// X = 9
// Output: 1 2 4 5 7 8 11 12
// Explanation: In the given input tree after
// deleting 9 will be
//              1
//               \
//                2
//                  \
//                   8
//                  /   \
//                 5     11
//                /  \     \
//               4    7     12
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function deleteNode() which takes two arguments. The first being the root of the tree, and an integer 'X' denoting the node value to be deleted from the BST. Return the root of the BST after deleting the node with value X. Do not make any update if there's no node with value X present in the BST.

// Note: The generated output will be the inorder traversal of the modified tree.
 

// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(Height of the BST).
 

// Constraints:
// 1 <= N <= 105

Node *deleteNode(Node *root, int X) {
    // your code goes here
     if(root) 
            if(X<root->data)root->left=deleteNode(root->left,X);     //We recursively call the function until we find the target node
            else if(X>root->data)root->right=deleteNode(root->right,X);       
            else{
                if(!root->left && !root->right)return NULL;          //No child condition
                if (!root->left || !root->right)
                    return root->left?root->left:root->right;    //One child contion -> replace the node with it's child
                   //Two child condition   
                Node* temp=root->left;                        //(or) TreeNode *temp = root->right;
                while(temp->right!=NULL)temp=temp->right;     //      while(temp->left != NULL) temp = temp->left;
                root->data=temp->data;                            //       root->val = temp->val;
                root->left=deleteNode(root->left, temp->data);  //        root->right = deleteNode(root->right, temp);		
            }
        return root;

}