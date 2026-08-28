class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        // Minimum cost to reach step 0 and 1
        int prev2 = cost[0];
        int prev1 = cost[1];

        // Calculate minimum cost for remaining steps
        for(int i = 2; i < cost.size(); i++) {

            int current = cost[i] + min(prev1, prev2);

            // Move pointers forward
            prev2 = prev1;
            prev1 = current;
        }

        // From last or second-last step, we can reach the top
        return min(prev1, prev2);
    }
};