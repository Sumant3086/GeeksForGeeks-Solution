// Coin Change (Count Ways)
// Difficulty: MediumAccuracy: 43.1%Submissions: 282K+Points: 4
// Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
// Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
// Answers are guaranteed to fit into a 32-bit integer. 

// Examples:

// Input: coins[] = [1, 2, 3], sum = 4
// Output: 4
// Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].
// Input: coins[] = [2, 5, 3, 6], sum = 10
// Output: 5
// Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].
// Input: coins[] = [5, 10], sum = 3
// Output: 0
// Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.
// Constraints:
// 1 <= sum <= 103
// 1 <= coins[i] <= 104
// 1 <= coins.size() <= 103

// Company Tags
// PaytmFlipkartMorgan StanleyAccoliteAmazonMicrosoftOYO RoomsSamsungSnapdealZoho
// Topic Tags
// Related Interview Experiences
// Related Articles
// Expected Complexities
// If you are facing any issue on this page. Please let us know.
// Double offers ending soon- Get extra 30% off + 90% fee refund on GeeksforGeeks courses  

// banner

int count(vector<int>& coins, int sum) {
    // code here.
    vector<int>dp(sum+1,0);
    dp[0]=1;
    for(int coin:coins){
        for(int j=coin;j<=sum;j++){
            dp[j]+=dp[j-coin];
        }
    }
    return dp[sum];
}