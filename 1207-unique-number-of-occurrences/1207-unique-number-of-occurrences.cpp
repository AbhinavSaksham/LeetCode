class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;

        // Count frequency
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        unordered_set<int> st;

        // Check if frequencies are unique
        for (auto it : freq) {

            if (st.count(it.second)) {
                return false;
            }

            st.insert(it.second);
        }

        return true;
    }
};