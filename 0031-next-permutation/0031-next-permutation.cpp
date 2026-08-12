class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int i = n - 2;// Find the first decreasing element from right

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If a valid pivot exists
        if (i >= 0) {

            // Find the element just greater than nums[i]
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            // Swap pivot with next greater element
            swap(nums[i], nums[j]);
        }

        // Reverse the remaining part
        reverse(nums.begin() + i + 1, nums.end());
    }
};