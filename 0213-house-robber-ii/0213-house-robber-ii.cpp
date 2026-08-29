class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        // Base case
        if(n == 1)
            return nums[0];
        
        int first = solve(nums, 0, n - 2); // Case 1: Exclude last house
        int second = solve(nums, 1, n - 1); // Case 2: Exclude first house

        return max(first, second);
    }

private:
    // Same DP logic, just applied to a range
    int solve(vector<int>& nums, int start, int end) {

        int n = end - start + 1;

        if(n == 1)
            return nums[start];

        vector<int> dp(n);

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        // Build DP array
        for(int i = 2; i < n; i++) {
            // Either skip current house
            // or rob current house
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }

        return dp[n - 1];
    }

};