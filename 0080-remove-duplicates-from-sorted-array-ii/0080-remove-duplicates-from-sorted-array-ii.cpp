class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() <= 2) {
            return nums.size(); //base case
        }

        int i = 1;
        int count = 1;

        for (int j = 1; j < nums.size(); j++) { //traverse array with j keeping i for unique elem.

            if (nums[j] == nums[j - 1]) {
                count++;
            }
            else {
                count = 1;
            }

            if (count <= 2) { //count condition
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};