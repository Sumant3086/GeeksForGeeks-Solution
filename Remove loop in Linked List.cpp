// Remove loop in Linked List
// Difficulty: MediumAccuracy: 27.66%Submissions: 494K+Points: 4
// Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).

// Custom Input format:

// A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

// The generated output will be true if there is no loop in list and other nodes in the list remain unchanged, otherwise, false.

// Examples:

// Input: head = 1 -> 3 -> 4, pos = 2
// Output: true
// Explanation: The linked list looks like

// A loop is present in the list, and it is removed.
// Input: head = 1 -> 8 -> 3 -> 4, pos = 0
// Output: true
// Explanation: 

// The Linked list does not contains any loop. 
// Input: head = 1 -> 2 -> 3 -> 4, pos = 1
// Output: true
// Explanation: The linked list looks like 

// A loop is present in the list, and it is removed.
// Constraints:
// 1 ≤ size of linked list ≤ 105

// Company Tags
// VMWareMorgan StanleyAmazonMicrosoftSnapdealMakeMyTripOracleWalmartGoldman SachsAdobeQualcommKulizaNetskope
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on t

void removeLoop(Node* head) {
        // code here
        if(head==nullptr){
            return;
        }
        unordered_set<Node* >st;
        Node* curr=head;
        Node* prev=nullptr;
        while(curr!=nullptr){
            if(st.find(curr)!=st.end()){
                prev->next=nullptr;
                break;
            }
            st.insert(curr);
            prev=curr;
            curr=prev->next;
        }
    }