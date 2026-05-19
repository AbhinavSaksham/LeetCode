class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) { // main traversal of array

            int count = 0;

            for (int j = 0; j < nums.size(); j++) { //traverse for i-th index to check value 

                if (i != j && nums[j] < nums[i]) {
                    count++;
                }
            }

            ans.push_back(count); //vector to store the list 
        }

        return ans;
    }
};