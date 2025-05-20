// Burning Tree
// Difficulty: HardAccuracy: 53.53%Submissions: 110K+Points: 8
// Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
// Note: The tree contains unique values.

// Examples : 

// Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
  
// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec 
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.
// Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

// Output: 5
// Explanation: Initially 10 is set to fire at 0 sec 
// At 1 sec: Node 5 catches fire.
// At 2 sec: Node 2 catches fire.
// At 3 sec: Nodes 1 and 4 catches fire.
// At 4 sec: Node 3 and 8 catches fire.
// At 5 sec: Node 7 catches fire.
// It takes 5s to burn the complete tree.
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 1 ≤ node->data ≤ 105

// Expected Complexities
// Company Tags
// FlipkartAmazonMicrosoftAdobe
// Topic Tags
// Related Interview Experiences
// Related Articles
// If you are facing any issue on this page. Please let us know.

 
class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
         deque<pair<Node*, int>> q = {{root, -1}};
        unordered_map<Node*, Node*> parent;
        parent[root] = nullptr;
        Node* tar = nullptr;
        Node* node = nullptr;
        while(!q.empty()){
            node = q.front().first;
            q.pop_front();
            if(node->data == target)tar = node;
            if(node->left){
                q.push_back({node->left, -1});
                parent[node->left] = node;
            }
            if(node->right){
                q.push_back({node->right, -1});
                parent[node->right] = node;
            }
        }
        int t = 0, tt;
        q.push_back({tar, 0});
        while(!q.empty()){
            node = q.front().first;
            tt = q.front().second;
            t = max(t, tt);
            q.pop_front();
            node->data = 0;
            if(node->left && node->left->data){
                q.push_back({node->left, tt + 1});
            }
            if(node->right && node->right->data){
                q.push_back({node->right, tt + 1});
            }
            if(parent[node] && parent[node]->data){
                q.push_back({parent[node], tt + 1});
            }
        }
        return t;
    }
};