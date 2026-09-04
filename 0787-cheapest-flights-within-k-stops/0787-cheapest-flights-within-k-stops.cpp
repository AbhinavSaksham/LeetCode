class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dp(n, INT_MAX); // dp[i] = minimum cost to reach city i
        dp[src] = 0; // Source city costs 0

        // At most k stops means k + 1 flights
        for(int i = 0; i <= k; i++) {

            // Copy previous prices to avoid using extra flights
            vector<int> temp = dp;

            for(auto it : flights) {
                int from = it[0];
                int to = it[1];
                int price = it[2];

                // Relax the flight if the source is reachable
                if(dp[from] != INT_MAX) {
                    temp[to] = min(temp[to], dp[from] + price);
                }
            }

            dp = temp; // Update prices
        }

        if(dp[dst] == INT_MAX) // Return -1 if destination cannot be reached
            return -1;

        return dp[dst];
    }
};