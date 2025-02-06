

// Construct Tree from Inorder & Preorder
// Difficulty: MediumAccuracy: 34.59%Submissions: 179K+Points: 4Average Time: 20m
// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

// Note: The output is written in postorder traversal.

// Examples:

// Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
// Output: [8, 7, 6, 1]
// Explanation: The tree will look like

// Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [3, 4, 1, 5, 2, 0]
// Explanation: The tree will look like

// Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
// Output: [2, 5, 4, 3, 1]
// Explanation: The tree will look like

// Constraints:
// 1 ≤ number of nodes ≤ 103
// 0 ≤ nodes -> data ≤ 103
// Both the inorder and preorder arrays contain unique values.

// Company Tags
// AccoliteAmazonMicrosoft
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities


 Node* helper(vector<int>& inorder,vector<int>& preorder,unordered_map<int,int>& mp,int start,int end,int &curr){
        if(start>end){
            return nullptr;
        }
        int rootVal=preorder[curr++];
        Node* root=new Node(rootVal);
        int rootIdx=mp[rootVal];
        
        root->left=helper(inorder,preorder,mp,start,rootIdx-1,curr);
        root->right=helper(inorder,preorder,mp,rootIdx+1,end,curr);
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int curr=0;
        return helper(inorder,preorder,mp,0,inorder.size()-1,curr);
    }