// Merge two sorted linked lists
// Difficulty: MediumAccuracy: 62.91%Submissions: 172K+Points: 4
// Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

// Examples:

// Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
// Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
// Explanation:

// Input: head1 = 1 -> 1, head2 = 2 -> 4
// Output: 1 -> 1 -> 2 -> 4
// Explanation:

// Constraints:
// 1 <= no. of nodes<= 103
// 0 <= node->data <= 105

// Company Tags
// ZohoFlipkartAccoliteAmazonMicrosoftSamsungFactSetMakeMyTripOracleBrocadeSynopsysOATS SystemsBelzabar
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities


class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
    
        Node* dummy=new Node(0);
        Node* curr=dummy;
        Node* ptr1=head1;
        Node* ptr2=head2;
        while(ptr1 && ptr2){
            if(ptr1->data<=ptr2->data){
                curr->next=ptr1;
                ptr1=ptr1->next;
            }else{
                curr->next=ptr2;
                ptr2=ptr2->next;
            }
            curr=curr->next;
        }
        if(ptr1){
            curr->next=ptr1;
        }
        if(ptr2){
            curr->next=ptr2;
        }
        Node* mergedH=dummy->next;
        delete dummy;
        return mergedH;
    }
};