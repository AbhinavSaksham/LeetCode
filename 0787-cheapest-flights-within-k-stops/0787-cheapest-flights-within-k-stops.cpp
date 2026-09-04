class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dp(n, INT_MAX); // dp[i] = cheapest price to reach city i
        dp[src] = 0; // Source city costs 0

        // At most k stops means at most k + 1 flights
        for(int i = 0; i <= k; i++) {

            // Use a copy so that one iteration uses only
            // routes with the previous number of flights
            vector<int> temp = dp;

            for(auto flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                // Relax the flight if the source city is reachable
                if(dp[from] != INT_MAX) {
                    temp[to] = min(temp[to], dp[from] + price);
                }
            }

            dp = temp; // Update prices for the next flight
        }

        // Return -1 if destination is unreachable
        return dp[dst] == INT_MAX ? -1 : dp[dst];
    }
};