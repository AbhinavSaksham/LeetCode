class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int ans = 0;

        while (l < r) {

            // Left side is smaller, so calculate water using leftMax
            if (height[l] <= height[r]) {

                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    ans += leftMax - height[l];

                l++;
            }
            else {

                // Right side is smaller, so calculate water using rightMax
                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    ans += rightMax - height[r];

                r--;
            }
        }

        return ans;
    }
};