class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int m) {
        if (i < 0 || j < 0 || j >= m) return INT_MAX;
        if (dp[i][j] != INT_MAX) return dp[i][j];
        if (i == 0) return grid[0][j];
        
        int temp = INT_MAX;
        for (int k = 0; k < m; k++) {
            if (k != j) {
                temp = min(temp, f(i - 1, k, grid, dp, n, m));
            }
        }
        return dp[i][j] = temp + grid[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, f(n - 1, j, grid, dp, n, m));
        }
        return ans;
    }
};
