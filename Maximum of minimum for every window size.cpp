// Maximum of minimum for every window size
// Difficulty: HardAccuracy: 42.9%Submissions: 53K+Points: 8Average Time: 45m
// Given an array of integers arr[], the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to arr.size().

// More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=arr.size().

// Examples :

// Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
// Output: [70, 30, 20, 10, 10, 10, 10] 
// Explanation: 
// 1. First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10], [20], [30], [50], [10], [70] and [30]. Maximum of these minimums is 70. 
// 2. Second element in output indicates maximum of minimums of all windows of size 2. Minimums of windows of size 2 are [10], [20], [30], [10], [10], and [30]. Maximum of these minimums is 30. 
// 3. Third element in output indicates maximum of minimums of all windows of size 3. Minimums of windows of size 3 are [10], [20], [10], [10] and [10]. Maximum of these minimums is 20. 
// Similarly other elements of output are computed.
// Input: arr[] = [10, 20, 30]
// Output: [30, 20, 10]
// Explanation: First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10] , [20] , [30]. Maximum of these minimums are 30 and similarly other outputs can be computed
// Constraints:
// 1 <= arr.size() <= 105
// 1 <= arr[i] <= 106

// Company Tags
// FlipkartAmazonMicrosoft
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.

vector<int> maxOfMins(vector<int>& arr) {
    // Your code here
    int n=arr.size();
    vector<int>left(n,-1),right(n,n),res(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty())left[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty())right[i]=st.top();
        st.push(i);
    }
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        int len=right[i]-left[i]-1;
        res[len-1]=max(res[len-1],arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        res[i]=max(res[i],res[i+1]);
    }
    return res;
}