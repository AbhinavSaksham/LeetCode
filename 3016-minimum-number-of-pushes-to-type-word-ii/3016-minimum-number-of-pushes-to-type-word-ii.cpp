class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : word)
            freq[ch - 'a']++;

        // Sort frequencies in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;

            // Cost = 1 for first 8 letters, 2 for next 8, etc.
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};