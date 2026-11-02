class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end()); // Sort the array

        int n = nums.size(); // Find the median
        int median = nums[n / 2];

        int ans = 0;

        // Calculate total moves required
        for(int i = 0; i < n; i++) {
            ans += abs(nums[i] - median);
        }

        return ans;
    }
};