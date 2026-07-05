class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int sumMax = 0;
        int sumMin = 0;

        int maxi = 0;
        int mini = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Maximum subarray
            sumMax += nums[i];
            maxi = max(maxi, sumMax);

            if (sumMax < 0) {
                sumMax = 0;
            }

            // Minimum subarray
            sumMin += nums[i];
            mini = min(mini, sumMin);

            if (sumMin > 0) {
                sumMin = 0;
            }
        }

        return max(maxi, abs(mini));
    }
};