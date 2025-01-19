// You are given an integer array arr[]. You are also given an equal sized integer array change[], and an integer k. You have to replace exactly k elements of arr[] with the corresponding element of change[]. Your goal is to minimize the sum of the elements of arr[].
// Examples:
// Input: arr[] = [1, 2, 3], change[] = [3, 3, 3], k = 2
// Output: 7
// Explanation: We can replace the last two elements of arr[] with the last two elements of change[]. The sum of the elements of arr[] will be 1 + 3 + 3 = 7, which is the minimum possible sum.
// Input: arr[] = [2], change[] = [0], k = 1
// Output: 0
// Explanation: We can replace the only element of arr[] with the only element of change[]. The sum of the elements of arr[] will be 0, which is the minimum possible sum.
// Constraints:
// (Note: While the constraints aren't visible in the image, they likely include restrictions on array sizes, element values, and k being less than or equal to array length)
// The problem has an accuracy rate of 39.04%, has received 41+ submissions, and is worth 20 points.

long long minimumSum(vector<int>& arr, vector<int>& change, int k) {
        // code here
        long long totS=accumulate(arr.begin(),arr.end(),0LL);
        vector<pair<int,int>>diff;
        for(int i=0;i<arr.size();i++){
            diff.push_back({change[i]-arr[i],i});
        }
        sort(diff.begin(),diff.end());
        for(int i=0;i<k;i++){
            int idx=diff[i].second;
            totS+=(change[idx]-arr[idx]);
        }
        return totS;
    }