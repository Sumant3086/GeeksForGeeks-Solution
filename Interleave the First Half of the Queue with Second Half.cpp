// Interleave the First Half of the Queue with Second Half
// Difficulty: MediumAccuracy: 77.03%Submissions: 7K+Points: 4
// You are given a queue Q of N integers of even length, rearrange the elements by interleaving the first half of the queue with the second half of the queue.

 

// Example 1:

// Input:
// N = 4
// Q = {2,4,3,1}
// Output:
// {2,3,4,1}
// Explanation:
// After the mentioned rearrangement of the first half
// and second half, our final queue will be {2,3,4,1}.
 

// Example 2:

// Input:
// N = 2
// Q = {3,5}
// Output:
// {3,5}
// Explanation:
// After the mentioned rearrangement of the first half
// and second half, our final queue will be {3,5}.
 

// Your Task:

// You don't need to read input or print anything. Your task is to complete the function rearrangeQueue() which takes a queue Q as input and returns the modified queue after the rearrangement.

 

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 2 <= N <= 105
// N is even
// 1 <= Elements of Queue <= 103
// Sum of N over all test cases doesn't exceeds 106


class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int>ans;
        while(!q.empty())
        {
            int first=q.front();
            q.pop();
            ans.push_back(first);
        }
        int i=0;
        int n=ans.size();
        int mid=n/2;
        vector<int>res;
        int j=mid;
        while(i<mid && j<n)
        {
            res.push_back(ans[i]);
            res.push_back(ans[j]);
            i++;
            j++;
        }
        while(j<ans.size())
        {
            res.push_back(ans[j]);
            j++;
        }
        return res;
    
    }
};