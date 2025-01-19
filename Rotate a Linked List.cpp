// Rotate a Linked List
// Difficulty: MediumAccuracy: 39.95%Submissions: 269K+Points: 4
// Given the head of a singly linked list, your task is to left rotate the linked list k times.

// Examples:

// Input: head = 10 -> 20 -> 30 -> 40 -> 50, k = 4
// Output: 50 -> 10 -> 20 -> 30 -> 40
// Explanation:
// Rotate 1: 20 -> 30 -> 40 -> 50 -> 10
// Rotate 2: 30 -> 40 -> 50 -> 10 -> 20
// Rotate 3: 40 -> 50 -> 10 -> 20 -> 30
// Rotate 4: 50 -> 10 -> 20 -> 30 -> 40

// Input: head = 10 -> 20 -> 30 -> 40 , k = 6
// Output: 30 -> 40 -> 10 -> 20 
 
// Constraints:

// 1 <= number of nodes <= 105
// 0 <= k <= 109
// 0 <= data of node <= 109
// Company Tags
// AccoliteAmazonMicrosoftMakeMyTrip
// Topic Tags
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.

class Solution {
  public:
//   int getLength(Node* head){
//       int len=0;
//       while(head){
//           len++;
//           head=head->next;
//       }
//       return len;
//   }
//     Node* rotate(Node* head, int k) {
//         // Your code here
//         if(!head || !head->next){
//             return head;
//         }
//         int len=getLength(head);
//         k=k%len;
//         if(k==0){
//             return head;
//         }
//         int last=len-k;
//         Node* lastNode=head;
//         for(int i=1;i<last;i++){
//             lastNode=lastNode->next;
//         }
//         Node* newHead=lastNode->next;
//         lastNode->next=nullptr;
//         Node* temp=newHead;
//         while(temp->next){
//             temp=temp->next;
//         }
//         temp->next=head;
//         return newHead;
//     }


    Node* rotate(Node* head, int k) {
 if (k == 0 || head == nullptr)
        return head;

    Node *curr = head;
    int len = 1;
  
  	// Find the length of linked list
    while (curr->next != nullptr) {
        curr = curr->next;
        len += 1;
    }

  	// Modulo k with length of linked list to handle
  	// large values of k
    k %= len;
  
    if (k == 0)
        return head;
  
  	// Make the linked list circular
    curr->next = head;

  	// Traverse the linked list to find the kth node
    curr = head;
    for (int i = 1; i < k; i++)
        curr = curr->next;

  	// Update the (k + 1)th node as the new head
    head = curr->next;
  
  	// Break the loop by updating next pointer of kth node
    curr->next = nullptr;
    return head;
}

};