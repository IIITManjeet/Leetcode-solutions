class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] != 'X')
            return;
        
        vis[i][j] = true;
        
        dfs(i + 1, j, board, vis, n, m); // Move down
        dfs(i, j + 1, board, vis, n, m); // Move right
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        int n = board.size();
        if (n == 0) return 0; // Edge case handling for empty board
        int m = board[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'X') {
                    dfs(i, j, board, vis, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
