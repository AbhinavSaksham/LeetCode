class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
        vector<int> dp(n + 1, INT_MAX);   // dp[i] = minimum cost to reach step i     
        dp[0] = 0; // Starting from step 0 costs nothing

        for(int i = 1; i <= n; i++) {

            // Try jumping from 1, 2 or 3 steps behind
            for(int j = 1; j <= 3; j++) {

                if(i - j >= 0) {

                    int jumpCost = costs[i - 1] + j * j;
                    dp[i] = min(dp[i], dp[i - j] + jumpCost);
                }
            }
        }
        return dp[n];
    }
};