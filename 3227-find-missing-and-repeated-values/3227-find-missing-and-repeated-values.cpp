class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size() * grid[0].size(); // Total number of elements
        vector<int> flattened;

        // Flatten the 2D grid into a 1D vector
        for (const auto& row : grid) {
            flattened.insert(flattened.end(), row.begin(), row.end());
        }

        vector<int> freq(
            n + 1, 0); // Frequency array to count occurrences of each number
        for (int num : flattened) {
            freq[num]++;
        }

        int missing = -1;
        int repeated = -1;

        // Find the repeated and missing numbers
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                repeated = i;
            } else if (freq[i] == 0) {
                missing = i;
            }
        }

        return {repeated, missing};
    }
};
