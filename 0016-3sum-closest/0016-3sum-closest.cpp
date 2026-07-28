class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Initialize with the first possible triplet
        int closest = nums[0] + nums[1] + nums[2];

        // Fix the first element
        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Update answer if current sum is closer
                if(abs(sum - target) < abs(closest - target))
                    closest = sum;

                // Perfect match
                if(sum == target)
                    return sum;

                // Need a larger sum
                if(sum < target)
                    left++;

                // Need a smaller sum
                else
                    right--;
            }
        }

        return closest;
    }
};