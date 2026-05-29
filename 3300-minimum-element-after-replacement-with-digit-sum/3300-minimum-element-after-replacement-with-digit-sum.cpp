class Solution {
public:

    int minElement(vector<int>& nums) {

        vector<int> arr;

        for(int i = 0; i < nums.size(); i++) {

            int sum = 0;

            string s = to_string(nums[i]);  //digits ka sum nikala string me convert karke

            for(char digit : s) {
                sum += digit - '0';
            }

            arr.push_back(sum); //arr me push kiya new sum 
        }

        sort(arr.begin(), arr.end()); //sort 

        return arr[0];
    }
};