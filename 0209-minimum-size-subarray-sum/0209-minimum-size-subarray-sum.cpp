class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int left = 0;
        int sum = 0;

        int ans = INT_MAX;

        // Expand the window
        for(int right = 0; right < n; right++) {

            sum += nums[right];

            // Shrink the window while sum >= target
            while(sum >= target) {

                ans = min(ans, right - left + 1);

                sum -= nums[left];
                left++;
            }
        }

        if(ans == INT_MAX) { // No valid subarray found
            return 0;
        }
        return ans;
    }
};