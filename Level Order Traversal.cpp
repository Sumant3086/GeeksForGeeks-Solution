// Level order traversal
// Difficulty: EasyAccuracy: 70.31%Submissions: 220K+Points: 2
// Given a root of a binary tree with n nodes, the task is to find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.

// Examples:

// Input: root[] = [1, 2, 3]

// Output: [[1], [2, 3]]
// Input: root[] = [10, 20, 30, 40, 50]

// Output: [[10], [20, 30], [40, 50]]
// Input: root[] = [1, 3, 2, N, N, N, 4, 6, 5]

// Output: [[1], [3, 2], [4], [6, 5]]
// Constraints:

// 1 ≤ number of nodes ≤ 105
// 0 ≤ node->data ≤ 109
// Company Tags
// FlipkartMorgan StanleyAccoliteAmazonMicrosoftSamsungD-E-ShawOla CabsPayuAdobeCiscoQualcomm
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities

 vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            Node* curr=q.front();
            q.pop();
            level.push_back(curr->data);
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        ans.push_back(level);
        }
        return ans;
    }