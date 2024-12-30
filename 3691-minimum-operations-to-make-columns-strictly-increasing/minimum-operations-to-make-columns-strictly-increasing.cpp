class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int ans = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            for (int i = 0; i < grid.size() - 1; i++) {
                if (grid[i][j] >= grid[i + 1][j]) {
                    int diff = grid[i][j] - grid[i + 1][j] + 1;
                    grid[i + 1][j] += diff;
                    ans += diff;
                }
            }
        }
        return ans;
    }
};
