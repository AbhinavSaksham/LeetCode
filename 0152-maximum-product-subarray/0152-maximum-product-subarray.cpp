class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi = nums[0];
        int maxProduct = nums[0];
        int minProduct = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Negative number changes max to min and vice versa
            if (nums[i] < 0) {
                swap(maxProduct, minProduct);
            }

            // Maximum product till current index
            maxProduct = max(nums[i], maxProduct * nums[i]);

            // Minimum product till current index
            minProduct = min(nums[i], minProduct * nums[i]);

            // Update answer
            maxi = max(maxi, maxProduct);
        }

        return maxi;
    }
};