class Solution {
public:
    int n, m, totalZeros = 0;
    pair<int, int> src, dest;

    int dfs(int sx, int sy, vector<vector<int>>& grid, int z) {
        if (sx < 0 || sy < 0 || sx >= n || sy >= m || grid[sx][sy] == -1) {
            return 0;
        }
        if (grid[sx][sy] == 2) return z == -1 ? 1 : 0;

        grid[sx][sy] = -1;
        z--;
        int totalpaths = dfs(sx - 1, sy, grid, z) + dfs(sx, sy - 1, grid, z) + dfs(sx + 1, sy, grid, z) + dfs(sx, sy + 1, grid, z);
        grid[sx][sy] = 0;
        z++;
        return totalpaths;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int totalZeros = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) src = { i, j };
                else if (grid[i][j] == 2) dest = { i, j };
                else if (grid[i][j] == 0) totalZeros++;
            }
        }
        return dfs(src.first, src.second, grid, totalZeros);
    }
};
