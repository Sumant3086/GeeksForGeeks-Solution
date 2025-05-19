// Predecessor and Successor
// Difficulty: MediumAccuracy: 47.36%Submissions: 147K+Points: 4
// You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

// Examples :

// Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8

// Output: 4 9
// Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
// Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11

// Output: 10 -1
// Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
// Input: root[] = [2, 1, 3], key = 3

// Output: 2 -1
// Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.
// Constraints: 
// 1 <= no. of nodes <= 105
// 1 <= node->data <= 106
// 1 <= key <= 106

// Expected Complexities
// Company Tags
// Ola Cabs
// Topic Tags
// Related Interview Experiences
// Related Articles


class Solution {
  public:
    pair<int,int> help(vector<int> &temp,int target){
       int n=temp.size();
       int i=0;
       int j=n-1;
       int ans=0;
       while(i<=j){
           int mid=i+(j-i)/2;
           if(temp[mid]==target){
               if(mid+1==n) return {temp[mid-1],-1};
               else if(mid-1<0) return {-1,temp[mid+1]};
               return {temp[mid-1],temp[mid+1]};
           } 
           else if(temp[mid]<target){
               //ans=mid;
               i=mid+1;
           }
           else{
               j=mid-1;
           }
       }
       if(i==n) return {temp[j],-1};
       else if(j<0) return {-1,temp[i]};
       return {temp[j],temp[i]};
   }
  
   void inorder(Node* root,vector<int> &temp){
       if(root==NULL) return ;
       if(root->left!=NULL) inorder(root->left,temp);
       temp.push_back(root->data);
       if(root->right!=NULL) inorder(root->right,temp);
   }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        if(root->left==NULL && root->right==NULL){
            Node* pre=new Node(-1);
            Node* suc=new Node(-1);
            return {pre,suc};
        }
        vector<int> temp;
        inorder(root,temp);
        pair<int,int> p=help(temp,key);
        Node* pre=new Node(p.first);
        Node* suc=new Node(p.second);
        return {pre,suc};
    }


};