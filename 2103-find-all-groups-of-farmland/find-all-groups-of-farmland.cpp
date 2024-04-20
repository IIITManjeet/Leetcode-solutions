class Solution {
public:
    vector<int> row = {1, 0, -1, 0};
    vector<int> col = {0, 1, 0, -1};
    int n = 0, m = 0;

    void dfs(int i, int j, int& row2, int& col2, vector<vector<bool>>& vis, vector<vector<int>>& land) {
        vis[i][j] = true;
        row2 = max(row2, i);
        col2 = max(col2, j);
        for (int k = 0; k < 4; k++) {
            int newX = i + row[k];
            int newY = j + col[k];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] && land[newX][newY] == 1) {
                dfs(newX, newY, row2, col2, vis, land);
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && land[i][j] == 1) {
                    int row2 = i, col2 = j;
                    dfs(i, j, row2, col2, vis, land);
                    ans.push_back({i, j, row2, col2});
                }
            }
        }
        return ans;
    }
};
