class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> arr; // to convert arr to str

        for(int i = 0; i < nums.size(); i++) {
            arr.push_back(to_string(nums[i])); 
        }

        // Put a before b if ab is greater than ba
        sort(arr.begin(), arr.end(), [](string a, string b) { 
            return a + b > b + a;
        });

        // base case check 
        if(arr[0] == "0")
            return "0";

        string ans = "";

        for(int i = 0; i < arr.size(); i++) { //return answer as str
            ans += arr[i];
        }

        return ans;
    }
};