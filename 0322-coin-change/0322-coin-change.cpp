class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1); // dp[i] = minimum coins needed to make amount i
        dp[0] = 0; // base case - 0 cains for 0 amount

        for(int i = 1; i <= amount; i++) {

            // Try every coin
            for(int j = 0; j < coins.size(); j++) {

                // Use this coin if it is not greater than current amount
                if(coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        if(dp[amount] == amount + 1) // base case - Amount cannot be formed 
            return -1;

        return dp[amount];
    }
};