class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int m = b.size(), n = b[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && b[i][j] == 'O') {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + dx[i];
                int ncol = c + dy[i];
                if (nrow < 0 || ncol < 0 || nrow >= m || ncol >= n) continue;
                if (vis[nrow][ncol] || b[nrow][ncol] == 'X') continue;
                
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && b[i][j] == 'O') b[i][j] = 'X';
            }
        }
    }
};
