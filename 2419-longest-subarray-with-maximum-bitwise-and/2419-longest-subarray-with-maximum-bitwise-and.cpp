class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = 0, count = 0, maxCount = 0;

        // Find the maximum element in the array
        for (int num : nums) {
            maxElement = std::max(maxElement, num);
        }

        // Find the longest subarray where all elements are equal to maxElement
        for (int num : nums) {
            if (num == maxElement) {
                count++;
            } else {
                maxCount = std::max(maxCount, count);
                count = 0;
            }
        }

        // Compare one last time to ensure no sequence is missed at the end
        maxCount = std::max(maxCount, count);

        return maxCount;
    }
};
