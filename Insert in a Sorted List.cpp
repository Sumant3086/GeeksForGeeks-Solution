// Insert in a Sorted List
// Difficulty: EasyAccuracy: 31.37%Submissions: 129K+Points: 2
// Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.

// Example 1:

// Input:
// LinkedList: 25->36->47->58->69->80
// data: 19
// Output: 
// 19 25 36 47 58 69 80
// Explanation:
// After inserting 19 the sorted linked list will look like the one in the output.
// Example 2:

// Input:
// LinkedList: 50->100
// data: 75
// Output: 
// 50 75 100
// Explanation:
// After inserting 75 the sorted linked list will look like the one in the output.
// Your Task:
// The task is to complete the function sortedInsert() which should insert the element in sorted Linked List and return the head of the linked list

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 104
// -99999 <= A[i] <= 99999, for each valid i

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node* temp=new Node(data);
        if(head==NULL)return temp;
        if(data<head->data){
            temp->next=head;
            return temp;
        }
        Node* curr=head;
        while(curr->next!=NULL && curr->next->data<data){
            curr=curr->next;
        }
        temp->next=curr->next;
        curr->next=temp;
        return head;
    }
};