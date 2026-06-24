class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int degree = 0;

            // Count connections of vertex i
            for (int j = 0; j < n; j++) {
                degree += matrix[i][j];
            }

            ans[i] = degree;
        }

        return ans;
    }
};