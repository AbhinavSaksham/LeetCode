class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = colSum.size();
            int m = rowSum.size();
            vector<vector<int>> mtx(m, vector<int>(n, 0));
            
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (rowSum[i] == 0 || colSum[j] == 0) {
                    mtx[i][j] = 0;
                } else {
                    mtx[i][j] = min(rowSum[i], colSum[j]);
                    rowSum[i] -= mtx[i][j];
                    colSum[j] -= mtx[i][j];
                }
            }
        }
        return mtx;
    }
}; 