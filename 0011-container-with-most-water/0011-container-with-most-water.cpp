class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;

        int ans = 0;

        while (start < end){


            int width = end - start;
            int Area = width * min(height[start], height[end]);
            ans = max(ans, Area);

            if (height[start]< height[end]){
            start ++;
            }
            else 
            {
            end--;
            }
        }
        return ans;
    }
};