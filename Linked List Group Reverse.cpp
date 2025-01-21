// Linked List Group Reverse
// Difficulty: HardAccuracy: 57.08%Submissions: 221K+Points: 8
// Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

// Examples:

// Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
// Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

// Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.
// Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
// Output: 3 -> 2 -> 1 -> 5 -> 4

// Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed. Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.
// Constraints:
// 1 <= size of linked list <= 105
// 1 <= data of nodes <= 106
// 1 <= k <= size of linked list 
// Company Tags
// PaytmVMWareAccoliteAmazonMicrosoftSnapdealHikeMakeMyTripWalmartGoldman SachsAdobeSAP Labs
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities


 Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* prev=nullptr;
        Node* curr=head;
        Node* next;
        int count=0;
        while(curr && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=nullptr){
            head->next=reverseKGroup(next,k);
        }
        return prev;
    }