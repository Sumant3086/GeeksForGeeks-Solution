// Minimize Max Distance to Gas Station
// Difficulty: HardAccuracy: 38.36%Submissions: 86K+Points: 8Average Time: 40m
// We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1], where n is the size of the stations array. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
// Note: stations is in a strictly increasing order.

// Example 1:

// Input:
// n = 10
// stations[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// k = 9
// Output: 0.50
// Explanation: Each of the 9 stations can be added mid way between all the existing adjacent stations.
// Example 2:

// Input:
// n = 10
// stations[] = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95] 
// k = 2 
// Output: 14.00 
// Explanation: Construction of gas stations at 8th(between 72 and 89) and 6th(between 44 and 67) locations.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findSmallestMaxDist() which takes a list of stations and integer k as inputs and returns the smallest possible value of d. Find the answer exactly to 2 decimal places.

// Constraint:
// 10 <= n <= 10000 
// 0 <= stations[i] <= 109 
// 0 <= k <= 105

// Expected Complexities
// Topic Tags
// Binary SearchMathematicalArraysData StructuresAlgorithms
// Related Articles
// Minimize The Maximum Distance Between Adjacent Points After Adding K Points Anywhere In Between
// If you are facing any issue on this page. Please let us know.
class Solution {
  public:
  bool isP(double mid,vector<int>& stations,int n,int k){
      int used=0;
      for(int i=0;i<n-1;i++){
          used+=(double)((stations[i+1]-stations[i])/mid);
      }
      return used<=k;
  }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double low=0.0;
        double high=1e8;
        int n=stations.size();
        while(high-low>1e-6){
            double mid=(low+high)/2.0;
            if(isP(mid,stations,n,k)){
                high=mid;
            }else{
                low=mid;
            }
        }
        return round(high*100.0)/100.0; 
    }
};