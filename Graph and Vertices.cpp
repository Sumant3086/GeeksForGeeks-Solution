// Graph and Vertices
// Difficulty: EasyAccuracy: 59.13%Submissions: 35K+Points: 2
// Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.

 

// Example 1:

// Input: 2
// Output: 2
// Example 2:

// Input: 5
// Output: 1024
 

// Your Task:

// Complete the function count() which takes an integer n as input and return the count of total number of graphs possible.

 

// Expected Time Complexity: O(1)

// Expected Space Complexity: O(1)

 

// Constraints:

// 1<=n<=10

 

// Related Articles
// If you are facing any issue on this page. Please let us know.
// Complete 90% Course in 90 days to get your refund. Take the challenge today!  

// banner

public:
    long long count(int n) {
        // your code here
        if(n<=2){
            return n;
        }
        long long edges=(n*(n-1)/2);
        long long ans=pow(2,edges);
        return ans;
    }