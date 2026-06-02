class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int i = 0; i < nums.size(); i++) {

            freq[nums[i]]++;
        }

        vector<pair<int, int>> vec;

        // Store {frequency, element}
        for (unordered_map<int, int>::iterator it = freq.begin();
             it != freq.end();
             it++) {

            vec.push_back({it->second, it->first});
        }

        // Sort by frequency
        sort(vec.rbegin(), vec.rend());

        vector<int> ans;

        // First k frequent elements
        for (int i = 0; i < k; i++) {

            ans.push_back(vec[i].second);
        }

        return ans;
    }
};