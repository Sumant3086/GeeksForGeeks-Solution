// Reverse a linked list
// Difficulty: EasyAccuracy: 73.11%Submissions: 294K+Points: 2
// Given head a linked list, the task is to reverse this list.

// The following is internal representation of every test case (two inputs).
// n : Size of the linked list
// value[] :  An array of values that represents values of nodes.

// Examples:

// Input: n = 6, value[] = {1, 2, 3, 4, 5, 6}
// Output: 6 5 4 3 2 1
// Explanation:

// Input: n = 5, value[] = {2, 7, 10, 9, 8} 
// Output: 8 9 10 7 2
// Explanation:

// Input: n = 1, value[] = {10}
// Output: 10
// Explanation: For a single node list, the reverse would be same as original
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= n <= 104

class Solution {
  public:
    // Function to reverse a linked list.
    struct Node* reverseList(struct Node* head) {
        // code here
        // return head of reversed list
        Node* next,* prev=nullptr;
        while(head!=nullptr){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
};
