class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        // Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }

        // Store {frequency, element}
        vector<pair<int, int>> vec;

        for (auto it : freq) {
            vec.push_back({it.second, it.first});
        }

        // Sort in descending order of frequency
        sort(vec.rbegin(), vec.rend());

        vector<int> ans;

        // Take first k elements
        for (int i = 0; i < k; i++) {
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};