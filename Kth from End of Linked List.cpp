// Kth from End of Linked List
// Difficulty: EasyAccuracy: 41.18%Submissions: 377K+Points: 2
// Given head of a linked list and a number k, your task is to find the kth node from the end. If k is more than the number of nodes, then the output should be -1.
// The following is internal representation of every test case (three inputs).
// n :  Size of the linked list
// k : Postion (from end) of the node to be found
// value[] :  An array of values that represents values of nodes.

// Examples

// Input: n = 9, k = 2, value[] = {1,2,3,4,5,6,7,8,9}
// Output: 8
// Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.  
// Input: n = 4, k = 5, value[] = {10,5,100,5}
// Output: -1
// Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.
// Note:  Try to solve in a single traversal.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= n <= 106
// 1 <= k <= 106

class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int len=0;
        for(Node* curr=head;curr!=nullptr;curr=curr->next){
            len++;
        }
        if(len<k)return -1 ;
        Node* curr=head;
        for(int i=1;i<len-k+1;i++){
            curr=curr->next;
        }
        return curr->data;
    }
};