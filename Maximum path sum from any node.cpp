// Maximum path sum from any node
// Difficulty: MediumAccuracy: 42.92%Submissions: 92K+Points: 4Average Time: 45m
// Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

// Examples:

// Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
// Output: 42
// Explanation: 

// Max path sum is represented using green colour nodes in the above binary tree.
// Input: root[] = [-17, 11, 4, 20, -2, 10]
// Output: 31
// Explanation: 

// Max path sum is represented using green colour nodes in the above binary tree.
// Constraints:
// 1 ≤ number of nodes ≤ 103
// -104 ≤ node->data ≤ 104

// Company Tags
// FlipkartGoogleFacebook
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// 


class Solution {
    public:
    
      int maxPathSum(Node* root, int &maxSum) {
          // code here
          if (root == NULL) {
              return 0;
          }
          int leftMax = maxPathSum(root->left, maxSum);
          int rightMax = maxPathSum(root->right, maxSum);
          int nodeMax = root->data;
          if (leftMax > 0) {
              nodeMax += leftMax;
          }
          if (rightMax > 0) {
              nodeMax += rightMax;
          }
          maxSum = max(maxSum, nodeMax);
          return max(root->data, root->data + max(leftMax, rightMax));
      }
      int findMaxSum(Node* root) {
          int maxSum = INT_MIN;
          maxPathSum(root, maxSum);
          return maxSum; 
      }
  };