class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> arr;

        // Add elements less than pivot
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < pivot) {
                arr.push_back(nums[i]);
            }
        }

        // Add elements equal to pivot
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == pivot) {
                arr.push_back(nums[i]);
            }
        }

        // Add elements greater than pivot
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > pivot) {
                arr.push_back(nums[i]);
            }
        }

        return arr;
    }
};