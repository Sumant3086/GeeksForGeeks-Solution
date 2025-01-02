// Diameter of a Binary Tree
// Difficulty: MediumAccuracy: 47.37%Submissions: 281K+Points: 4
// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 



// Example 1:

// Input:
//        1
//      /  \
//     2    3
// Output: 3
// Example 2:

// Input:
//          10
//         /   \
//       20    30
//     /   \ 
//    40   60
// Output: 4
// Your Task:
// You need to complete the function diameter() that takes root as parameter and returns the diameter.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 10000
// 1 <= Data of a node <= 1000


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// class Solution {
//   public:
//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//         // Your code here
//     }
// };
class Solution {
public:
    int diameter(Node* root) {
        maxDepth(root);
        return maxD+1;
    }
private:
    int maxD=0;

    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        int leftM=maxDepth(root->left);
        int rightM=maxDepth(root->right); 
        int currD=leftM+rightM;
        maxD=max(maxD,currD);

        return max(leftM,rightM)+1;
    }
};