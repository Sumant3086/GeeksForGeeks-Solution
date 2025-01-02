// Top View of Binary Tree
// Difficulty: MediumAccuracy: 38.43%Submissions: 293K+Points: 4
// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3
// Example 2:

// Input:
//        10
//     /      \
//   20        30
//  /   \    /    \
// 40   60  90    100
// Output: 40 20 10 30 100
// Your Task:
// Since this is a function problem. You don't have to take input. Just complete the function topView() that takes root node as parameter and returns a list of nodes visible from the top view from left to right.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Node Data ≤ 105


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==nullptr)return ans;
        queue<pair<Node*,int>>q;
        map<int,int>topNodes;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node* current=p.first;
            int horDis=p.second;
            if(topNodes.find(horDis)==topNodes.end()){
                topNodes[horDis]=current->data;
            }
            if(current->left){
                q.push({current->left,horDis-1});
            }
            if(current->right){
                q.push({current->right,horDis+1});
            }
        }
        for(const auto& node:topNodes){
            ans.push_back(node.second);
        }
        return ans;
    }

};

