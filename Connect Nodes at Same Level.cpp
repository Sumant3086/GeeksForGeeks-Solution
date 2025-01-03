// Connect Nodes at Same Level
// Difficulty: MediumAccuracy: 55.78%Submissions: 96K+Points: 4
// Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

// Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
//        10                       10 ------> NULL
//       / \                       /      \
//      3   5       =>     3 ------> 5 --------> NULL
//     / \     \               /  \           \
//    4   1   2          4 --> 1 -----> 2 -------> NULL

 

// Example 1:

// Input:
//      3
//    /  \
//   1    2
// Output:
// 3 1 2
// 1 3 2
// Explanation:The connected tree is
//         3 ------> NULL
//      /    \
//     1-----> 2 ------ NULL
// Example 2:

// Input:
//       10
//     /   \
//    20   30
//   /  \
//  40  60
// Output:
// 10 20 30 40 60
// 40 20 60 10 30
// Explanation:The connected tree is
//          10 ----------> NULL
//        /     \
//      20 ------> 30 -------> NULL
//   /    \
//  40 ----> 60 ----------> NULL
// Your Task:
// You don't have to take input. Complete the function connect() that takes root as parameter and connects the nodes at same level. The printing is done by the driver code. First line of the output will be level order traversal and second line will be inorder travsersal

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 0 ≤ Data of a node ≤ 105


class Solution
{
    public:
    void connect(Node *root){
        if(!root)return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            Node* prev=NULL;
            while(size--){
                Node* curr=q.front();
                q.pop();
                if(prev){
                    prev->nextRight=curr;
                }
                prev=curr;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            prev->nextRight=NULL;
        }
    }    
};