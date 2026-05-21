class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) { //nums.siz()-2 because we need 2 val afer i.
            if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicate values for i
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])// Skip duplicates for j
                        j++;

                    while (j < k && nums[k] == nums[k - 1])// Skip duplicates for k
                        k--;

                    j++;
                    k--;

                }
                else if (sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return ans;
    }
};



        // set<vector<int>> st;
        // for (int i= 0; i< nums.size(); i++)
        // {
        //     set<int> hashset;
        //     for (int j = i+1; j < nums.size(); j++){
        //         int third = -(nums[i] + nums[j]);
        //         if(hashset.find(third)!= hashset.end())
        //         {
        //             vector<int> temp = {nums[i], nums[j], third};
        //             sort(temp.begin(), temp.end());
        //             st.insert(temp);
        //         }

        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;
        