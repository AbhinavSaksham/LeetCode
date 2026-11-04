class Solution {
public:

    // Balance the two halves and keep the median in low
    void balance(multiset<int>& low, multiset<int>& high, long long& sumLow, long long& sumHigh) {

        int total = low.size() + high.size();
        int target = (total + 1) / 2;

        while(low.size() > target) {
            int num = *low.rbegin();

            low.erase(prev(low.end()));
            high.insert(num);

            sumLow -= num;
            sumHigh += num;
        }

        while(low.size() < target) {
            int num = *high.begin();

            high.erase(high.begin());
            low.insert(num);

            sumHigh -= num;
            sumLow += num;
        }
    }

    // Insert an element into the sliding window
    void addNum(int num, multiset<int>& low, multiset<int>& high, long long& sumLow, long long& sumHigh) {

        if(low.empty() || num <= *low.rbegin()) {
            low.insert(num);
            sumLow += num;
        }
        else {
            high.insert(num);
            sumHigh += num;
        }

        balance(low, high, sumLow, sumHigh);
    }

    // Remove an element from the sliding window
    void removeNum(int num, multiset<int>& low, multiset<int>& high,
                   long long& sumLow, long long& sumHigh) {

        auto it = low.find(num);

        if(it != low.end()) {
            low.erase(it);
            sumLow -= num;
        }
        else {
            it = high.find(num);
            high.erase(it);
            sumHigh -= num;
        }

        balance(low, high, sumLow, sumHigh);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        // Store the cost of making each window equal
        vector<long long> cost(n - x + 1);

        // Calculate costs using sliding window + median
        for(int i = 0; i < n; i++) {

            addNum(nums[i], low, high, sumLow, sumHigh);

            // Remove the element outside the window
            if(i >= x) {
                removeNum(nums[i - x], low, high,
                          sumLow, sumHigh);
            }

            // Calculate cost when window size becomes x
            if(i >= x - 1) {

                long long median = *low.rbegin();

                cost[i - x + 1] =
                    median * low.size() - sumLow +
                    sumHigh - median * high.size();
            }
        }

        // DP: dp[i][j] = minimum cost using first i elements
        // to select exactly j non-overlapping subarrays
        const long long INF = LLONG_MAX / 2;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        // Zero subarrays require zero operations
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= k; j++) {

                // Option 1: Skip current element
                dp[i][j] = dp[i - 1][j];

                // Option 2: Take a window of size x
                if(i >= x && dp[i - x][j - 1] != INF) {

                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};