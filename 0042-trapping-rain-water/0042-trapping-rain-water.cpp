class Solution {
public:
    int trap(vector<int>& height) {

        // Two pointers: one from left and one from right
        int l = 0;
        int r = height.size() - 1;

        // Maximum height seen from left and right
        int leftMax = 0;
        int rightMax = 0;

        int ans = 0;

        while (l <= r) {

            // Process the side with smaller height
            if (height[l] <= height[r]) {

                // Update left maximum
                if (height[l] >= leftMax) {
                    leftMax = height[l];
                }
                else {
                    // Water trapped = leftMax - current height
                    ans += leftMax - height[l];
                }

                l++;
            }
            else {

                // Update right maximum
                if (height[r] >= rightMax) {
                    rightMax = height[r];
                }
                else {
                    // Water trapped = rightMax - current height
                    ans += rightMax - height[r];
                }

                r--;
            }
        }

        return ans;
    }
};