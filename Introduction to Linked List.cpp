// Introduction to Linked List
// Difficulty: EasyAccuracy: 66.76%Submissions: 24K+Points: 2
// Geek loves linked list data structure. Given an array of integer arr of size n, Geek wants to construct the linked list from arr.

// Construct the linked list from arr and return the head of the linked list.

// Example 1:

// Input:
// n = 5
// arr = [1,2,3,4,5]
// Output:
// 1 2 3 4 5
// Explanation: Linked list for the given array will be 1->2->3->4->5.
// Example 2:

// Input:
// n = 2
// arr = [2,4]
// Output:
// 2 4
// Explanation: Linked list for the given array will be 2->4.
// Constraints:
// 1 <= n <= 105
// 1 <= arr[i] <= 100

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function constructLL() which takes arr[] as input parameters and returns the head of the Linked List.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node *head=new Node(arr[0]);
        Node *curr=head;
        for(int i=1;i<arr.size();i++){
            Node *temp=new Node(arr[i]);
            curr->next=temp;
            curr=temp;
        }
        return head;
    }
};